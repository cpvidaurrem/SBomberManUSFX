#include "EnemigoFantasma.h"

EnemigoFantasma::EnemigoFantasma(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer):Enemy(_texture, _renderer)
{
	/*gameManager = GameManager::instance;
	scaledTileSize = 32;*/
}

//std::shared_ptr<GameObject> EnemigoFantasma::CrearEnemigoFantasma(AIType _type, const int _positionX, const int _positionY) {
//
//    auto enemy = std::make_shared<Enemy>(gameManager->getAssetManager()->getTexture(GameTexture::EnemyGhost), gameManager->getRenderer());
//    enemy->setPosition(_positionX, _positionY);
//    enemy->setSize(scaledTileSize, scaledTileSize);
//    enemy->setAIType(_type);
//
//    return dynamic_pointer_cast<GameObject>(enemy);
//}
