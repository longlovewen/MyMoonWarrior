//
//  WelcomeLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#include "WelcomeLayer.h"

#include " AboutLayer.h"

WelcomeLayer::WelcomeLayer(){}

WelcomeLayer::~WelcomeLayer(){}

//  初始化方法
bool WelcomeLayer::init(){
    bool sRect = false;
    
    do {
        CC_BREAK_IF( !BasicLayer::init() );
        
        
        setupViews();
        
        
        sRect = true;
    } while (0);
    
    
    return sRect;
}

//  初始化控件
void WelcomeLayer::setupViews(){

     setBackgroundImage("loading.png");
    
    
    
    //  加入Logo
    CCSprite* pLogo = CCSprite::create( "logo.png" );
    pLogo->setAnchorPoint( ccp( 0.5, 1) );
    pLogo->setPosition( ccp( getWinSize().width / 2 ,getWinSize().height - 20 ) );
    
    this->addChild( pLogo );
    
    //  加入菜单项
    //  第一步：加入开始菜单
    CCSprite* pStartNormal = CCSprite::create( "menu.png" ,CCRectMake(0, 0, 126, 33));
    CCSprite* pStartPressed = CCSprite::create( "menu.png" ,CCRectMake(0, 33, 126, 33));
    CCSprite* pStartDisabled = CCSprite::create( "menu.png" ,CCRectMake(0, 66, 126, 33));
    
    CCMenuItemSprite* startGame = CCMenuItemSprite::create(pStartNormal, pStartPressed, pStartDisabled, this, menu_selector(WelcomeLayer::startgame_callback));
    
    //  第二步：加入关于菜单
    
    CCSprite* pAboutNormal = CCSprite::create( "menu.png" ,CCRectMake(252, 0, 126, 33));
    CCSprite* pAboutPressed = CCSprite::create( "menu.png" ,CCRectMake(252, 33, 126, 33));
    CCSprite* pAboutDisabled = CCSprite::create( "menu.png" ,CCRectMake(252, 66, 126, 33));
    
    CCMenuItemSprite* aboutGame = CCMenuItemSprite::create(pAboutNormal, pAboutPressed, pAboutDisabled, this, menu_selector(WelcomeLayer::about_callback ));
    
    //  第三部：加入选项菜单
    CCSprite* pOptionNormal = CCSprite::create( "menu.png" ,CCRectMake(126, 0, 126, 33));
    CCSprite* pOptionPressed = CCSprite::create( "menu.png" ,CCRectMake(126, 33, 126, 33));
    CCSprite* pOptionDisabled = CCSprite::create( "menu.png" ,CCRectMake(126, 66, 126, 33));
    
    CCMenuItemSprite* optionGame = CCMenuItemSprite::create(pOptionNormal, pOptionPressed, pOptionDisabled, this, menu_selector(WelcomeLayer::option_callback));
    
    //  创建菜单
    CCMenu* pMenu = CCMenu::create( startGame,optionGame,aboutGame,NULL);
    pMenu->setPosition( ccp(getWinSize().width / 2 ,getWinSize().height / 2 - 20 ) );
    pMenu->alignItemsVerticallyWithPadding( 10 );
    
    this->addChild( pMenu );
    

}


//  获取场景指针
CCScene* WelcomeLayer::scene(){

    CCScene* sc = NULL;
    
    do {
        sc = CCScene::create();
        
        CC_BREAK_IF( !sc );
        
        WelcomeLayer* layer = WelcomeLayer::create();
        CC_BREAK_IF( !layer );
        
        sc->addChild( layer );
    } while (0);

    return sc;
}

void WelcomeLayer::startgame_callback( CCObject* pSender ){

    CCLOG( "start game ");
   
}
void WelcomeLayer::option_callback( CCObject* pSender ){

        CCLOG( " option game ");

}
void WelcomeLayer::about_callback( CCObject* pSender ){
        CCLOG( "about game ");
    
    CCDirector::sharedDirector()->pushScene( CCTransitionFade::create( 0.5f, AboutLayer::scene()));
}
