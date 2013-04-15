//
//  Effects.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-4-14.
//
//

#include "Effects.h"

static Effects* instance = NULL;

Effects* Effects::sharedEffects(){

    if( !instance ){
    
        instance = new Effects();
    }
    
    
    return instance;
}

//   预加载动画到CCAnimationCache中
void Effects::preLoad(){
    
    //  将爆炸的plist 和 图片加入到cache中
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "explosion.plist" );
    
    //  创建一个CCAnimation
    CCAnimation* boomAnimation = CCAnimation::create();
    boomAnimation->setDelayPerUnit( 0.05f );
    boomAnimation->setLoops( 1 );
    
      //  将plist 中的所有图片加入到CCAnimation中
    for (int i = 1; i <= 35; i++ ) {
        
        char str[20] = {0};
        
        sprintf(str, "explosion_%02d.png",i );
        
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( str );
        
        boomAnimation->addSpriteFrame( pFrame );
        
    }
    
    
    //  将这个CCAnimation 指针加入到CCAnimationCache中
    
    CCAnimationCache::sharedAnimationCache()->addAnimation(boomAnimation, "boom" );
    

}

//  爆炸的效果
void Effects::boom( CCNode* target, CCPoint point ){
    
    CCSprite* sp = CCSprite::createWithSpriteFrameName( "explosion_01.png" );
    
    target->addChild( sp,10 );
    sp->setPosition( point );
    
    //  1.从CCanimationcache 中读取爆炸的animation
    CCAnimation* boomAnimation = CCAnimationCache::sharedAnimationCache()->animationByName( "boom" );
    
    CCAnimate* anim = CCAnimate::create( boomAnimation );
    
    //  2.写一个CCSequence 包含回调
    CCCallFuncN* callback = CCCallFuncN::create(sp, callfuncN_selector( Effects::boom_callback));
    
    CCAction* actions = CCSequence::create( anim,callback,NULL );
    
    sp->runAction( actions );
    
    
    
}

void Effects::boom_callback( CCNode* pNode ){

    pNode->removeFromParentAndCleanup( true );
}
