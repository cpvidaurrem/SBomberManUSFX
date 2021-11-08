#include <iostream>
#include "GameManager.h"
//#include "Bomberman.h"
//#include "GameObject.h"
//#include "GameActor.h"
//#include "Detonador.h"

using namespace std;

int main(int argc, char* args[])
{
	//Singleton
	GameManager* gm01;
	gm01 = GameManager::Instance();

	return gm01->onExecute();

	/*GameManager* gm01 = new GameManager();
	
	return gm01->onExecute();*/
}