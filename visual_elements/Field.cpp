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
    for (int row = 0; row < ROW; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (row == 0 || row == ROW - 1) {
                FIELD[row][column] = BORDER;
            }
            else if (column == 0 || column == COLUMNS - 1) {
                FIELD[row][column] = BORDER;
            } else {
                FIELD[row][column] = EMPTY;
            }
        }
    }
}

void Field::draw_new_figure_coord(coord figure_coord)
{
    for ( int i = 0; i < BLOCK_COUNT; i++) {
        if (figure_coord.row[i] > 0 && figure_coord.column[i] > 0) {
            FIELD[figure_coord.row[i]][figure_coord.column[i]] = BLOCK;
        }
    }
}

void Field::clear_old_figure_coord(coord figure_coord)
{
    for ( int i = 0; i < BLOCK_COUNT; i++) {
        if (figure_coord.row[i] > 0 && figure_coord.column[i] > 0) {
            FIELD[figure_coord.row[i]][figure_coord.column[i]] = EMPTY;
        }
    }
}

bool Field::is_suitable_to_move(coord figure_coord)
{
    for ( int i = 0; i < BLOCK_COUNT; i++) {
        if(is_border_bottom(figure_coord.row[i], figure_coord.column[i])) {
            return false;
        }
        if(is_figure(figure_coord)) {
            return false;
        }
      
    }

    return true;
}

bool Field::is_border_left_right(coord figure_coord)
{
    for ( int i = 0; i < BLOCK_COUNT; i++) {
        auto column = figure_coord.column[i];
        const bool is_border = column == 0 || column == COLUMNS - 1;
        if ( is_border) {
            return true;
        }
    }

    return false;
}

bool Field::is_border_bottom(int row, int column)
{
    const bool row_is_suitable = row < ROW - 1; // Do not check top row, figure need appear.

    return !row_is_suitable;
}

bool Field::is_figure(coord figure_coord)
{
    for ( int i = 0; i < BLOCK_COUNT; i++) {
        bool is_block = FIELD[figure_coord.row[i]][figure_coord.column[i]] == BLOCK;
        if(is_block) {
            int current_row = figure_coord.row[i];
            int current_column = figure_coord.column[i];
            bool same_fugire = false;

            for ( int j = 0; j < BLOCK_COUNT; j++) {
                if (j == i) {
                    continue;
                }
                bool same_row = current_row + 1 == figure_coord.row[j];
                bool same_column = current_column == figure_coord.column[j];
                if(same_row && same_column) {
                    same_fugire = true;
                    break;
                }
                
            }
            if (!same_fugire) {
                return true;
            }
        }
    }
    return false;
}

void Field::draw_field()
{
    for (int row = 0; row < ROW; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            std::cout << FIELD[row][column];
        }
        std::cout << std::endl;
    }
}