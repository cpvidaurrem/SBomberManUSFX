#include <iostream>
//#include "Detonador.h"
//#include "Bomber.h"
#include "GameObject.h"
#include "GameActor.h"

using namespace std;

int main() {
	//GameObject o1;
	GameActor a1("Pedro");
	GameActor a2;

	cout << "La posicion x es: " << a1.getPosicionX() << endl;
	cout << "El nombre del objeto es: " << a1.getNombre() << endl;
	cout << "El nombre del objeto es: " << a2.getNombre() << endl;


	
	

	/*Bomber JuanBombero;
	Bomber PedroBombero(10, 10, 5);

	int anchoImagen = JuanBombero.getAltoAvatar();
	int nv = JuanBombero.numeroVidas;

	cout << "Ancho Imagen: " << anchoImagen << " Numero vidas: " << nv << endl;
	cout << "Ancho Imagen: " << JuanBombero.getAltoAvatar() << " Numero vidas: " << JuanBombero.numeroVidas << endl;

	JuanBombero.setAltoAvatar(8);
	JuanBombero.setAnchoAvatar(8);

	cout << "Ancho Imagen: " << anchoImagen << " Numero vidas: " << nv << endl;
	cout << "Ancho Imagen: " << JuanBombero.getAltoAvatar() << " Numero vidas: " << JuanBombero.numeroVidas << endl;

	JuanBombero.mostrarInformacion();

	PedroBombero.mostrarInformacion();


	cout << "Primer paso rumbo a BomberMan" << endl;*/

	/*Detonador d1;

	d1.setHoras(1);
	d1.setMinutos(28);
	d1.setSegundos(18);

	while (d1.getEjecutado() != true) {
		d1.ReducirTiempo();
	}

	d1.Explotar();*/

	return 0;
}