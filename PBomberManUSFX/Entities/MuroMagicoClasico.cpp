#include "MuroMagicoClasico.h"
#include "../Const.h"

MuroMagicoClasico::MuroMagicoClasico(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer)
    : Wall(_texture, _renderer)
{
}

void MuroMagicoClasico::update(const unsigned int delta)
{
    Wall::update(delta);
}

void MuroMagicoClasico::render(const SDL_Rect& camera)
{
    Wall::render(camera);
    //std::cout << "dentro de muroMagicoClasico" << std::endl;

}