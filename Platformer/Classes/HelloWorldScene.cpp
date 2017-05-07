#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/role.plist","res/role.pvr.ccz");
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite* background = Sprite::create("res/background.png");
    background->setPosition(origin + visibleSize/2.0);
    background->setScale(visibleSize.width / background->getContentSize().width,
                         visibleSize.height / background->getContentSize().height);
    this->addChild(background);
    
    Player* player = Player::create(Player::PlayerType::PLAYER);
    player->setPosition(origin.x + player->getContentSize().width/2.0,
                        origin.y + visibleSize.height/3.5);
    this->addChild(player);
    
    Player* enemy = Player::create(Player::PlayerType::ENEMY1);
    enemy->setPosition(origin.x + visibleSize.width - player->getContentSize().width/2.0,
                        origin.y + visibleSize.height/3.5);
    this->addChild(enemy);
    
    //test animation
    player->playAnimationForever(1);
    enemy->playAnimationForever(1);
    
    return true;
}
