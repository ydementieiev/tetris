#include "Tetris.h"
#include <conio.h>
#include <iostream>
#include <time.h>
#include "Field.h"
#include "Figure.h"
#include "Stick.h"
#include "Square.h"
#include "HookRight.h"
#ifdef _WIN32 
#include <Windows.h>    
#endif

const int DELAY = 1000000;

Tetris::Tetris()
{
}

void Tetris::run()
{
    Figure *active_figure = get_random_figure();
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
                active_figure = get_random_figure();
            }
        }
    }
}

eActions Tetris::read_user_input()
{
    if (kbhit())
    {
        const auto ch = getch();
        switch (ch)
        {
        case 'a':
            return eActions::LEFT;
        case 'd':
            return eActions::RIGHT;
        case 'w':
            return eActions::UP;
        case 's':
            return eActions::DOWN;
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
            if (field_.is_possible_to_rotate(active_figure))
            {
                active_figure->rotate();
                update_figure_on_field(active_figure);
            }
            break;
        case eActions::DOWN:
                // finish sleep to speed up moving down
                return;
            break;
        default:
            break;
        }
    }
}

Figure * Tetris::get_random_figure()
{
    srand(time(0));
    int random_figure = 3;
    Figure *active_figure = nullptr;
    switch (random_figure)
    {
    case 1:
        active_figure = new Stick;
        break;
    case 2:
        active_figure = new Square;
        break;
    case 3:
        active_figure = new Hook_Right;
        break;
    default:
        break;
    }

    return active_figure;
}