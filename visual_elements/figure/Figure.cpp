#include "Figure.h"

coord Figure::get_figure_coord()
{
    return figure_coord;
}

coord Figure::get_figure_coord_old()
{
    return figure_coord_old;
}

void Figure::move_down()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.row[i]++;
    }
}

void Figure::move_left()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.column[i]--;
    }
}

void Figure::move_right()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.column[i]++;
    }
}

void Figure::return_to_old_coord()
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.row[i] = figure_coord_old.row[i];
        figure_coord.column[i] = figure_coord_old.column[i];
    }
}

void Figure::save_old_coord()
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord_old.row[i] = figure_coord.row[i];
        figure_coord_old.column[i] = figure_coord.column[i];
    }
}
