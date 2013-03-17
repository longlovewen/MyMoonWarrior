//
//  EnemyManager.h
//  MyMoonWarrior
//  敌机的管理类

//
//  Created by cesc on 13-3-17.
//
//

#ifndef __MyMoonWarrior__EnemyManager__
#define __MyMoonWarrior__EnemyManager__

#include <iostream>

#include "BasicLayer.h"
#include "EnumAndStruct.h"

class EnemyManager : public BasicLayer {
    
    
public:
    
    
    
    CCArray* enemyArray;
    
public:
    
    EnemyManager();
    ~EnemyManager();

    virtual bool init();

    void setupViews();

    CREATE_FUNC( EnemyManager );

    void addEnemy( float t );


    CCSprite* getEnemy( char* type );

    CCArray* getEnemyArray(  );


};


#endif /* defined(__MyMoonWarrior__EnemyManager__) */
