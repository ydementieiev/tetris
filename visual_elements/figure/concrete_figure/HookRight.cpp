#include "HookRight.h"

Hook_Right::Hook_Right()
{
    // -2 12 main BLOCK
    figure_coord.row[0] = -2;
    figure_coord.column[0] = 13;

    figure_coord.row[1] = -2;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = -1;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 12;
}
void Hook_Right::rotate()
{
    save_old_coord();

    switch (current_position_HR)
    {
    case position::original:
        rotate_hook_to_right_side();
        // current_position_HR = position::right_side;
        break;
    case position::right_side:
        rotate_hook_to_down();
        // current_position_HR = position::down;
        break;
    case position::down:
        rotate_hook_to_left_side();
        // current_position_HR = position::left_side;
        break;
    case position::left_side:
        rotate_to_original_new();
        // current_position_HR = position::original;
        break;
    default:
        break;
    }
}


void Hook_Right::rotate_hook_to_right_side()
{
    figure_coord.row[0] = figure_coord.row[0];
    figure_coord.column[0] = figure_coord.column[0] - 2;

    figure_coord.row[1] = figure_coord.row[1];//
    figure_coord.column[1] = figure_coord.column[1]; //

    figure_coord.row[2] = figure_coord.row[2];//
    figure_coord.column[2] = figure_coord.column[2];//

    figure_coord.row[3] = figure_coord.row[3] - 2;
    figure_coord.column[3] = figure_coord.column[3] - 2;
}

void Hook_Right::rotate_hook_to_down()
{
    figure_coord.row[0] = figure_coord.row[0]; //
    figure_coord.column[0] = figure_coord.column[0]; //

    figure_coord.row[1] = figure_coord.row[1]; //
    figure_coord.column[1] = figure_coord.column[1]; //

    figure_coord.row[2] = figure_coord.row[2] - 2;
    figure_coord.column[2] = figure_coord.column[2];

    figure_coord.row[3] = figure_coord.row[3] - 2;
    figure_coord.column[3] = figure_coord.column[3] + 1;
}

void Hook_Right::rotate_hook_to_left_side()
{
    figure_coord.row[0] = figure_coord.row[0];
    figure_coord.column[0] = figure_coord.column[0] + 2;

    figure_coord.row[1] = figure_coord.row[1]; //
    figure_coord.column[1] = figure_coord.column[1]; //

    figure_coord.row[2] = figure_coord.row[2]; // 
    figure_coord.column[2] = figure_coord.column[2]; //

    figure_coord.row[3] = figure_coord.row[3] + 2;
    figure_coord.column[3] = figure_coord.column[3] + 2;
}

void Hook_Right::rotate_to_original_new()
{
    figure_coord.row[0] = figure_coord.row[0]; //
    figure_coord.column[0] = figure_coord.column[0];//

    figure_coord.row[1] = figure_coord.row[1];  //
    figure_coord.column[1] = figure_coord.column[1];  //

    figure_coord.row[2] = figure_coord.row[2] + 2; 
    figure_coord.column[2] = figure_coord.column[2]; 

    figure_coord.row[3] = figure_coord.row[3] + 2;
    figure_coord.column[3] = figure_coord.column[3] - 2;
}