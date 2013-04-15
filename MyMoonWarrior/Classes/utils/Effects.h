//
//  Effects.h
//  MyMoonWarrior
//
//  Created by cesc on 13-4-14.
//
//

#ifndef __MyMoonWarrior__Effects__
#define __MyMoonWarrior__Effects__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Effects {
    
    
public:
    
    static Effects* sharedEffects();
    
    //   预加载动画到CCAnimationCache中
    void preLoad();
    
    void boom( CCNode* target, CCPoint point );
    
    void boom_callback( CCNode* pNode );
    

};
#endif /* defined(__MyMoonWarrior__Effects__) */
