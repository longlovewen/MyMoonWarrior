//
//   AboutLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#include " AboutLayer.h"

#include "WelcomeLayer.h"
AboutLayer::AboutLayer(){}
AboutLayer::~AboutLayer(){}

bool AboutLayer::init(){


    bool sRect = false;
    
    do {
        CC_BREAK_IF( !BasicLayer::init() );
        
        
        setupViews();
        
        
        sRect = true;
    } while (0);
    
    
    return sRect;
}


CCScene* AboutLayer::scene(){
    
    CCScene* sc = NULL;
    
    do {
        sc = CCScene::create();
        
        CC_BREAK_IF( !sc );
        
        AboutLayer* layer = AboutLayer::create();
        CC_BREAK_IF( !layer );
        
        sc->addChild( layer );
    } while (0);
    
    return sc;
}




void AboutLayer::setupViews(){

    setBackgroundImage( "loading.png" );
    
    //  加入title
    CCSprite* title = CCSprite::create( "menuTitle.png",CCRectMake(0, 34, 130, 38) );
    
    title->setAnchorPoint( ccp(0.5, 1) );
    title->setPosition( ccp( getWinSize().width / 2 ,getWinSize().height -20 ) );
    this->addChild( title );
    //  加入文字说明
    
    CCLabelBMFont* pDes = CCLabelBMFont::create( "This Game is recoded by longlingxiu ", "arial-14.fnt" );
    
    pDes->setPosition( ccp(getWinSize().width / 2, getWinSize().height / 2) );
    
    this ->addChild(pDes);
    
    
    
    CCLabelBMFont* fontOfBack = CCLabelBMFont::create("Go Back", "arial-14.fnt" );
    
    fontOfBack->setScale(1.5f);
    
    CCMenuItemLabel* backLabel = CCMenuItemLabel::create(fontOfBack, this, menu_selector(AboutLayer::back_callback));
    backLabel->setAnchorPoint( ccp( 0.5, 0 ) );
    backLabel->setPosition( ccp( getWinSize().width / 2, 30) );
    
    CCMenu* menu = CCMenu::create( backLabel, NULL );;
    menu->setPosition( CCPointZero );
    
    this->addChild( menu );
    
}

void AboutLayer::back_callback( CCObject* pSender ){

    CCDirector::sharedDirector()->popScene();
}
