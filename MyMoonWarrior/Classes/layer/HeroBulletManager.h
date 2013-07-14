//
//  HeroBulletManager.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-14.
//
//

#ifndef __MyMoonWarrior__HeroBulletManager__
#define __MyMoonWarrior__HeroBulletManager__

#include <iostream>

#include "BasicLayer.h"

#include "Effects.h"
class HeroBulletMananger: public BasicLayer {
    
    
public:
    
    
    
    HeroBulletMananger();
    ~HeroBulletMananger();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( HeroBulletMananger );
    
    void addNewBullet( const CCPoint point,const CCRect planeBox );
    
    void moveAllBullets( float t );
    
    //  利用系统自带的宏 创建一个protected的变量bulletsArray  和 一个返回bulletsArray的const 函数
    CC_SYNTHESIZE_READONLY(CCArray*, bulletsArray, BulletsArray );
    
private:
    CCSpriteBatchNode* mBulletsBatchNode;

    
    
    
    
private:
    CCSprite* m_warrior;
    
    
};
#endif /* defined(__MyMoonWarrior__HeroBulletManager__) */
