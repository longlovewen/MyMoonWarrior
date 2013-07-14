//
//  WarriorLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-14.
//
//

#ifndef __MyMoonWarrior__WarriorLayer__
#define __MyMoonWarrior__WarriorLayer__

#include <iostream>
#include "BasicLayer.h"

class WarriorLayer: public BasicLayer {
    
    
public:
    WarriorLayer();
    ~WarriorLayer();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( WarriorLayer );

 virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

    virtual void registerWithTouchDispatcher(void);


    CCPoint getHeroPosition();

    CCSize getHeroSize();

    void setEnabledTouch( bool flag );
    
    
public:
    CCSprite* m_warrior;


};

#endif /* defined(__MyMoonWarrior__WarriorLayer__) */
