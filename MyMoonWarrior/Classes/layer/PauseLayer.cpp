//
//  PauseLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "PauseLayer.h"
#include "GamingLayer.h"
#include "DLog.h"
#include "CescMenu.h"

PauseLayer::PauseLayer(){}
PauseLayer::~PauseLayer(){}

bool PauseLayer::init(){

    if (!CCLayerColor::initWithColor(ccc4(0 , 0, 0, 50)) ) {
    
        return false;
        
    }

    setupViews();
    
    return true;
}

void PauseLayer::setupViews(){
    
    do {

        //   创建menu
        
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        
        CCMenuItemImage* resumeItem = CCMenuItemImage::create("play.png", "play.png", this, menu_selector(PauseLayer::play_logic));
        
        CCMenuItemImage* toCoverItem = CCMenuItemImage::create( "Icon.png", "Icon.png",this,menu_selector( PauseLayer::to_cover_logic ));
        
        
        
        
        CescMenu* menu = CescMenu::create( resumeItem,toCoverItem, NULL );
        menu->alignItemsVerticallyWithPadding( 10 );
        menu->setPosition( ccp( size.width / 2, size.height / 2  ));
        
        this->addChild( menu );
        
        this->setTouchEnabled( true );
        
        
    } while (0);

}

void PauseLayer::to_cover_logic(cocos2d::CCObject *pSender){

    //  todo 调用gameworld 的返回菜单的逻辑
    
    DLog::sharedDLog()->d( "返回主菜单" );
    
    GamingLayer* father =   (GamingLayer*)this->getParent();
    
    father->to_cover_logic();
    
    this->removeFromParentAndCleanup( true );
}

//  恢复逻辑
void PauseLayer::play_logic( CCObject* pSender){
    
    
    this->removeFromParentAndCleanup( true );

    CCDirector::sharedDirector()->resume();
    
    
    DLog::sharedDLog()->d( "恢复游戏" );
    

}


bool PauseLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){

    return true;
}

void PauseLayer::registerWithTouchDispatcher(void){    
 
    
        CCLayer::registerWithTouchDispatcher();
    
    
       CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-129 ,true	);
    
}

