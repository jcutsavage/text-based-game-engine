#include "TextGameBuilder.h"


std::shared_ptr<TextGame> TextGameBuilder::buildTextGame()
{
    return std::make_shared<TextGame>();
}