#pragma once
#include <iostream>
using namespace std;
class Bomber
{
private:
	int anchoAvatar;
	int altoAvatar;
	int posicionX;
	int posicionY;

public:
	int numeroVidas;

	//Constructor
	Bomber();
	Bomber(int _anchoAvatar, int _altoAvatar, int _numeroVidas);


	int getAnchoAvatar() { return anchoAvatar; }
	void setAnchoAvatar(int _anchoAvatar) { anchoAvatar = _anchoAvatar; }

	int getAltoAvatar() { return altoAvatar; }
	void setAltoAvatar(int _altoAvatar) { altoAvatar = _altoAvatar; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void Morir();
	void Correr();
	void colocarBomba();
	void moverse();
	void mostrarInformacion();
};