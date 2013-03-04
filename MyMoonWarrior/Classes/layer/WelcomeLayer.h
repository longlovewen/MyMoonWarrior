//
//  WelcomeLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#ifndef __MyMoonWarrior__WelcomeLayer__
#define __MyMoonWarrior__WelcomeLayer__

#include <iostream>
#include "BasicLayer.h"

class WelcomeLayer : public BasicLayer
{

public:
    WelcomeLayer();
    ~WelcomeLayer();
    
    virtual bool init();    
   
    
    static CCScene* scene();
    
    CREATE_FUNC( WelcomeLayer );
    
    
  
    void setupViews();
    
    void startgame_callback( CCObject* pSender );
    void option_callback( CCObject* pSender );
    void about_callback( CCObject* pSender );
    
    virtual void onEnter();
    
    
    
};
#endif /* defined(__MyMoonWarrior__WelcomeLayer__) */
