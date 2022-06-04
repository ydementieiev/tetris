#pragma once

#include "Figure.h"

const int ROWS = 20;
const int COLUMNS = 25;

class Field
{
public:
    Field();
    void draw_field();
    void update_new_figure_coord(const coord &figure_coord);
    void clear_old_figure_coord(const coord &figure_coord);

    bool is_possible_to_move_down(const coord &figure_coord);
    bool is_possible_to_move_left(const coord &figure_coord);
    bool is_possible_to_move_right(const coord &figure_coord);

private:
    bool is_border_from_bottom(const coord &figure_coord);
    bool is_border_on_left_side(const coord &figure_coord);
    bool is_border_on_right_side(const coord &figure_coord);

    bool is_other_figure_from_bottom(const coord &figure_coord);

    bool is_figure(coord figure_coord);
    void fill_field_by_default();

private:
    char FIELD[ROWS][COLUMNS];
};