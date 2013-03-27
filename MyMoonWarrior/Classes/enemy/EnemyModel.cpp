//
//  EnemyModel.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-27.
//
//

#include "EnemyModel.h"


EnemyModel::EnemyModel( Monster mMonster,CCPoint targetPoint  ){

       
    //  构造函数中的作用是根据传入的枚举来加载不同的飞机图片 和 不同的CCAction

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    switch ( mMonster) {
        case monster1:
            
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster1.png" );
            
            m_action = CCMoveTo::create( 1.0f, targetPoint );
                                        
            
            
            
            break;
        case monster2:
            
           m_sprite = CCSprite::createWithSpriteFrameName( "Monster2.png" );
            
            break;
        case monster3:
           m_sprite = CCSprite::createWithSpriteFrameName( "Monster3.png" );
            break;
        case monster4:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster4.png" );
            break;
        case monster5:
            
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster5.png" );
            
            break;
            
        case monster6:
            
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster6.png" );
            
            break;
        default:
            break;
    }

}
EnemyModel::~EnemyModel(){}

bool EnemyModel::init(){
    
    //  初始化子弹数组
    bulletArray = CCArray::create();
    bulletArray->retain();
 

    
    
    //  1.将子弹的plist 文件加入到CCSpriteFrameCache 中
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist", "bullet.png" );
    
    
    //  2.读取其中敌机的子弹然后加入到CCSpriteBatchNode中
    
    enemyBulletBatchNode = CCSpriteBatchNode::create( "bullet.png" );
    
    //  3.为CCSpritBatchNode 加入光晕效果
    ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
    
    enemyBulletBatchNode->setBlendFunc( cb );
    
    this->addChild( enemyBulletBatchNode );
    
    
    //  设置飞机CCsprite的位置胃0
    m_sprite->setPosition( CCPointZero );
    this->addChild( m_sprite );
    //  执行动画
    m_sprite->runAction( m_action  );
    
    //  执行加入子弹和移动子弹的schedule
    this->schedule( schedule_selector( EnemyModel::addNewBullet),0.1f );
    this->schedule( schedule_selector( EnemyModel::moveBullet),0.015f );
    
        
    return true;
}


EnemyModel* EnemyModel::getEnemey( Monster mMonster,CCPoint targetPoint  ){

    
    EnemyModel* model = new EnemyModel( mMonster,targetPoint );
    
    
    
    if( model && model->init()){
    
    
        model->autorelease();
        
        return  model;
    }
    
    
    CC_SAFE_DELETE( model );
    return NULL;
}

void EnemyModel::addNewBullet( float t ){
    
    CCSprite* sp = CCSprite::createWithSpriteFrameName( "W1.png" );
    
    sp->setPosition(  m_sprite->getPosition() );

    
    enemyBulletBatchNode->addChild( sp );
    
    bulletArray->addObject( sp );
    
    
    
}

void EnemyModel::moveBullet( float t ){
    
    CCObject* obj = NULL;
    
    CCARRAY_FOREACH( bulletArray, obj){
        
        CCSprite* sp = ( CCSprite* )obj;
        
    
        sp->setPositionY( sp->getPositionY() - 10 );
        
        if( sp->getPositionY() <= -200){
        
            bulletArray->removeObject( obj );
            
            enemyBulletBatchNode->removeChild( sp, true );
        }
        
    }

}