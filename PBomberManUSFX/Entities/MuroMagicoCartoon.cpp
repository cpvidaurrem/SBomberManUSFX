#include "MuroMagicoCartoon.h"
#include "../Const.h"

MuroMagicoCartoon::MuroMagicoCartoon(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer)
    : Wall(_texture, _renderer)
{
}

void MuroMagicoCartoon::update(const unsigned int delta)
{
    Wall::update(delta);
}

void MuroMagicoCartoon::render(const SDL_Rect& camera)
{
    Wall::render(camera);
    //std::cout << "dentro de muroMagico" << std::endl;

}
