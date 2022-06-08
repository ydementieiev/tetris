#pragma once

#include "Figure.h"

class Hook_Right : public Figure
{
private:
    enum class position
    {
        original = 0,
        right_side = 1,
        down = 2,
        left_side = 3,
        undefine = 4
    };
public:
    Hook_Right();
    void rotate(bool rotate_back = false) override;
    void rotate_hook_to_right_side();
    void rotate_hook_to_left_side();
    void rotate_hook_to_down();
    void rotate_to_original_new();
private:
    position current_position_HR = position::original;
    position before_prev_position_HR = position::undefine;
};

