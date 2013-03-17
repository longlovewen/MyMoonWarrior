//
//  EnemyManager.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-17.
//
//

/*
 
 1.创建一个敌人随机的图片随机的其实位置  加入的CCArray （这个CCArray要实现设定好个数）
 2.敌人能移动
 
 */

#include "EnemyManager.h"


EnemyManager::EnemyManager(){}
EnemyManager::~EnemyManager(){
    
    CC_SAFE_DELETE_ARRAY( enemyArray );

}

bool EnemyManager::init(){

    if(!BasicLayer::init()){
        return false;
    }
    
    //  创建长度为5的敌机
    enemyArray = CCArray::createWithCapacity( 6 );
    enemyArray->retain();
    
    setupViews();
    
    return true;
}

void EnemyManager::setupViews(){

    do {
        //  加入的plist
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "Monster.plist", "Monster.png" );
        
        addEnemy( 1 );
        
    } while (0);
}

//  添加敌人的方法
void EnemyManager::addEnemy( float t ){

  
    
    
    
    
    
    
    
}




//  获得敌机
CCSprite* EnemyManager::getEnemy( char* type ){
    
    CCSprite* sprite = NULL;
    
    if( type == "1" ){
        
        
        sprite = CCSprite::createWithSpriteFrameName( "Monster1.png");
    
    }else if( type == "2" ){
        
         sprite = CCSprite::createWithSpriteFrameName( "Monster2.png");
    
    }else if( type == "3"){
    
         sprite = CCSprite::createWithSpriteFrameName( "Monster3.png");
    }else if( type == "4"){
        
        sprite = CCSprite::createWithSpriteFrameName( "Monster4.png");
    }else if( type == "5"){
        
        sprite = CCSprite::createWithSpriteFrameName( "Monster5.png");
    }else if( type == "6"){
        
        sprite = CCSprite::createWithSpriteFrameName( "Monster3.png");
    }



    
       return sprite;

}


//  返回敌人的数组
CCArray* EnemyManager::getEnemyArray(){
    
    return enemyArray;
}


