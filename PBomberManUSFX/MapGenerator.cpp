#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
}

MapGenerator::MapGenerator(int _anchoPantalla, int _altoPantalla) : 
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla)
{

}

bool MapGenerator::crearObjetosJuego(string _path)
{
	//Crea un flujo de archivo
	fstream file;

	//Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false)
		return false;

	string line;
	int x = 0;
	int y = 0;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		for (int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;

			/*switch (chars[x]) {
			case '0':
				objetoNuevo = new PizoNatural();
			case '1':
				objetoNuevo = new ParedCeramica();
			case '2':
				objetoNuevo = new ParedMetalica();
			}*/

			if (objetoNuevo != nullptr) {
				vectorObjectosJuego.push_back(objetoNuevo);
			}

		}
	}

	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
}
