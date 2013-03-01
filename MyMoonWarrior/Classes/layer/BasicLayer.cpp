//
//  BasicLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#include "BasicLayer.h"



BasicLayer::BasicLayer(){}
BasicLayer::~BasicLayer(){}


//  初始化方法
bool BasicLayer::init(){
    
    bool sRect = false;
    
    do {
        CC_BREAK_IF( !CCLayer::init() );
        
        sRect = true;
    } while ( 0 );
    
    return sRect;
}


//  获取屏幕大小的方法
CCSize BasicLayer::getWinSize(){

    
    return CCDirector::sharedDirector()->getWinSize();
}



//  设置背景图片的方法
void BasicLayer::setBackgroundImage( const char* back_image_name ){
    
    CCSprite* sp = CCSprite::create( back_image_name );
    sp->setPosition( ccp( getWinSize().width / 2 , getWinSize().height / 2 ) );
    this->addChild( sp );
    
}