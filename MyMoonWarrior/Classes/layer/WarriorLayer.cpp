//
//  WarriorLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-14.
//
//

#include "WarriorLayer.h"


WarriorLayer::WarriorLayer(){}
WarriorLayer::~WarriorLayer(){

    m_warrior = NULL;
}

bool WarriorLayer::init(){
    
    
    if( !BasicLayer::init()){
        
        
        return false;
    }
    
    setupViews();
    
    return true;
}

void WarriorLayer::setupViews(){

    
    do {
        
        //1. 创建一个精灵 也就是主角

        m_warrior = CCSprite::create( "ship01.png", CCRectMake(60, 0, 60, 43));
        
        m_warrior->setPosition( ccp( getWinSize().width / 2, getWinSize().height / 2 ) );
        this->addChild( m_warrior );
        
        
        //2.为主角添加动画
        
        CCAnimation* animation = CCAnimation::create();
        animation->setDelayPerUnit( 0.1f );
        
        animation->addSpriteFrame( CCSpriteFrame::create( "ship01.png", CCRectMake(60, 0, 60, 43) ) );
        
        animation->addSpriteFrame( CCSpriteFrame::create( "ship01.png", CCRectMake(0, 0, 60, 43) ) );
        
        CCAnimate* animate = CCAnimate::create( animation );
        
        m_warrior->runAction( CCRepeatForever::create( animate ));
        
        
        
        //  设定setTouchEnabled 为true  !!!!
        this->setTouchEnabled( true );
    } while (0);
}


bool WarriorLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    
    
    CCMoveTo* moveToAction = CCMoveTo::create(0.2f, pTouch->getLocation() );
    
    m_warrior->runAction( moveToAction );
    m_warrior->setPosition( pTouch->getLocation() );
    
    
    //  修改为返回false  如果为true 则PauseLayer 的CCMenu 获取不到点击事件
    return false;
}

void WarriorLayer::registerWithTouchDispatcher(void){
    

    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true	);
    
    
    
}

//  获取当前精灵的坐标
CCPoint WarriorLayer::getHeroPosition(){

    return m_warrior->getPosition();
}

CCSize WarriorLayer::getHeroSize(){

    return m_warrior->getContentSize();
}

void WarriorLayer::setEnabledTouch( bool flag ){

    this->setEnabledTouch( flag );

}
