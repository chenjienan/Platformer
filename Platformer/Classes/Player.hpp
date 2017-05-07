//
//  Player.hpp
//  Platformer
//
//  Created by Terence Chen on 2017-05-06.
//
//

#ifndef Player_hpp
#define Player_hpp
#include "cocos2d.h"
USING_NS_CC; //using namespace cocos2d

class Player : public Sprite
{
public:
    enum PlayerType
    {
        PLAYER,
        ENEMY1,
        ENEMY2
    };
    bool init(PlayerType type);
    static Player* create(PlayerType type);
    void addAnimation();
    void playAnimationForever(int index);
    
private:
    PlayerType _type;
    std::string _name;
    int _animationNum;
    std::vector<int> _animationFrameNum;
    std::vector<std::string> _animationNames;
    
};



#endif /* Player_hpp */
