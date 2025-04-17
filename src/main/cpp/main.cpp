#include <fmt/core.h>
#include <memory>
#include <csignal>

#include "TextGame.h"
#include "TextGameBuilder.h"

std::shared_ptr<TextGame> game;

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

    game->stop();
}

int main() {
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    fmt::println("Starting up your game!");

    game = TextGameBuilder::buildTextGame();

    game->start();

    return 0;
}