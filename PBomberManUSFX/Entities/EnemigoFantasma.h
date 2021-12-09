#pragma once
#include "Enemy.h"
#include <SDL.h>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../Const.h"
#include "../Entities/Music.h"
#include "../Entities/Sound.h"
#include "../Entities/Text.h"
#include "../Scenes/Scene.h"
#include "../GameManager.h"
#include "../Managers/AssetManager.h"
#include "../GameAITypes.h"
#include "../GameTextures.h"

class EnemigoFantasma :
    public Enemy
{
private:
    /*GameManager* gameManager;
    int scaledTileSize;*/
public:
    EnemigoFantasma(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);

    //std::shared_ptr<GameObject> CrearEnemigoFantasma(AIType _type, const int _positionX, const int _positionY);
    
};

