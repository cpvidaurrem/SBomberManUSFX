#include <iostream>
#include "GameManager.h"
//#include "Detonador.h"
//#include "Bomber.h"
//#include "GameObject.h"
//#include "GameActor.h"

using namespace std;

int main(int argc, char* args[]) {
	GameManager* gm01 = new GameManager();

	return gm01->onExecute();

}