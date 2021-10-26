#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
	renderer = nullptr;
}

MapGenerator::MapGenerator(SDL_Renderer* _renderer, int _anchoPantalla, int _altoPantalla, TilesGraph* _tilesGraph):
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla),
	renderer(_renderer),
	tilesGraph(_tilesGraph)
{
	
}

bool MapGenerator::crearObjetosJuego(string _path)
{
	// Crea un flujo de archivo
	fstream file;

	// Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false) {
		std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
		return false;
	}

	string line;
	
	Texture* texturaBomberman;
	texturaBomberman = new Texture();
	Texture* texturaBomberwoman;
	texturaBomberwoman = new Texture();
	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();
	Texture* texturaMuroVegetacion;
	texturaMuroVegetacion = new Texture(); //1. creando la textura para muro vegetacion

	//6. creando textura para los 5 enemigos
	Texture* texturaEnemigo1;
	texturaEnemigo1 = new Texture();
	Texture* texturaEnemigo2;
	texturaEnemigo2 = new Texture();
	Texture* texturaEnemigo3;
	texturaEnemigo3 = new Texture();
	Texture* texturaEnemigo4;
	texturaEnemigo4 = new Texture();
	Texture* texturaEnemigo5;
	texturaEnemigo5 = new Texture();

	Texture* texturanNewBomberman;
	texturanNewBomberman = new Texture(); //8. creando la textura del tercer bomberman
	
	Texture::renderer = renderer;

	texturaBomberman->loadFromImage("resources/bomberman.png");
	texturaBomberwoman->loadFromImage("resources/bomberwoman.png");
	texturaMuroCeramica->loadFromImage("resources/muro_ceramica.png");
	texturaMuroMetal->loadFromImage("resources/muro_metal.png");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped.png");
	texturaMuroVegetacion->loadFromImage("resources/muro_vegetacion.png"); //1. cargando la textura del muro vegetacion

	//6. cargando texturas de los enemigos
	texturaEnemigo1->loadFromImage("resources/enemigo1.png");
	texturaEnemigo2->loadFromImage("resources/enemigo2.png");
	texturaEnemigo3->loadFromImage("resources/enemigo3.png");
	texturaEnemigo4->loadFromImage("resources/enemigo4.png");
	texturaEnemigo5->loadFromImage("resources/enemigo5.png");
	
	texturanNewBomberman->loadFromImage("resources/bomberman_new2.png");//8. cargando la textura del tercer bomberman

	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;
	int newBombermanPosicionX = -1;
	int newBombermanPosicionY = -1;

	Pila<GameObject*> pilaSueloCesped(200);
	int cantidadSueloCesped = 0;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			if (chars[i] != ' ') {
				GameObject* objetoNuevo = nullptr;
				Tile* tileNuevo = tilesGraph->getTileEn(x, y);
				switch (chars[i]) {
				case '0':
					objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
					pilaSueloCesped.Insertar(objetoNuevo);
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}

					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}

					if (x > newBombermanPosicionX || y < newBombermanPosicionY) {
						newBombermanPosicionX = x;
						newBombermanPosicionY = y;
					}

					break;
				case '1':
					objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					
					break;
				case '2':
					objetoNuevo = new MuroCeramica(texturaMuroMetal, tileNuevo);
					break;
					/*case 'B':
						objetoNuevo = new Bomberman(texturaBomberman, tileNuevo);
						break;*/
				case '3': //1. asignando un caracter para muro vegetacion en el nivel
					objetoNuevo = new MuroVegetacion(texturaMuroVegetacion, tileNuevo);
					break;
					//6. Asignando caracteres a los enemigos
				case 'A':
					objetoNuevo = new Enemigo(texturaEnemigo1, tileNuevo);
					break;
				case 'B':
					objetoNuevo = new Enemigo(texturaEnemigo2, tileNuevo);
					break;
				case 'C':
					objetoNuevo = new Enemigo(texturaEnemigo3, tileNuevo);
					break;
				case 'D':
					objetoNuevo = new Enemigo(texturaEnemigo4, tileNuevo);
					break;
				case 'E':
					objetoNuevo = new Enemigo(texturaEnemigo5, tileNuevo);
					break;
				}

				if (objetoNuevo != nullptr) {
					((GameActor*)objetoNuevo)->setPosicionX(x * 34);
					((GameActor*)objetoNuevo)->setPosicionY(y * 34);
					vectorObjectosJuego.push_back(objetoNuevo);
					x++;
				}
			}
		}
		y++;
	}
	cout << "Numero suelo cesped: " << pilaSueloCesped.getCima()<<endl;

	
	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBomberman)->setPosicionX(bombermanPosicionX * 34);
		((GameActor*)objetoBomberman)->setPosicionY(bombermanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberman);
	}

	/*GameObject* objetoBomberwoman = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	if (objetoBomberwoman != nullptr) {
		((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
		((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
		((GamePawn*)objetoBomberwoman)->setBotomBomba(SDLK_o);
		((GamePawn*)objetoBomberwoman)->setBotomArriba(SDLK_w);
		((GamePawn*)objetoBomberwoman)->setBotomAbajo(SDLK_s);
		((GamePawn*)objetoBomberwoman)->setBotomIzquierda(SDLK_a);
		((GamePawn*)objetoBomberwoman)->setBotomDerecha(SDLK_d);

		vectorObjectosJuego.push_back(objetoBomberwoman);
	}*/

	/*GameObject* objetoNewBomberman = nullptr;
	tileNuevo = tilesGraph->getTileEn(newBombermanPosicionX, newBombermanPosicionY);
	objetoNewBomberman = new Bomberman(texturanNewBomberman, tileNuevo);
	if (objetoNewBomberman != nullptr) {
		((GameActor*)objetoNewBomberman)->setPosicionX(newBombermanPosicionX * 34);
		((GameActor*)objetoNewBomberman)->setPosicionY(newBombermanPosicionY * 34);
		((GamePawn*)objetoNewBomberman)->setBotomBomba(SDLK_g);
		((GamePawn*)objetoNewBomberman)->setBotomArriba(SDLK_i);
		((GamePawn*)objetoNewBomberman)->setBotomAbajo(SDLK_k);
		((GamePawn*)objetoNewBomberman)->setBotomIzquierda(SDLK_j);
		((GamePawn*)objetoNewBomberman)->setBotomDerecha(SDLK_l);

		vectorObjectosJuego.push_back(objetoNewBomberman);
	}*/


	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
