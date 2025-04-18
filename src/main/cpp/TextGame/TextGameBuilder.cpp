#include "TextGameBuilder.h"


std::shared_ptr<TextGameEngine> TextGameBuilder::buildTextGame(std::string game_name)
{
    return std::make_shared<TextGameEngine>();
}