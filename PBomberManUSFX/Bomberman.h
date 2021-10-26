#pragma once
#include <iostream>
#include <map>
#include "GamePawn.h"

using namespace std;

class Bomberman : public GamePawn
{
private:
	int numMovimientos;
public:
	map<int,array<int, 20000>> movimientoBomberman;

	//Constructor
	Bomberman(Texture* _textura, Tile* _tileActual);
	void setTileActual(Tile* _tileNuevo) override;

	void update();
	void render();

};

