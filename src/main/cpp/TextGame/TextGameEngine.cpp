#include <fmt/core.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "TextGameEngine.h"

TextGameEngine::TextGameEngine() : running(true)
{
#ifdef _WIN32
    std::system("cls");
#else
    int result = std::system("clear");
#endif
    fmt::println("Text game created!");
}

void TextGameEngine::start()
{
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void TextGameEngine::stop()
{
    running = false;
}