#include <fmt/core.h>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

#include "PrintUtilities.h"
#include "Menu.h"
#include "GameSelector.h"


GameSelector::GameSelector() :
    gametypes{{"ADVENTURE", "ROGUELIKE"}}
{
}

GameTypeEnum GameSelector::selectGame()
{
    bool selection_valid = false;

#ifdef _WIN32
    int result = std::system("cls");
#else
    int result = std::system("clear");
#endif

    int selection;

    PrintUtils::print("Welcome! Please choose a game type:\n");

    Menu gametypeMenu(gametypes);

    selection = gametypeMenu.run();

    //PrintUtils::print("Launching " + gametypes[selection] + " game");

    PrintUtils::printLine("....", 500, 0);

    return (GameTypeEnum)selection;

}