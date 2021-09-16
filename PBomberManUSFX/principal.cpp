#include <iostream>
#include "Detonador.h"

using namespace std;

int main() {

	cout << "Primer paso rumbo a BomberMan" << endl;

	Detonador d1;

	d1.setHoras(1);
	d1.setMinutos(28);
	d1.setSegundos(18);

	while (d1.getEjecutado() != true) {
		d1.ReducirTiempo();
	}

	d1.Explotar();

	return 0;
}