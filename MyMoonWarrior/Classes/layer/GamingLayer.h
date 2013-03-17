//
//  GamingLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#ifndef __MyMoonWarrior__GamingLayer__
#define __MyMoonWarrior__GamingLayer__

#include <iostream>
#include "BasicLayer.h"
#include "WarriorLayer.h"
#include "HeroBulletManager.h"
#include "EnemyManager.h"


class GamingLayer: public BasicLayer {
    
    
public:
    GamingLayer();
    ~GamingLayer();
    
    virtual bool init();
    
    
    static CCScene* scene();
    
    CREATE_FUNC( GamingLayer );
    
    void setupViews();
    
    void background_scroll_logic( float t );
    
    void pause_logic( CCObject* pSender );
    
    void warrior_add_new_bullet( float t );
    
     WarriorLayer* mWarrior;

    EnemyManager* mEnemyManager;

    
    HeroBulletMananger* mHeroBulletManager;
};

#endif /* defined(__MyMoonWarrior__GamingLayer__) */
