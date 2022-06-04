#pragma once

#include "Field.h"
#include "Figure.h"

enum class eActions {
    NO_ACTION = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 2
};

class Tetris
{
    public:
        Tetris();
        void run();

    private:
        eActions sleep_or_proccess_user_action();
        eActions read_user_input();

    private:
        Field field_;
        Figure *active_figure_;
};