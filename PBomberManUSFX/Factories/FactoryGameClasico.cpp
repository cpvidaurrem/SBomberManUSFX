#include "FactoryGameClasico.h"

FactoryGameClasico::FactoryGameClasico() {
    gameManager = GameManager::instance;
    scaledTileSize = 32;
}

std::shared_ptr<GameObject> FactoryGameClasico::CreatePlayer(const int _positionX, const int _positionY)
{
    // spawn player
    auto player = std::make_shared<ClasicoPlayer>(gameManager->getAssetManager()->getTexture(GameTexture::Player), gameManager->getRenderer());
    player->setPosition(_positionX, _positionY);
    player->setSize(scaledTileSize, scaledTileSize);
    player->setClip(tileSize, tileSize, tileSize * 4, 0);

    return dynamic_pointer_cast<GameObject>(player);
}


std::shared_ptr<GameObject> FactoryGameClasico::CreateEnemy(AIType _type, const int _positionX, const int _positionY)
{
    //shared_ptr<GameObject> enemy(nullptr);
    auto enemy = std::make_shared<ClasicoEnemy>(gameManager->getAssetManager()->getTexture(GameTexture::Enemy1), gameManager->getRenderer());
    enemy->setPosition(_positionX, _positionY);
    enemy->setSize(scaledTileSize, scaledTileSize);
    enemy->setAIType(_type);

    return dynamic_pointer_cast<GameObject>(enemy);
}

/*ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff*/
std::shared_ptr<GameObject> FactoryGameClasico::CreateMuroMagico(const int _positionX, const int _positionY)
{
    auto muroMagico = std::make_shared<MuroMagicoClasico>(gameManager->getAssetManager()->getTexture(GameTexture::MuroMagicoClasico), gameManager->getRenderer());
    muroMagico->setPosition(_positionX, _positionY);
    muroMagico->setSize(scaledTileSize, scaledTileSize);

    return dynamic_pointer_cast<GameObject>(muroMagico);
}
/*ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff*/
