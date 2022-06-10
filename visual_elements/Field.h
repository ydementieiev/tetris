#pragma once

#include "Figure.h"

const int ROWS = 20;
const int COLUMNS = 25;

class Field
{
public:
    Field();
    void draw_field();
    void update_new_figure_coord(const Figure *figure);
    void clear_old_figure_coord(const Figure *figure);

    bool is_possible_to_move_down(const Figure *figure);
    bool is_possible_to_move_left(const Figure *figure);
    bool is_possible_to_move_right(const Figure *figure);
    bool is_possible_to_rotate(Figure *figure);

    void move_all_block_on_field();
    void clear_one_line(int x);
    void move_field_down_after_clear(int x);
private:
    bool is_possible_to_rotate_on_figure(Figure *figure);
    bool is_possible_to_rotate_on_border(Figure *figure);

    bool is_border_from_bottom(const Figure *figure);
    bool is_border_on_left_side(const Figure *figure);
    bool is_border_on_right_side(const Figure *figure);

    bool is_other_figure_from_bottom(const Figure *figure);
    bool is_other_figure_on_left_side(const Figure *figure);
    bool is_other_figure_on_right_side(const Figure *figure);

    void fill_field_by_default();

private:
    char FIELD[ROWS][COLUMNS];
};