#include <fmt/core.h>
#include <memory>
#include <csignal>
#include <string>
#include <cstdlib>

#include "Menu.h"
#include "PrintUtilities.h"

#include "GameTypeEnum.h"

#include "TextGameEngine.h"
#include "GameSelector.h"
#include "TextGameBuilder.h"

std::shared_ptr<TextGameEngine> game_engine;

enum class Options 
{
    UNKNOWN_OPTION = -1,
    NEW_OPTION = 0,
    LOAD_OPTION = 1,
    EXIT_OPTION = 2,
    SETTINGS_OPTION = 100,
    CREDITS_OPTION = 101,
    HELP_OPTION = 102
};

void signalHandler(int signum)
{
    game_engine->stop();
}

int main() {
#ifdef _WIN32
    int result = std::system("cls");
#else
    int result = std::system("clear");
#endif

    std::srand(time(nullptr));

    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    std::vector<std::vector<std::string>> menuGrid = {
        {"New", "Load", "Exit"},
        {"Settings", "Credits", "Help"}
    };

    std::cout << R"(
    _______  ___      _______  _______  _______  __   __  _______  ___      ______   _______  ______   
    |       ||   |    |   _   ||       ||       ||  | |  ||       ||   |    |      | |       ||    _ |  
    |    _  ||   |    |  |_|  ||       ||    ___||  |_|  ||   _   ||   |    |  _    ||    ___||   | ||  
    |   |_| ||   |    |       ||       ||   |___ |       ||  | |  ||   |    | | |   ||   |___ |   |_||_ 
    |    ___||   |___ |       ||      _||    ___||       ||  |_|  ||   |___ | |_|   ||    ___||    __  |
    |   |    |       ||   _   ||     |_ |   |___ |   _   ||       ||       ||       ||   |___ |   |  | |
    |___|    |_______||__| |__||_______||_______||__| |__||_______||_______||______| |_______||___|  |_|                                                                  
                                                                              
                            Welcome to Fayte's Text-Based Game Engine!
                          Use Arrow Keys or WASD to navigate the menus.
                                      Press Enter to begin.
    )";

    std::cout << "\n\n";

    Menu mainMenu(menuGrid);
    int choice = mainMenu.run();

    switch((Options)choice)
    {
        case Options::NEW_OPTION:
        {
            auto game_selector = new GameSelector();

            GameTypeEnum game_type = game_selector->selectGame();
    
            game_engine = TextGameBuilder::buildTextGame(game_type);
    
            game_engine->start();

            break;
        }

        case Options::SETTINGS_OPTION:
        {
            break;
        }

        case Options::EXIT_OPTION:
        {
            PrintUtils::printLine("Goodbye!");
            break;
        }

        default:
        {
            PrintUtils::printLine("Buddy, how did we even get here?");
            break;
        }  
    };

    return 0;
}