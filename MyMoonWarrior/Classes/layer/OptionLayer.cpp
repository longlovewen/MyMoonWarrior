//
//  OptionLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-4.
//
//

#include "OptionLayer.h"
#include "WelcomeLayer.h"

OptionLayer::OptionLayer(){}
OptionLayer::~OptionLayer(){}

bool OptionLayer::init(){
    
    bool sRect = false;
    
    do {
        
        CC_BREAK_IF( !BasicLayer::init());
        
        setupViews();
        
        sRect = true;
    } while (0 );

   
    return sRect;
    
}


//  对控件以及布景 进行初始化
void OptionLayer::setupViews(){
    
    //  加入背景图片
    
    setBackgroundImage( "loading.png" );
    
    //  加入menutitle
    CCSprite* title = CCSprite::create( "menuTitle.png",CCRectMake(0, 0, 133, 36) );
    
    title->setAnchorPoint( ccp(0.5, 1) );
    title->setPosition( ccp( getWinSize().width / 2 ,getWinSize().height -20 ) );
    this->addChild( title );
    
    //  加入menu-- 既是创建CCMenuItemToggle
    CCMenuItemToggle* music_trigger = CCMenuItemToggle::createWithTarget(this, menu_selector(OptionLayer::music_trigger_callback), CCMenuItemFont::create( "Music : On" ),CCMenuItemFont::create("Music : Off"),NULL);
    
    music_trigger->setPosition( ccp( getWinSize().width / 2 ,getWinSize().height / 2 ) );
    //  根据背景音乐播放与否来显示相关的文字选项
    
    if( SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying() )
    {
              
        music_trigger->setSelectedIndex( 1 );
        
    }
    else
    {
        music_trigger->setSelectedIndex( 0 );
        
    }
    
    //  创建后退的CCMenuItem
    CCLabelBMFont* fontOfBack = CCLabelBMFont::create("Go Back", "arial-14.fnt" );
    
    fontOfBack->setScale(1.5f);
    
    CCMenuItemLabel* backLabel = CCMenuItemLabel::create(fontOfBack, this, menu_selector(OptionLayer::back_callback));
    backLabel->setAnchorPoint( ccp( 0.5, 0 ) );
    backLabel->setPosition( ccp( getWinSize().width / 2, 30) );
    
    
    CCMenu* menu = CCMenu::create( music_trigger,backLabel,NULL);
    
    menu ->setPosition( CCPointZero );
//    menu->setPosition( ccp( getWinSize().width / 2, getWinSize().height /  2) );
    
    this->addChild( menu );
}


//  音乐开关的回调函数
void OptionLayer::music_trigger_callback( CCObject* pSender ){
    
    if( SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying() )
    {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        
        CCLOG(" Music is stopped now");
        CCUserDefault::sharedUserDefault()->setBoolForKey( "music_not_playing", true );
    }else
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        
         CCLOG(" Music is playing now");
        
        CCUserDefault::sharedUserDefault()->setBoolForKey( "music_not_playing", false );
    }
    
    

}


//  返回场景类的指针
CCScene* OptionLayer::scene(){

    CCScene* sc = NULL;
    
    do {
        
        sc = CCScene::create();
        
        CC_BREAK_IF( !sc );
        
        OptionLayer* layer = OptionLayer::create();
        
        CC_BREAK_IF( !layer );
        
        sc->addChild( layer );
        
    } while (0);



    return sc;
}



void OptionLayer::back_callback( CCObject* pSender ){

    CCDirector::sharedDirector()->popScene();

}