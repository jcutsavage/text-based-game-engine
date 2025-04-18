#include <fmt/core.h>
#include <thread>
#include <chrono>
#include "TextGameEngine.h"

TextGameEngine::TextGameEngine() : running(true)
{
    fmt::println("Text game created!");
}

void TextGameEngine::start()
{
    while(running)
    {
        fmt::println("Waiting....");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void TextGameEngine::stop()
{
    running = false;
}