#include <fmt/core.h>
#include <memory>
#include <csignal>
#include <string>
#include <cstdlib>

#include "TextGameEngine.h"
#include "GameSelector.h"
#include "TextGameBuilder.h"

std::shared_ptr<TextGameEngine> game_engine;

void signalHandler(int signum)
{
    game_engine->stop();
}

int main() {
    std::srand(time(nullptr));

    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    auto game_selector = new GameSelector();

    std::string game_type = game_selector->selectGame();

    game_engine = TextGameBuilder::buildTextGame(game_type);

    game_engine->start();

    return 0;
}