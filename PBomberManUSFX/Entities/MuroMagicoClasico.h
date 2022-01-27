#pragma once
#include "Wall.h"
class MuroMagicoClasico :
    public Wall
{
public:
    MuroMagicoClasico(std::shared_ptr<SDL_Texture> texture, SDL_Renderer* renderer);
    void update(const unsigned int delta) override;
    void render(const SDL_Rect& camera);
};

