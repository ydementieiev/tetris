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
        left_side = 3
    };
public:
    Hook_Right();
    void rotate() override;
    void rotate_hook_to_right_side();
    void rotate_hook_to_left_side();
    void rotate_hook_to_down();
private:
    position current_position_ = position::original;
};

