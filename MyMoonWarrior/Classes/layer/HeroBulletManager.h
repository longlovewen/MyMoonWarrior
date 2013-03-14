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

class HeroBulletMananger: public BasicLayer {
    
    
public:
    
    
    
    HeroBulletMananger();
    ~HeroBulletMananger();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( HeroBulletMananger );
    
    void addNewBullet( const CCPoint point,const CCSize flySize  );
    
    void moveAllBullets( float t );
    
    
private:
    CCSpriteBatchNode* mBulletsBatchNode;
    CCArray* bulletsArray;
    
    
    
    
private:
    CCSprite* m_warrior;
    
    
};
#endif /* defined(__MyMoonWarrior__HeroBulletManager__) */
