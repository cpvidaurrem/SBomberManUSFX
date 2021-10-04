#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "GameObject.h"
#include "Bomber.h"
#include "MuroCeramica.h"
#include "MuroMetalico.h"
#include "SueloCesped.h"

class MapGenerator
{
private:
	vector<GameObject*> vectorObjectosJuego;
	int anchoPantalla;
	int altoPantalla;

public:
	//Contructores y destructores
	MapGenerator();
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	//Metodos accesores
	int getAnchoPantalla() { return anchoPantalla; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }

	int getAltoPantalla() { return altoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }

	//Metodos heredados

	//Metodos propios
	bool crearObjetosJuego(string _path);
	void transferirObjetosJuego(vector<GameObject*> &_vectorObjetosJuegoDestino);

};

