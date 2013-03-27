//
//  EnemyManager.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-27.
//
//

#ifndef __MyMoonWarrior__EnemyManager__
#define __MyMoonWarrior__EnemyManager__

#include <iostream>


#include "BasicLayer.h"
#include "EnumAndStruct.h"

class EnemyManager : public BasicLayer {
    
    
public:
    
    
    //  敌机的管理的数组
    CCArray* enemyArray;
    
public:
    
    EnemyManager();
    ~EnemyManager();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( EnemyManager );
    
    
    void addEnemy( float t );
    
    
    CCArray* getEnemyArray(  );
    
    
};


#endif /* defined(__MyMoonWarrior__EnemyManager__) */
