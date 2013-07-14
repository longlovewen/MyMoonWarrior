//
//  PauseLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#ifndef __MyMoonWarrior__PauseLayer__
#define __MyMoonWarrior__PauseLayer__

#include "BasicLayer.h"


//  暂停布景
class  PauseLayer: public CCLayerColor {
    
    
public:
    PauseLayer();
    ~PauseLayer();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( PauseLayer );
    
    virtual void registerWithTouchDispatcher(void);

   
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    

    
    void play_logic( CCObject* pSender);

    void to_cover_logic( CCObject* psender );
    
    
};


#endif /* defined(__MyMoonWarrior__PauseLayer__) */
