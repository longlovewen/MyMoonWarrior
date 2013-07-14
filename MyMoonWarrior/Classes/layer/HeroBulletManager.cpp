//
//  HeroBulletManager.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-14.
//
//

#include "HeroBulletManager.h"
#define OFFSIDE_HEIGHT 1200
#define OFFSIDE_WIDTH_LEFT -120
#define OFFSIDE_WIDTH_RIGHT 600
#include "GamingLayer.h"

#include "NewBullet.h"
#include "DLog.h"
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
void HeroBulletMananger::addNewBullet(const CCPoint point,const CCRect planeBox  ){
    
    
    //  飞机的左子弹
    NewBullet* bulletSprite = NewBullet::createWithSpriteFrameName( "W1.png" );
   
    CCRect bBox = bulletSprite->boundingBox();
    
    
    bulletSprite->setBulletTag( 1 );
    bulletSprite->setPosition( ccp( planeBox.getMinX(),planeBox.getMaxY())  );

    
    //  飞机的右子弹
    NewBullet* bullet2 = NewBullet::createWithSpriteFrameName( "W1.png" );
    
    bullet2->setPosition( ccp( planeBox.getMaxX(),planeBox.getMaxY())  );

    bullet2->setBulletTag( 3 );
    
    //  飞机的中间子弹
    NewBullet* bullet3 = NewBullet::createWithSpriteFrameName( "W1.png" );
    
    bullet3->setPosition( ccp( planeBox.getMidX(),  planeBox.getMaxY() ) );
    
    bullet3->setBulletTag( 2 );
    
    //  加入到数组中
    bulletsArray->addObject( bulletSprite );
    bulletsArray->addObject( bullet2 );
    bulletsArray->addObject( bullet3 );
    
    //  加入到BatchNode中
    mBulletsBatchNode->addChild( bulletSprite );
    mBulletsBatchNode->addChild( bullet2 );
    mBulletsBatchNode->addChild( bullet3 );
  
   
    
}


//  移动所有的子弹
void HeroBulletMananger::moveAllBullets( float t ){

    CCSize size = getWinSize();
    
    CCObject* obj = NULL;
    CCObject* oo = NULL;
    CCARRAY_FOREACH( bulletsArray, obj ){
    
        NewBullet* sp = ( NewBullet*)obj;
        
       
        
        //  todo  根据子弹的tag 来设定方向
        
        int bTag  = sp->getBulletTag();
        if (  bTag == 1 ) {
        
        //  角度转换成弧度
        float radius  =  CC_DEGREES_TO_RADIANS( 45 );
            
            float yspeed  =  sin( radius ) * 10 ;
            float xspeed = cos( radius )* 10;
            
            DLog::sharedDLog()->d( "xspeed:%f", xspeed );
            DLog::sharedDLog()->d( "yspeed:%f", yspeed );
             sp->setPositionY( sp->getPositionY() + yspeed );
            sp->setPositionX( sp->getPositionX() - 10 );
            
            sp->setRotation( 135);
            
        }else if( bTag == 2 ){
        
            sp->setPositionY( sp->getPositionY() + 10 );
        }else if( bTag == 3 ) {
            //  角度转换成弧度
            float radius  =  CC_DEGREES_TO_RADIANS( 45 );
        
            float yspeed  =  sin( radius ) * 10 ;
            float xspeed = cos( radius )* 10;
            
            DLog::sharedDLog()->d( "xspeed:%f", xspeed );
            DLog::sharedDLog()->d( "yspeed:%f", yspeed );
            sp->setPositionY( sp->getPositionY() + yspeed );
            sp->setPositionX( sp->getPositionX() + 10 );
            
            sp->setRotation( 45);

        }
        
  
        
        //  如果出边界则移除子弹，否则进行判断
        if( sp->getPositionY() > OFFSIDE_HEIGHT || sp->getPositionX() < OFFSIDE_WIDTH_LEFT || sp->getPositionX() > OFFSIDE_WIDTH_RIGHT ){
        
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
