#ifndef GAMESELECTOR_H_
#define GAMESELECTOR_H_

#include <set>
#include <string>

class GameSelector
{
public:
    GameSelector();

    std::string selectGame();

private:
    std::set<std::string> game_list;
};

#endif