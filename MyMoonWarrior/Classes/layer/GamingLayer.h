//
//  GamingLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#ifndef __MyMoonWarrior__GamingLayer__
#define __MyMoonWarrior__GamingLayer__

#include <iostream>
#include "BasicLayer.h"

class GamingLayer: public BasicLayer {
    
    
public:
    GamingLayer();
    ~GamingLayer();
    
    virtual bool init();
    
    
    static CCScene* scene();
    
    CREATE_FUNC( GamingLayer );
    
    void setupViews();
    
    void background_scroll_logic( float t );
    
    void pause_logic( CCObject* pSender );
};

#endif /* defined(__MyMoonWarrior__GamingLayer__) */
