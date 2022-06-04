#include "Tetris.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "Field.h"
#include "Figure.h"
#include "Stick.h"

const int DELAY = 500;

Tetris::Tetris()
{
}

void Tetris::run()
{
    Figure *active_figure = new Stick;

    while (true)
    {
        if (field_.is_possible_to_move_down(active_figure))
        {
            active_figure->move_down();
            update_figure_on_field(active_figure);
            sleep_and_proccess_user_action(active_figure);
        }
        else
        {
            if (active_figure)
            {
                delete active_figure;
                active_figure = new Stick;
            }
        }
    }
}

eActions Tetris::read_user_input()
{
    if (_kbhit())
    {
        const auto ch = _getch();
        switch (ch)
        {
        case 'a':
            return eActions::LEFT;
        case 'd':
            return eActions::RIGHT;
        case 'w':
            return eActions::UP;
        case '0':
            // Use '0' for exit from game.
            exit(0);
        default:
            // Not supported key.
            break;
        }
    }

    return eActions::NO_ACTION;
}

void Tetris::update_figure_on_field(Figure *figure)
{
    field_.clear_old_figure_coord(figure);
    field_.update_new_figure_coord(figure);
    field_.draw_field();
}

void Tetris::sleep_and_proccess_user_action(Figure *active_figure)
{
    clock_t end_time = clock() + DELAY;

    while (clock() < end_time)
    {
        const auto user_input = read_user_input();
        switch (user_input)
        {
        case eActions::LEFT:
            if (field_.is_possible_to_move_left(active_figure))
            {
                active_figure->move_left();
                update_figure_on_field(active_figure);
            }
            break;
        case eActions::RIGHT:
            if (field_.is_possible_to_move_right(active_figure))
            {
                active_figure->move_right();
                update_figure_on_field(active_figure);
            }
            break;
        case eActions::UP:
            active_figure->rotate();
            update_figure_on_field(active_figure);
            break;
        default:
            break;
        }
    }
}
