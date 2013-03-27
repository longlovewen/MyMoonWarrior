//
//  EnemyModel.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-27.
//
//

#ifndef __MyMoonWarrior__EnemyModel__
#define __MyMoonWarrior__EnemyModel__

#include <iostream>
#include "cocos2d.h"
#include "EnumAndStruct.h"
USING_NS_CC;

class EnemyModel : public CCNode {
    
    
public:
    
    //  构造函数
    EnemyModel( Monster mMonster,CCPoint targetPoint   );
    ~EnemyModel();
    
    bool init();
    
    
    //  静态的获取敌机指针的函数
    static EnemyModel* getEnemey( Monster mMonster,CCPoint targetPoint );
    
    
    //  添加子弹的函数
    void addNewBullet( float t );
    
    //  移动子弹的函数
    void moveBullet( float t );
    
public:
    
    CCSpriteBatchNode* enemyBulletBatchNode;    //  敌机子弹的batchNode
    
    CCArray* bulletArray;   //  敌机子弹的数组
    
private:

    CCAction*  m_action;
    CCSprite*  m_sprite;
    
    

    
    
    
    
    
    
};

#endif /* defined(__MyMoonWarrior__EnemyModel__) */
