//
//  NewBullet.h
//  MyMoonWarrior
//
//  Created by cesc on 13-7-14.
//
//

#ifndef __MyMoonWarrior__NewBullet__
#define __MyMoonWarrior__NewBullet__

#include "cocos2d.h"
USING_NS_CC;


class  NewBullet : public CCSprite {
    
    
public:
    
   static NewBullet* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
    
    bool initWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
   static  NewBullet* createWithSpriteFrameName(const char *pszSpriteFrameName);
    
    CC_SYNTHESIZE(int, bullettag,BulletTag );
};

#endif /* defined(__MyMoonWarrior__NewBullet__) */
