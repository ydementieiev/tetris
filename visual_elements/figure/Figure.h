#pragma once

const int BLOCK_COUNT = 4;

struct coord
{
    int row[BLOCK_COUNT] = {-1, -1, -1, -1};
    int column[BLOCK_COUNT] = {-1, -1, -1, -1};
};

class Figure
{
public:
    virtual void rotate() = 0;

    coord get_figure_coord();
    coord get_figure_coord_old();

    void move_down();
    void move_left();
    void move_right();
    void return_to_old_coord();

    void save_old_coord();

protected:
    coord figure_coord;
    coord figure_coord_old;
};