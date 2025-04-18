#ifndef TEXTGAMEENGINE_H_
#define TEXTGAMEENGINE_H_

#include <atomic>

class TextGameEngine
{
public:

    TextGameEngine();

    void start();

    void stop();

private:

    std::atomic<bool> running;
};

#endif