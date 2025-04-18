#include <fmt/core.h>
#include <memory>
#include <csignal>
#include <string>

#include "TextGameEngine.h"
#include "GameSelector.h"
#include "TextGameBuilder.h"

std::shared_ptr<TextGameEngine> game_engine;

void signalHandler(int signum)
{
    switch (signum) {
        case SIGINT:
            fmt::print("Received SIGINT (Interrupt from keyboard)\n");
            break;
        case SIGTERM:
            fmt::print("Received SIGTERM (Termination signal)\n");
            break;
        default:
            fmt::print("Received unknown signal {}\n", signum);
    }

    game_engine->stop();
}

int main() {
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    auto game_selector = new GameSelector();

    std::string game_type = game_selector->selectGame();

    game_engine = TextGameBuilder::buildTextGame(game_type);

    game_engine->start();

    return 0;
}