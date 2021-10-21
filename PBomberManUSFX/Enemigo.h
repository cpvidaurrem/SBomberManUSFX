#pragma once
#include"GameActor.h"

class Enemigo : public GameActor
{
public:
	Enemigo(Texture* _textura, Tile* _tileActual);
	void setTileActual(Tile* _tileNuevo);

};

