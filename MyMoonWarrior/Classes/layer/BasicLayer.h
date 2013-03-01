//
//  BasicLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#ifndef __MyMoonWarrior__BasicLayer__
#define __MyMoonWarrior__BasicLayer__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class BasicLayer : public CCLayer{
    
public:
    BasicLayer();
    ~BasicLayer();
    
    virtual bool init();
    
    
    CCSize getWinSize();
    
    CREATE_FUNC( BasicLayer );
    
void setBackgroundImage( const char* back_image_name );

    

};

#endif /* defined(__MyMoonWarrior__BasicLayer__) */
