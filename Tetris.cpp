#include "Tetris.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "Field.h"
#include "Figure.h"
#include "Stick.h"

const int DELAY = 1000;

Tetris::Tetris()
{

}

void Tetris::run()
{
    Field field;
    Figure *figure;

    figure = new Stick;

    while (true)
    {
        system("clear");
        field.draw_field();
        auto user_input = sleep_or_proccess_user_action();
        if ( user_input == eActions::LEFT) {
            figure->move_left();
        } else if (user_input == eActions::RIGHT) {
            figure->move_right();
        }

        auto new_figure_coord =  figure->get_figure_coord();
        bool need_to_clear = true;

        if( field.is_border_left_right(new_figure_coord)) {
            figure->return_to_old_coord();
            need_to_clear = false;
        }

        if (field.is_suitable_to_move(new_figure_coord)) {
            if ( need_to_clear) {
                field.clear_old_figure_coord(figure->get_figure_coord_old());
            }
            field.draw_new_figure_coord(new_figure_coord);
            figure->move_down();
        } else {
            delete figure;
            figure = new Stick;
        }
    }
}

eActions Tetris::read_user_input()
{
    if ( _kbhit() ) {
        auto ch = _getch();
        if (ch == 'a') {
            return eActions::LEFT;
        } else if (ch == 'd') {
            return eActions::RIGHT;
        }
         else if (ch == '0') {
            std::cout << "Press 0 to exit, or any other to continue" << std::endl;
            exit(0);
        }
    }

    return eActions::NO_ACTION;
}

eActions Tetris::sleep_or_proccess_user_action()
{
    clock_t end_time = clock() + DELAY;
    while (clock() < end_time) {
        auto user_input = read_user_input();
        if ( user_input != eActions::NO_ACTION ) {
            return user_input;
        }
    }

    return eActions::NO_ACTION;
}
