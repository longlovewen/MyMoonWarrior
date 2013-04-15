//
//  HeroBulletManager.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-14.
//
//

#include "HeroBulletManager.h"
#define OFFSIDE_HEIGHT 1200
#include "GamingLayer.h"

#include "EnemyModel.h"
HeroBulletMananger::HeroBulletMananger(){}
HeroBulletMananger::~HeroBulletMananger(){}

bool HeroBulletMananger::init(){

    if( !BasicLayer::init()){
        
        return false;
    }
    
    setupViews();
    return true;
}

void HeroBulletMananger::setupViews(){

    do {
        
        //  1.将子弹的plist 文件加入到CCSpriteFrameCache 中
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist", "bullet.png" );
        
        
        //  2.读取其中英雄的子弹然后加入到CCSpriteBatchNode中
        
        mBulletsBatchNode = CCSpriteBatchNode::create( "bullet.png" );
        
        //  3.为CCSpritBatchNode 加入光晕效果
        ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
        
        mBulletsBatchNode->setBlendFunc( cb );
        
        this->addChild(mBulletsBatchNode );
        
        //  4.初始化数组
        bulletsArray = CCArray::create();
        bulletsArray->retain();
        
      
        this->schedule( schedule_selector( HeroBulletMananger::moveAllBullets),0.015f );
        
        
        //  5.预加载特效类 和 爆炸动画
        Effects::sharedEffects()->preLoad();
        
    } while ( 0 );
     
    
}

//  添加子弹 -- 对外的 其实就是对WarriorLayer
void HeroBulletMananger::addNewBullet(const CCPoint point,const CCSize flySize ){
    
    
    //  飞机的左子弹
    CCSprite* bulletSprite = CCSprite::createWithSpriteFrameName( "W1.png" );
   
        
    bulletSprite->setPosition( ccp( point.x - flySize.width / 4 , point.y + flySize.height / 2  )  );

    
    //  飞机的右子弹
    CCSprite* bullet2 = CCSprite::createWithSpriteFrameName( "W1.png" );
    
    bullet2->setPosition( ccp( point.x + flySize.width / 4 , point.y + flySize.height / 2  )  );

    
    //  加入到数组中
    bulletsArray->addObject( bulletSprite );
    bulletsArray->addObject( bullet2 );

    //  加入到BatchNode中
    mBulletsBatchNode->addChild( bulletSprite );
    mBulletsBatchNode->addChild( bullet2 );
  
   
    
}


//  移动所有的子弹
void HeroBulletMananger::moveAllBullets( float t ){

    CCSize size = getWinSize();
    
    CCObject* obj = NULL;
    CCObject* oo = NULL;
    CCARRAY_FOREACH( bulletsArray, obj ){
    
        CCSprite* sp = ( CCSprite*)obj;
        
        sp->setPositionY( sp->getPositionY() + 10 );
        
        //  如果出边界则移除子弹，否则进行判断
        if( sp->getPositionY() > OFFSIDE_HEIGHT){
        
            mBulletsBatchNode->removeChild( sp , true );
            
            bulletsArray->removeObject( sp );
        }else{
        
            GamingLayer* father  = (GamingLayer*)this->getParent();
            CCArray* eArr = father->mEnemyManager->getEnemyArray();
            
            
            CCARRAY_FOREACH(eArr, oo ){
               
                
                EnemyModel* model = (EnemyModel*)oo;
                
                
                
                if( sp->boundingBox().containsPoint( model->getPosition())){
                   
                    Effects::sharedEffects()->boom( this->getParent(), model->getPosition() );
                    
                    
                }
                
            }
           
        }
            
            
            
    
    }

}
