#include "GameActor.h"

GameActor::GameActor() : GameObject() {
	posicionX = 0;
	posicionY = 0;

	direccionActual = GAME_DIRECTION_NONE;
	direccionSiguiente = GAME_DIRECTION_NONE;
}

GameActor::GameActor(string _nombre) : GameObject(_nombre) {
	posicionX = 0;
	posicionY = 0;

	direccionActual = GAME_DIRECTION_NONE;
	direccionSiguiente = GAME_DIRECTION_NONE;
}
