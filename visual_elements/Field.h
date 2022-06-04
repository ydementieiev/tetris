#pragma once

#include "Figure.h"

const int ROW = 20;
const int COLUMNS = 25;

class Field
{
public:
    Field();
    void draw_field();
    void update_new_figure_coord(coord figure_coord);
    void clear_old_figure_coord(coord figure_coord);
    bool is_suitable_to_move(coord figure_coord);

    bool is_border_left_right(coord figure_coord);

private:
    bool is_border_bottom(int row, int column);

    bool is_figure(coord figure_coord);
    void fill_field_by_default();

private:
    char FIELD[ROW][COLUMNS];
};