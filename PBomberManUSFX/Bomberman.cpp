#include "Bomberman.h"

Bomberman::Bomberman(Texture* _textura, Tile* _tileActual) :GamePawn(_textura, _tileActual)
{

	tileActual = _tileActual;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setBomberman(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else{
		posicionX = 0;
		posicionY = 0;
	}

	velocidad = 1;
	movil = true;
	enMovimiento = false;
	direccionActual = MOVE_DIRECTION_NONE;
	direccionSiguiente = MOVE_DIRECTION_NONE;

}

void Bomberman::update()
{
	if (keyboardInput->IsKeyOn(botonAbajo)) {
		direccionSiguiente = MOVE_DIRECTION_ABAJO;
	}
	else if (keyboardInput->IsKeyOn(botonArriba)) {
		direccionSiguiente = MOVE_DIRECTION_ARRIBA;
	}
	else if (keyboardInput->IsKeyOn(botonDerecha)) {
		direccionSiguiente = MOVE_DIRECTION_DERECHA;
	}
	else if (keyboardInput->IsKeyOn(botonIzquierda)) {
		direccionSiguiente = MOVE_DIRECTION_IZQUIERDA;
	}


	if (tileActual != nullptr && tileActual->getSueloCesped() != nullptr) {
		//Camina normalmente, se revisan colisiones
	}

	// Animar Bomberman
	if (enMovimiento) {
		//GameActor::update();
	}

	//// Cambiar de direccion y tileSiguiente
	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;
	}
	else {
		switch (direccionActual) {
		case MOVE_DIRECTION_ARRIBA:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			break;
		case MOVE_DIRECTION_ABAJO:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			break;
		case MOVE_DIRECTION_IZQUIERDA:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			break;
		case MOVE_DIRECTION_DERECHA:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			break;
		}

		// Asignacion de coliciones
		//
		//

		// Cambio de direccion

		if ((direccionActual == MOVE_DIRECTION_ABAJO || direccionActual == MOVE_DIRECTION_ARRIBA) && posicionY == tileSiguiente->getPosicionTileY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_DIRECTION_IZQUIERDA || direccionActual == MOVE_DIRECTION_DERECHA) && posicionX == tileSiguiente->getPosicionTileX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
}

void Bomberman::render()
{
	GamePawn::render();
}
void Bomberman::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr){
		tileActual->setBomberman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setBomberman(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
	}

}
