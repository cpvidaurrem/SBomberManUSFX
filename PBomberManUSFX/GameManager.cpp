#include "GameManager.h"


GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	texturaBomber1 = nullptr;
	texturaBomber2 = nullptr;

	texturaEnemigo = nullptr;
	texturaEnemigo2 = nullptr;
	texturaEnemigo3 = nullptr;
	texturaEnemigo4 = nullptr;
	texturaEnemigo5 = nullptr;

	texturaExplosion = nullptr;
	texturaExplosion2 = nullptr;
	texturaExplosion3 = nullptr;
	texturaExplosion4 = nullptr;
	texturaExplosion5 = nullptr;
}

bool GameManager::onInit() {

	//Initialization flag
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Bomber Man USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			////Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
};

bool GameManager::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture("texture.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}


void GameManager::close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = nullptr;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int GameManager::onExecute() {
	if (!onInit()) {
		cout << "Failed to initialize!" << endl;
		return -1;
	}
	else
	{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event event;

			texturaBomber1 = new Texture(gRenderer);
			texturaBomber1->loadFromImage("resources/bomber.bmp");
			//texturaBomber2 = new Texture(gRenderer);
			//texturaBomber2->loadFromImage("resources/textures.bmp");

			texturaEnemigo = new Texture(gRenderer);
			texturaEnemigo->loadFromImage("resources/textures.bmp");
			texturaEnemigo2 = new Texture(gRenderer);
			texturaEnemigo2->loadFromImage("resources/textures.bmp");
			texturaEnemigo3 = new Texture(gRenderer);
			texturaEnemigo3->loadFromImage("resources/textures.bmp");
			texturaEnemigo4 = new Texture(gRenderer);
			texturaEnemigo4->loadFromImage("resources/textures.bmp");
			texturaEnemigo5 = new Texture(gRenderer);
			texturaEnemigo5->loadFromImage("resources/textures.bmp");

			texturaExplosion = new Texture(gRenderer);
			texturaExplosion->loadFromImage("resources/textures.bmp");
			texturaExplosion2 = new Texture(gRenderer);
			texturaExplosion2->loadFromImage("resources/textures.bmp");
			texturaExplosion3 = new Texture(gRenderer);
			texturaExplosion3->loadFromImage("resources/textures.bmp");
			texturaExplosion4 = new Texture(gRenderer);
			texturaExplosion4->loadFromImage("resources/textures.bmp");
			texturaExplosion5 = new Texture(gRenderer);
			texturaExplosion5->loadFromImage("resources/textures.bmp");

			Bomber* b1 = new Bomber(texturaBomber1);
			//Bomber* b2 = new Bomber(texturaBomber2);

			Enemigo* e = new Enemigo(texturaEnemigo);
			Enemigo* e2 = new Enemigo(texturaEnemigo);
			Enemigo* e3 = new Enemigo(texturaEnemigo);
			Enemigo* e4 = new Enemigo(texturaEnemigo);
			Enemigo* e5 = new Enemigo(texturaEnemigo);

			Explosion* ex = new Explosion(texturaExplosion);
			Explosion* ex2 = new Explosion(texturaExplosion2);
			Explosion* ex3 = new Explosion(texturaExplosion3);
			Explosion* ex4 = new Explosion(texturaExplosion4);
			Explosion* ex5 = new Explosion(texturaExplosion5);

			b1->setImagenX(3);
			b1->setImagenY(4);
			b1->setAncho(18);
			b1->setAlto(32);

			/*b2->setImagenX(570);
			b2->setImagenY(3);
			b2->setAncho(30);
			b2->setAlto(35);*/

			e->setImagenX(0);
			e->setImagenY(160);
			e->setAncho(24);
			e->setAlto(24);
			e2->setImagenX(0);
			e2->setImagenY(184);
			e2->setAncho(24);
			e2->setAlto(24);
			e3->setImagenX(0);
			e3->setImagenY(208);
			e3->setAncho(24);
			e3->setAlto(24);
			e4->setImagenX(0);
			e4->setImagenY(232);
			e4->setAncho(24);
			e4->setAlto(24);
			e5->setImagenX(0);
			e5->setImagenY(256);
			e5->setAncho(24);
			e5->setAlto(24);

			ex->setImagenX(305);
			ex->setImagenY(24);
			ex->setAncho(24);
			ex->setAlto(24);
			ex2->setImagenX(305);
			ex2->setImagenY(48);
			ex2->setAncho(24);
			ex2->setAlto(24);
			ex3->setImagenX(305);
			ex3->setImagenY(72);
			ex3->setAncho(24);
			ex3->setAlto(24);
			ex4->setImagenX(305);
			ex4->setImagenY(96);
			ex4->setAncho(24);
			ex4->setAlto(24);
			ex5->setImagenX(377);
			ex5->setImagenY(0);
			ex5->setAncho(24);
			ex5->setAlto(24);

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&event) != 0)
				{
					//User requests quit
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen
				//SDL_RenderClear(gRenderer);

				//Render texture to screen
				//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
			
				
				////Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Update screen

				/*onLoop();
				onRender();*/
				b1->render();
				//b2->setPosicionX(rand() % SCREEN_WIDTH);
				//b2->setPosicionY(rand() % SCREEN_HEIGHT);

				//b2->render();

				e->setPosicionX(400);
				e->setPosicionY(300);
				e->render();
				e2->setPosicionX(400+24+4);
				e2->setPosicionY(300);
				e2->render();
				e3->setPosicionX(400+48+8);
				e3->setPosicionY(300);
				e3->render();
				e4->setPosicionX(400+72+12);
				e4->setPosicionY(300);
				e4->render();
				e5->setPosicionX(400+96+16);
				e5->setPosicionY(300);
				e5->render();

				ex->setPosicionX(400);
				ex->setPosicionY(0);
				ex->render();
				ex2->setPosicionX(400+24+4);
				ex2->setPosicionY(0);
				ex2->render();
				ex3->setPosicionX(400+48+8);
				ex3->setPosicionY(0);
				ex3->render();
				ex4->setPosicionX(400+72+12);
				ex4->setPosicionY(0);
				ex4->render();
				ex5->setPosicionX(400+96+16);
				ex5->setPosicionY(0);
				ex5->render();

				SDL_RenderPresent(gRenderer);
			}
		
	}

	//Free resources and close SDL
	close();

	return 0;

}

SDL_Texture* GameManager::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}