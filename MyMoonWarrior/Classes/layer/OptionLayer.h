//
//  OptionLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-4.
//
//

#ifndef __MyMoonWarrior__OptionLayer__
#define __MyMoonWarrior__OptionLayer__

#include "BasicLayer.h"

class OptionLayer : public BasicLayer
{
    
public:
    
public:
    OptionLayer();
    ~OptionLayer();
    
    virtual bool init();
    
    
    static CCScene* scene();
    
    CREATE_FUNC( OptionLayer );
    
    
    void setupViews();
    
    void back_callback( CCObject* pSender );
    
    
    void music_trigger_callback( CCObject* pSender );
    
};

#endif /* defined(__MyMoonWarrior__OptionLayer__) */
