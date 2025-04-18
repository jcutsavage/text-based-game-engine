#include <fmt/core.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "PrintUtilities.h"
#include "TextGameEngine.h"

TextGameEngine::TextGameEngine(GameTypeEnum gametype) : gametype(gametype), running(true)
{
#ifdef _WIN32
    int result = std::system("cls");
#else
    int result = std::system("clear");
#endif
}

void TextGameEngine::start()
{
    if(running)
    {
        printGametypeSplashScreen();
    
        PrintUtils::printLine("Exiting game...");        
    }

}

void TextGameEngine::stop()
{
    running = false;
}

void TextGameEngine::printGametypeSplashScreen()
{
    const char* adventure_string = R"(
     _______  ______   __   __  _______  __    _  _______  __   __  ______    _______ 
    |   _   ||      | |  | |  ||       ||  |  | ||       ||  | |  ||    _ |  |       |
    |  |_|  ||  _    ||  |_|  ||    ___||   |_| ||_     _||  | |  ||   | ||  |    ___|
    |       || | |   ||       ||   |___ |       |  |   |  |  |_|  ||   |_||_ |   |___ 
    |       || |_|   ||       ||    ___||  _    |  |   |  |       ||    __  ||    ___|
    |   _   ||       | |     | |   |___ | | |   |  |   |  |       ||   |  | ||   |___ 
    |__| |__||______|   |___|  |_______||_|  |__|  |___|  |_______||___|  |_||_______|                                                                   
                                                                                  
                       Welcome to the Text-Based Adventure Game!
                     Use Arrow Keys or WASD to navigate the menus.
                                Press Enter to begin.
    )";

    const char* roguelike_string = R"(
     ______    _______  _______  __   __  _______  ___      ___   ___   _  _______ 
    |    _ |  |       ||       ||  | |  ||       ||   |    |   | |   | | ||       |
    |   | ||  |   _   ||    ___||  | |  ||    ___||   |    |   | |   |_| ||    ___|
    |   |_||_ |  | |  ||   | __ |  |_|  ||   |___ |   |    |   | |      _||   |___ 
    |    __  ||  |_|  ||   ||  ||       ||    ___||   |___ |   | |     |_ |    ___|
    |   |  | ||       ||   |_| ||       ||   |___ |       ||   | |    _  ||   |___ 
    |___|  |_||_______||_______||_______||_______||_______||___| |___| |_||_______|                                                                 
                                                                                     
                          Welcome to the Text-Based Adventure Game!
                        Use Arrow Keys or WASD to navigate the menus.
                                   Press Enter to begin.
       )";

    switch(gametype)
    {
        case GameTypeEnum::ADVENTURE_GAMETYPE:
            std::cout << adventure_string;
            break;
        case GameTypeEnum::ROGUELIKE_GAMETYPE:
            std::cout << roguelike_string;
            break;
        default:
            PrintUtils::printLine("You ever wonder why we're here?");
            break;
    }

    std::cout << "\n\n";
}