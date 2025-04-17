#ifndef TEXTGAME_H_
#define TEXTGAME_H_

#include <atomic>

class TextGame
{
public:

    TextGame();

    void start();

    void stop();

private:

    std::atomic<bool> running;
};

#endif