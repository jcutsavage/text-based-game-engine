#include <fmt/core.h>
#include <thread>
#include <chrono>
#include "TextGame.h"

TextGame::TextGame() : running(true)
{
    fmt::println("Text game created!");
}

void TextGame::start()
{
    while(running)
    {
        fmt::println("Waiting....");
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

void TextGame::stop()
{
    running = false;
}