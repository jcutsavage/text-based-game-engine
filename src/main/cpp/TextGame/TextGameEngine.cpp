#include <fmt/core.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "PrintUtilities.h"
#include "TextGameEngine.h"

TextGameEngine::TextGameEngine() : running(true)
{
#ifdef _WIN32
    int result = std::system("cls");
#else
    int result = std::system("clear");
#endif
}

void TextGameEngine::start()
{
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    PrintingUtils::printLine("Exiting game...");
}

void TextGameEngine::stop()
{
    running = false;
}