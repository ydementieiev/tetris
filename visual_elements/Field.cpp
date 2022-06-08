#include "Field.h"
#include <iostream>
#ifdef _WIN32 
#include <Windows.h>    
#endif

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

void Field::update_new_figure_coord(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        if (figure_coord.row[i] > 0 && figure_coord.column[i] > 0)
        {
            FIELD[figure_coord.row[i]][figure_coord.column[i]] = BLOCK;
        }
    }
}

void Field::clear_old_figure_coord(const Figure *figure)
{
    const auto figure_coord_old = figure->get_figure_coord_old();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        if (figure_coord_old.row[i] > 0 && figure_coord_old.column[i] > 0)
        {
            FIELD[figure_coord_old.row[i]][figure_coord_old.column[i]] = EMPTY;
        }
    }
}

bool Field::is_possible_to_move_down(const Figure *figure)
{
    if (is_border_from_bottom(figure))
    {
        return false;
    }

    if (is_other_figure_from_bottom(figure))
    {
        return false;
    }

    return true;
}

bool Field::is_possible_to_move_left(const Figure *figure)
{
    if (is_border_on_left_side(figure))
    {
        return false;
    }

    if (is_other_figure_on_left_side(figure))
    {
        return false;
    }

    return true;
}

bool Field::is_possible_to_move_right(const Figure *figure)
{
    if (is_border_on_right_side(figure))
    {
        return false;
    }

    if (is_other_figure_on_right_side(figure))
    {
        return false;
    }

    return true;
}

bool Field::is_possible_to_rotate(Figure *figure)
{
    if (is_possible_to_rotate_on_figure(figure))
    {
        return false;
    }
    if (is_possible_to_rotate_on_border(figure))
    {
        return false;
    }
    
    return true;
    
}

bool Field::is_border_from_bottom(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

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

bool Field::is_border_on_left_side(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

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

bool Field::is_border_on_right_side(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

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

bool Field::is_other_figure_from_bottom(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

    for (int active_block_index = 0; active_block_index < BLOCK_COUNT; active_block_index++)
    {
        // Check that below current block not another block.
        const int next_row_to_active_block = figure_coord.row[active_block_index] + 1;
        const int column_active_block = figure_coord.column[active_block_index];
        const bool is_other_block_below = FIELD[next_row_to_active_block][column_active_block] == BLOCK;

        if (is_other_block_below)
        {
            // Check that block below not from current figure.
            const auto block_from_same_figure = figure->is_block_from_same_figure(next_row_to_active_block, column_active_block);

            if (!block_from_same_figure)
            {
                // At least one block from current figure bump into another block.
                return true;
            }
        }
    }

    return false;
}

bool Field::is_other_figure_on_left_side(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

    for (int active_block_index = 0; active_block_index < BLOCK_COUNT; active_block_index++)
    {
        // Check that below current block not another block.
        const int row_active_block = figure_coord.row[active_block_index];
        const int left_column_to_active_block = figure_coord.column[active_block_index] - 1;
        const bool is_other_block_below = FIELD[row_active_block][left_column_to_active_block] == BLOCK;

        if (is_other_block_below)
        {
            // Check that block below not from current figure.
            const auto block_from_same_figure = figure->is_block_from_same_figure(row_active_block, left_column_to_active_block);

            if (!block_from_same_figure)
            {
                // At least one block from current figure bump into another block.
                return true;
            }
        }
    }

    return false;
}

bool Field::is_other_figure_on_right_side(const Figure *figure)
{
    const auto figure_coord = figure->get_figure_coord();

    for (int active_block_index = 0; active_block_index < BLOCK_COUNT; active_block_index++)
    {
        // Check that below current block not another block.
        const int row_active_block = figure_coord.row[active_block_index];
        const int right_column_to_active_block = figure_coord.column[active_block_index] + 1;
        const bool is_other_block_below = FIELD[row_active_block][right_column_to_active_block] == BLOCK;

        if (is_other_block_below)
        {
            // Check that block below not from current figure.
            const auto block_from_same_figure = figure->is_block_from_same_figure(row_active_block, right_column_to_active_block);

            if (!block_from_same_figure)
            {
                // At least one block from current figure bump into another block.
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


bool Field::is_possible_to_rotate_on_figure(Figure *figure)
{
    bool result = false;
    figure->rotate();
    auto active_coord = figure->get_figure_coord();
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        bool is_wrong = FIELD[active_coord.row[i]][active_coord.column[i]] == BLOCK;
        if (is_wrong)
        {
            auto active_cord_old = figure->get_figure_coord_old();
            if (active_cord_old.row[i] == active_coord.row[i] && active_cord_old.column[i] == active_coord.column[i])
            {
                continue;
            }
            result = true;
            break;
        }
    }
    figure->rotate(true);
    return result;
}

bool Field::is_possible_to_rotate_on_border(Figure *figure)
{
    bool result = false;
    figure->rotate();
    auto active_coord = figure->get_figure_coord();
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        bool is_wrong = FIELD[active_coord.row[i]][active_coord.column[i]] == BORDER;
        if (is_wrong)
        {
            result = true;
            break;
        }
    }
    figure->rotate(true);
    return result;
}