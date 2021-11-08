#include "MapGenerator.h"
#include "Texture.h"

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

	//Muros BORDES
	Texture* texturaMuroMetalEIA;
	texturaMuroMetalEIA = new Texture();
	Texture* texturaMuroMetalEIAb;
	texturaMuroMetalEIAb = new Texture();
	Texture* texturaMuroMetalEDA;
	texturaMuroMetalEDA = new Texture();
	Texture* texturaMuroMetalEDAb;
	texturaMuroMetalEDAb = new Texture();
	Texture* texturaMuroMetalI;
	texturaMuroMetalI = new Texture();
	Texture* texturaMuroMetalD;
	texturaMuroMetalD = new Texture();
	Texture* texturaMuroMetalA;
	texturaMuroMetalA = new Texture();
	Texture* texturaMuroMetalAb;
	texturaMuroMetalAb = new Texture();
	
	Texture::renderer = renderer;

	texturaBomberman->loadFromImage("resources/bomberwoman.png");
	texturaBomberwoman->loadFromImage("resources/bomberman.png");
	texturaMuroCeramica->loadFromImage("resources/muro_ceramica2.png");
	texturaMuroMetal->loadFromImage("resources/muro_metal3.png");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped2.png");

	//texturas MUROS BORDES
	texturaMuroMetalEIA->loadFromImage("resources/muro_metal_EIA.png");
	texturaMuroMetalEIAb->loadFromImage("resources/muro_metal_EIAb.png");
	texturaMuroMetalEDA->loadFromImage("resources/muro_metal_EDA.png");
	texturaMuroMetalEDAb->loadFromImage("resources/muro_metal_EDAb.png");
	texturaMuroMetalI->loadFromImage("resources/muro_metal_I.png");
	texturaMuroMetalD->loadFromImage("resources/muro_metal_D.png");
	texturaMuroMetalA->loadFromImage("resources/muro_metal_A.png");
	texturaMuroMetalAb->loadFromImage("resources/muro_metal_Ab.png");
	
	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			if (chars[i] != ' ') {
				GameObject* objetoNuevo = nullptr;
				Tile* tileNuevo = tilesGraph->getTileEn(x, y);
				switch (chars[i]) {
				case '0':
					//objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
					objetoNuevo = new SueloCesped((std::shared_ptr<SDL_Texture>)texturaSueloCesped->getTexturaSDL(), renderer, tileNuevo);
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}

					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}

					//pilaObjetosJuegoMurosMetal.Insertar((GameActor*)objetoNuevo);

					break;
				case '1':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetal->getTexturaSDL(), renderer, tileNuevo);
					break;
				case '2':
					//objetoNuevo = new MuroCeramica(texturaMuroMetal, tileNuevo);
					objetoNuevo = new MuroCeramica((std::shared_ptr<SDL_Texture>)texturaMuroCeramica->getTexturaSDL(), renderer, tileNuevo);
					break;
					/*case 'B':
						objetoNuevo = new Bomberman(texturaBomberman, tileNuevo);
						break;*/
				case 'M':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalEIA->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'N':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalEIAb->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'O':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalEDA->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'P':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalEDAb->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'Q':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalI->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'R':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalD->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'S':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalA->getTexturaSDL(), renderer, tileNuevo);
					break;
				case 'T':
					//objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					objetoNuevo = new MuroMetal((std::shared_ptr<SDL_Texture>)texturaMuroMetalAb->getTexturaSDL(), renderer, tileNuevo);
					break;
				}

				if (objetoNuevo != nullptr) {

					((Sprite*)objetoNuevo)->setPosition(x * Tile::anchoTile, y * Tile::altoTile);
					((Sprite*)objetoNuevo)->setSize(Tile::anchoTile, Tile::altoTile);
					((Sprite*)objetoNuevo)->setClip(Tile::anchoTile, Tile::altoTile, x * Tile::anchoTile, y * Tile::altoTile);
			
					vectorObjectosJuego.push_back(objetoNuevo);
					x++;
				}
			}
		}
		y++;
	}

	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	//objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	objetoBomberman = new Bomberman((std::shared_ptr<SDL_Texture>)texturaBomberman->getTexturaSDL(), renderer, tileNuevo);
	if (objetoBomberman != nullptr) {
		((Sprite*)objetoBomberman)->setPosition(bombermanPosicionX * Tile::anchoTile, bombermanPosicionY * Tile::altoTile);
		((Sprite*)objetoBomberman)->setSize(Tile::anchoTile, Tile::altoTile);
		((Sprite*)objetoBomberman)->setClip(Tile::anchoTile, Tile::altoTile, bombermanPosicionX * Tile::anchoTile, bombermanPosicionY * Tile::altoTile);

		vectorObjectosJuego.push_back(objetoBomberman);
	}


	//GameObject* objetoBomberwoman = nullptr;
	//tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	//objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	//if (objetoBomberwoman != nullptr) {
	//	((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
	//	((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
	//	((GamePawn*)objetoBomberwoman)->setBotomBomba(SDLK_o);
	//	((GamePawn*)objetoBomberwoman)->setBotomArriba(SDLK_w);
	//	((GamePawn*)objetoBomberwoman)->setBotomAbajo(SDLK_s);
	//	((GamePawn*)objetoBomberwoman)->setBotomIzquierda(SDLK_a);
	//	((GamePawn*)objetoBomberwoman)->setBotomDerecha(SDLK_d);

	//	vectorObjectosJuego.push_back(objetoBomberwoman);
	//}


	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	//_vectorObjetosJuegoDestino = vectorObjectosJuego;
	
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
