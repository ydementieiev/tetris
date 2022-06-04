#pragma once

#include "Figure.h"

class Stick : public Figure
{
public:
    Stick();
    void rotate() override;
};
