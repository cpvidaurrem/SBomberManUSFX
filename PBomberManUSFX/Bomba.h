#pragma once
class Bomba
{
private:
	
	int posicionX;
	int posicionY;

public:
	
	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	void visible();
};

