#include "GameActor.h"

GameActor::GameActor() : GameObject() {
	posicionX = 0;
	posicionY = 0;
}

GameActor::GameActor(string _nombre) : GameObject(_nombre) {
	posicionX = 0;
	posicionY = 0;
}
