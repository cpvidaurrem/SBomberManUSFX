#pragma once
class Muro
{
private:
	int posicionX;
	int posicionY;
	bool destruible;

public:
	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	bool getDestruible() { return destruible; }
	void setDestruible(int _destruible) { destruible = _destruible; }
	
	void destruir();

};

