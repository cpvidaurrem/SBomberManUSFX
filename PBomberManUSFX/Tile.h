#pragma once
#include <SDL.h>

//
//#include "Bomberman.h"
//#include "MuroCeramica.h"
//#include "MuroMetal.h"
//#include "SueloCesped.h"

class Bomberman;
class MuroCeramica;
class MuroMetal;
class SueloCesped;
class MuroVegetacion; //1. añadiendo la clase MuroVegetacion
class Enemigo; //6. añadiendo la clase Enemigo

class Tile
{
private:
	Bomberman* bomberman;
	MuroCeramica* muroCeramica;
	MuroMetal* muroMetal;
	SueloCesped* sueloCesped;
	MuroVegetacion* muroVegetación; // 1. creando un atributo del tipo MuroVegetacion
	Enemigo* enemigo; //6. Creando un atributo del tipo Enemigo

	int posicionTileX;
	int posicionTileY;

public:
	static const int anchoTile = 34;
	static const int altoTile = 34;

	// Constructores y destructores
	Tile();
	Tile(int _posicionTileX, int _posicionTileY);

	// Metodos accesores
	Bomberman* getBomberman() { return bomberman; }
	MuroCeramica* getMuroCeramica() { return muroCeramica; }
	MuroMetal* getMuroMetal() { return muroMetal; }
	SueloCesped* getSueloCesped() { return sueloCesped; }
	MuroVegetacion* getMuroVegetacion() { return muroVegetación; } //1. geter para muroVegetacion
	Enemigo* getEnemigo() { return enemigo; } //6. geter para enemigo
	int getPosicionTileX() { return posicionTileX; }
	int getPosicionTileY() { return posicionTileY; }

	void setBomberman(Bomberman* _bomberman) { bomberman = _bomberman; }
	void setMuroCeramica(MuroCeramica* _muroCeramica) { muroCeramica = _muroCeramica; }
	void setMuroMetal(MuroMetal* _muroMetal) { muroMetal = _muroMetal; }
	void setSueloCesped(SueloCesped* _sueloCesped) { sueloCesped = _sueloCesped; }
	void setMuroVegetacion(MuroVegetacion* _muroVegetacion) { muroVegetación = _muroVegetacion; } //1. seter para muroVegetacion
	void setEnemigo(Enemigo* _enemigo) { enemigo = _enemigo; }//6. seter para enemigo
	void setPosicionTileX(int _posicionTileX) { posicionTileX = _posicionTileX; }
	void setPosicionTileY(int _posicionTileY) { posicionTileY = _posicionTileY; }
};

