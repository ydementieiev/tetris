#pragma once
#include <string>
const int SIZE_MENU_LINE = 8;
struct MenuLine
{
    std::string line;
    int x;
    int y;
};

class Menu
{
private:
    MenuLine menu[SIZE_MENU_LINE];
    int gametime = 0;
public:
    Menu();
    void getMenu(MenuLine * mn);
};

