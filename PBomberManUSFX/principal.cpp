#include <iostream>
#include "GameManager.h"
//#include "Detonador.h"
//#include "Bomber.h"
//#include "GameObject.h"
//#include "GameActor.h"

using namespace std;

int main() {
	GameManager* gm01 = new GameManager();


	/*int* c = new int(4);
	int* a;
	int b = 10;
	cout <<"Direccion de memoria donde esta b: " << &b << "El valor de la variable b: " << b << endl;
	a = &b;

	cout << "El valor que almacena la variable a: " << a << "El valor almacenado en la direccion que tien a es: " << *a << endl;*/
	/*GameObject o1;
	GameActor a1("Pedro");
	GameActor a2;

	cout << "La posicion x es: " << a1.getPosicionX() << endl;
	cout << "El nombre del objeto es: " << a1.getNombre() << endl;
	cout << "El nombre del objeto es: " << a2.getNombre() << endl;*/


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