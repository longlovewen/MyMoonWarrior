//
//  CescMenu.h
//  MyMoonWarrior
//
//  Created by cesc on 13-7-14.
//
//

#ifndef __MyMoonWarrior__CescMenu__
#define __MyMoonWarrior__CescMenu__

#include "cocos2d.h"
USING_NS_CC;

class CescMenu : public CCMenu {
    
    
public:
   
    
    /** creates a CCMenu with it's items */
    static CescMenu* create(CCMenuItem* item, ...);
    
    /** initializes a CCMenu with it's items */
    bool initWithItems(CCMenuItem* item, va_list args);
    void registerWithTouchDispatcher();
};

#endif /* defined(__MyMoonWarrior__CescMenu__) */
