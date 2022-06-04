#include "Field.h"
#include <iostream>
#include <Windows.h>

const char BORDER = 'X';
const char EMPTY = '.';
const char BLOCK = '0';

Field::Field()
{
    fill_field_by_default();
}

void Field::fill_field_by_default()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            if (row == 0 || row == ROWS - 1)
            {
                FIELD[row][column] = BORDER;
            }
            else if (column == 0 || column == COLUMNS - 1)
            {
                FIELD[row][column] = BORDER;
            }
            else
            {
                FIELD[row][column] = EMPTY;
            }
        }
    }
}

void Field::update_new_figure_coord(const coord &figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        if (figure_coord.row[i] > 0 && figure_coord.column[i] > 0)
        {
            FIELD[figure_coord.row[i]][figure_coord.column[i]] = BLOCK;
        }
    }
}

void Field::clear_old_figure_coord(const coord &figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        if (figure_coord.row[i] > 0 && figure_coord.column[i] > 0)
        {
            FIELD[figure_coord.row[i]][figure_coord.column[i]] = EMPTY;
        }
    }
}

bool Field::is_possible_to_move_down(const coord &figure_coord)
{
    if (is_border_from_bottom(figure_coord))
    {
        return false;
    }

    if (is_other_figure_from_bottom(figure_coord))
    {
        return false;
    }

    return true;
}

bool Field::is_possible_to_move_left(const coord &figure_coord)
{
    if (is_border_on_left_side(figure_coord))
    {
        return false;
    }

    return true;
}

bool Field::is_possible_to_move_right(const coord &figure_coord)
{
    if (is_border_on_right_side(figure_coord))
    {
        return false;
    }

    return true;
}

bool Field::is_border_from_bottom(const coord &figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        const int next_row = figure_coord.row[i] + 1;
        const bool is_border = next_row == ROWS - 1;
        if (is_border)
        {
            return true;
        }
    }

    return false;
}

bool Field::is_border_on_left_side(const coord &figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        const int prev_column = figure_coord.column[i] - 1;
        const bool is_border = prev_column == 0;
        if (is_border)
        {
            return true;
        }
    }

    return false;
}

bool Field::is_border_on_right_side(const coord &figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        const int next_column = figure_coord.column[i] + 1;
        const bool is_border = next_column == COLUMNS - 1;
        if (is_border)
        {
            return true;
        }
    }

    return false;
}

bool Field::is_other_figure_from_bottom(const coord &figure_coord)
{
    for (int active_block_index = 0; active_block_index < BLOCK_COUNT; active_block_index++)
    {
        // Check that below current block not another block.
        const int next_row_to_active_block = figure_coord.row[active_block_index] + 1;
        const int column_active_block = figure_coord.column[active_block_index];
        const bool is_other_block_below = FIELD[next_row_to_active_block][column_active_block] == BLOCK;

        bool same_fugire_below = false;

        if (is_other_block_below)
        {
            // Check that block below not from current figure.
            for (int other_block_index = 0; other_block_index < BLOCK_COUNT; other_block_index++)
            {
                if (other_block_index == active_block_index)
                {
                    // Skip comparing the same block.
                    continue;
                }
                const int other_block_row = figure_coord.row[other_block_index];
                const int other_block_column = figure_coord.column[other_block_index];

                const bool same_row = next_row_to_active_block == other_block_row;
                const bool same_column = column_active_block == other_block_column;
                if (same_row && same_column)
                {
                    same_fugire_below = true;
                    break;
                }
            }

            if (!same_fugire_below)
            {
                return true;
            }
        }
    }

    return false;
}

bool Field::is_figure(coord figure_coord)
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        bool is_block = FIELD[figure_coord.row[i]][figure_coord.column[i]] == BLOCK;
        if (is_block)
        {
            int current_row = figure_coord.row[i];
            int current_column = figure_coord.column[i];
            bool same_fugire = false;

            for (int j = 0; j < BLOCK_COUNT; j++)
            {
                if (j == i)
                {
                    continue;
                }
                bool same_row = current_row + 1 == figure_coord.row[j];
                bool same_column = current_column == figure_coord.column[j];
                if (same_row && same_column)
                {
                    same_fugire = true;
                    break;
                }
            }
            if (!same_fugire)
            {
                return true;
            }
        }
    }
    return false;
}

void Field::draw_field()
{
    system("clear");

    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            std::cout << FIELD[row][column];
        }
        std::cout << std::endl;
    }
}