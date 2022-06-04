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
    active_figure_ = new Stick;

    while (true)
    {
        field_.draw_field();
        sleep_or_proccess_user_action();

        // auto new_figure_coord =  active_figure_->get_figure_coord();
        // bool need_to_clear = true;

        // if( field_.is_border_left_right(new_figure_coord)) {
        // active_figure_->return_to_old_coord();
        // need_to_clear = false;
        // }

        if (field_.is_possible_to_move_down(active_figure_->get_figure_coord())) {
            active_figure_->move_down();
            field_.clear_old_figure_coord(active_figure_->get_figure_coord_old());
            field_.update_new_figure_coord(active_figure_->get_figure_coord());
        } else {
            if ( active_figure_ ) {
                delete active_figure_;
                active_figure_ = new Stick;
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

void Tetris::sleep_or_proccess_user_action()
{
    clock_t end_time = clock() + DELAY;

    while (clock() < end_time)
    {
        const auto user_input = read_user_input();
        switch (user_input)
        {
        case eActions::LEFT:
            if(field_.is_possible_to_move_left(active_figure_->get_figure_coord())) {
                active_figure_->move_left();
                field_.clear_old_figure_coord(active_figure_->get_figure_coord_old());
                field_.update_new_figure_coord(active_figure_->get_figure_coord());
                field_.draw_field();
            }
            break;
        case eActions::RIGHT:
            if(field_.is_possible_to_move_right(active_figure_->get_figure_coord())) {
                active_figure_->move_right();
                field_.clear_old_figure_coord(active_figure_->get_figure_coord_old());
                field_.update_new_figure_coord(active_figure_->get_figure_coord());
                field_.draw_field();
            }
            break;
        case eActions::UP:
            active_figure_->rotate();
            field_.clear_old_figure_coord(active_figure_->get_figure_coord_old());
            field_.update_new_figure_coord(active_figure_->get_figure_coord());
            field_.draw_field();
            break;
        default:
            break;
        }
    }
}
