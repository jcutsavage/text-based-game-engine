#include <fmt/core.h>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "PrintUtilities.h"
#include "GameSelector.h"

bool equals_ignore_case(const std::string& a, const std::string& b) {
    return a.size() == b.size() &&
           std::equal(a.begin(), a.end(), b.begin(),
                      [](unsigned char c1, unsigned char c2) {
                          return std::tolower(c1) == std::tolower(c2);
                      });
}

bool contains_ignore_case(const std::set<std::string>& s, const std::string& value) {
    return std::any_of(s.begin(), s.end(), [&](const std::string& str) {
        return equals_ignore_case(str, value);
    });
}

GameSelector::GameSelector() :
    game_list{"ADVENTURE"}
{
}

std::string GameSelector::selectGame()
{
    bool selection_valid = false;

    std::string selection;

    typeOutput("Welcome! ");

    while(!selection_valid)
    {
        typeOutputLine("Please choose a game type:\n");

        for(auto game_type : game_list)
        {
            typeOutput(game_type + " ");
        }
    
        typeOutputLine("\n");
    
        typeOutput("Your selection: ");
        
        std::getline(std::cin, selection);

        std::transform(selection.begin(), selection.end(), selection.begin(), ::toupper);

        typeOutputLine("\n");

        if(contains_ignore_case(game_list, selection))
        {
            selection_valid = true;
        }
        else
        {
            typeOutputLine("That is an invalid gametype!\n");
        }
    }

    typeOutput("Launching " + selection + " game");

    typeOutputLine("....", 500, 0);

    return selection;

}