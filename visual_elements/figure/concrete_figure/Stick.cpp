#include "Stick.h"

Stick::Stick()
{
    figure_coord.row[0] = -3;
    figure_coord.column[0] = 12;

    figure_coord.row[1] = -2;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = -1;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 12;
}

void Stick::rotate()
{
    save_old_coord();
    switch (current_position_)
    {
    case position::vertical:
        rotate_stick_to_horizontal();
        current_position_ = position::horizontal;
        break;
    case position::horizontal:
        rotate_stick_to_vertical();
        current_position_ = position::vertical;
        break;
    default:
        break;
    }
}

void Stick::rotate_stick_to_horizontal()
{
    figure_coord.row[0] = figure_coord.row[2];
    figure_coord.column[0] = figure_coord.column[2] - 2;

    figure_coord.row[1] = figure_coord.row[2];
    figure_coord.column[1] = figure_coord.column[2] - 1;

    figure_coord.row[2] = figure_coord.row[2];
    figure_coord.column[2] = figure_coord.column[2];

    figure_coord.row[3] = figure_coord.row[2];
    figure_coord.column[3] = figure_coord.column[2] + 1;
}

void Stick::rotate_stick_to_vertical()
{
    figure_coord.row[0] = figure_coord.row[2] - 2;
    figure_coord.column[0] = figure_coord.column[2];

    figure_coord.row[1] = figure_coord.row[2] - 1;
    figure_coord.column[1] = figure_coord.column[2];

    figure_coord.row[2] = figure_coord.row[2];
    figure_coord.column[2] = figure_coord.column[2];

    figure_coord.row[3] = figure_coord.row[2] + 1;
    figure_coord.column[3] = figure_coord.column[2];
}