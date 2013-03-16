//
//  PauseLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "PauseLayer.h"
#include "GamingLayer.h"

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
        
        resumeItem->setPosition( ccp( size.width / 2, size.height / 2  ));
        
        
        CCMenu* menu = CCMenu::create( resumeItem, NULL );
        
        menu->setPosition( CCPointZero );
        
        this->addChild( menu );
        
      
        
        
    } while (0);

}

//  恢复逻辑
void PauseLayer::play_logic( CCObject* pSender){
    
    
    CCLOG("点击恢复");
    GamingLayer* fatherNode = (GamingLayer*)getParent();   

    
    //  1. 将这个暂停层进行移植
    fatherNode->removeChildByTag( 99, true );
    
    // 2. 设定CCMenu(父节点中)enable 为true
    CCMenu* menu = (CCMenu*) fatherNode->getChildByTag( 156 );
    menu->setEnabled( true );
    
    fatherNode->mWarrior->setTouchEnabled( true );
    
    // 3.调用 CCDirector 的 resume 方法
    CCDirector::sharedDirector()->resume();
    
    // 4.恢复背景音乐
    
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    
    
    
    setTouchEnabled( true );
    

}


bool PauseLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){

    return true;
}

void PauseLayer::registerWithTouchDispatcher(void){    
 
    
        CCLayer::registerWithTouchDispatcher();
    
    
       CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,std::numeric_limits <int> ::min() ,true	);
    
}

