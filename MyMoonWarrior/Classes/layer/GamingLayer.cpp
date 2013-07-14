//
//  GamingLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "GamingLayer.h"
#include "ScoreLayer.h"
#include "TimerLayer.h"
#include "PauseLayer.h"
#include "DLog.h"
#include "WelcomeLayer.h"


GamingLayer::GamingLayer(){
    
    m_pauseLayer = PauseLayer::create();
    
    CC_SAFE_RETAIN( m_pauseLayer );

}
GamingLayer::~GamingLayer(){

    
    CC_SAFE_RELEASE_NULL( m_pauseLayer );
}

bool GamingLayer::init(){
    
    if( !BasicLayer::init() ){
        return false;
    }
    
    

    setupViews();
    
    DLog::sharedDLog()->d( "初始化游戏场景" );
    
    return true;

}


void GamingLayer::to_cover_logic(){

    //  todo 等待修改pauselayer的加载方式之后再添加
    
    CCDirector::sharedDirector()->resume();
    
    CCDirector::sharedDirector()->replaceScene( CCTransitionFade::create(1.0f, WelcomeLayer::scene()));
    
    
}

//  初始化控件和布景
void GamingLayer::setupViews(){

    do {
        
        CCSprite* bg1 = CCSprite::create( "bg01.jpg" );
        CCSprite* bg2 = CCSprite::create( "bg01.jpg" );
        
        
        bg1->setAnchorPoint( CCPointZero );
        bg2->setAnchorPoint( CCPointZero );
        
        bg1->setPosition( CCPointZero );
        bg2->setPosition( ccp(0,576) );
        
        
        //this->addChild( bg1,0,11 );
       // this->addChild( bg2,0,12 );
        
        
        //  背景滚动的schedule方法
       // this->schedule( schedule_selector( GamingLayer::background_scroll_logic),0.1f );
        
        //  加入分数布景        
        ScoreLayer* score_layer = ScoreLayer::create();
        score_layer->setAnchorPoint( ccp(0,1));
        score_layer->setPosition( ccp(10,getWinSize().height -20) );
        
        
        this->addChild( score_layer );
        
        
        //  加入计时的布景
        TimerLayer* timer_layer = TimerLayer::create();
        timer_layer->setAnchorPoint( ccp(0,1));
        timer_layer->setPosition( ccp( getWinSize().width - timer_layer->getContentSize().width / 4 -20,getWinSize().height -20) );
        
        this->addChild( timer_layer );
        
        
        //  创建暂停按钮 和 CCMenu
        CCMenuItemImage* pauseItem = CCMenuItemImage::create( "pause.png", "pause.png", this, menu_selector(GamingLayer::pause_logic));
        pauseItem->setPosition( ccp( getWinSize().width - pauseItem->getContentSize().width-20 , pauseItem->getContentSize().height + 5 ) );
        pauseItem->setAnchorPoint( ccp(0,1 ) );
        
        CCMenu* menu = CCMenu::create( pauseItem, NULL );
        menu->setPosition( CCPointZero );
        
        this->addChild( menu,1,156 );
        
      
        
        mEnemyManager = EnemyManager::create();
        
        this->addChild( mEnemyManager,1 );
        
        
        
        //  初始化飞机类
        mWarrior = WarriorLayer::create();
        
        this->addChild(mWarrior ,1);
        
        mHeroBulletManager = HeroBulletMananger::create();
         this->addChild(mHeroBulletManager,1);
        
        
         
        
        //  移动英雄子弹的schedule
        this->schedule( schedule_selector( GamingLayer::warrior_add_new_bullet),0.05f );
        
        
        
        //  加入敌机
        mEnemyManager = EnemyManager::create();
        this->addChild( mEnemyManager , 1 );
        
     
        
        
    } while ( 0 );
}

void GamingLayer::warrior_add_new_bullet( float t ){

    mHeroBulletManager->addNewBullet( mWarrior->getHeroPosition(),mWarrior->m_warrior->boundingBox());
}



//  暂停逻辑
void GamingLayer::pause_logic( CCObject* pSender ){
    
    this->addChild( m_pauseLayer,99,99 );

    CCDirector::sharedDirector()->pause();    


}


//  背景滚动逻辑回调方法
void GamingLayer::background_scroll_logic( float t ){
    
    CCSprite* bg1 = (CCSprite*)getChildByTag( 11 );
    CCSprite* bg2 = (CCSprite*)getChildByTag( 12 );

    bg1->setPositionY( bg1->getPositionY() - 10 );
    bg2->setPositionY( bg1->getPositionY() + 576  );
    
    if( bg2->getPositionY() <= 0 ){
        
        bg1->setPositionY( 0 );
    }
    
}

//  返回场景的指针
CCScene* GamingLayer::scene(){
    CCScene* sc = NULL;
    
    do {
        sc = CCScene::create();
        
        CC_BREAK_IF( !sc );
        
        GamingLayer* layer = GamingLayer::create();
        
        CC_BREAK_IF( !layer );
        
        sc->addChild( layer );
    } while (0);
    
    
    return sc;
}


