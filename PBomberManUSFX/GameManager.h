#pragma once
#include<iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class GameManager
{
private:
    //La ventana a la que estaremos representando
    SDL_Window* gWindow;

    //El renderizador de ventanas
    SDL_Renderer* gRenderer;

public:
    GameManager();
    int onExecute();
	bool onInit();
    
};

