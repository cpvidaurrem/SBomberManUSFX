#include "Bomber.h"

Bomber::Bomber()
{
	anchoAvatar = 0;
	altoAvatar = 0;

	numeroVidas = 3;
	mostrarInformacion();
}

Bomber::Bomber(int _anchoAvatar, int _altoAvatar, int _numeroVidas)
{
	anchoAvatar = _anchoAvatar;
	altoAvatar = _altoAvatar;
	numeroVidas = _numeroVidas;
	mostrarInformacion();
}

void Bomber::colocarBomba()
{
}

void Bomber::moverse()
{
}

void Bomber::mostrarInformacion()
{
	cout << "INFORMACION BOMBER" << endl;
	cout << " Ancho avatar: " << anchoAvatar << " Alto avatar: " << altoAvatar <<"Numero de vidas: "<<numeroVidas << endl;
}
