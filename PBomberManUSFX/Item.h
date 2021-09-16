#pragma once
class Item
{
private:
	int posicionX;
	int posicionY;
	int tiempoVisible;

public:
	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getTiempoVisible() { return tiempoVisible; }
	void setTiempoVisible(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }

	void visible();
};

