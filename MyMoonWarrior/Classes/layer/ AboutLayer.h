//
//   AboutLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-2.
//
//

#ifndef __MyMoonWarrior___AboutLayer__
#define __MyMoonWarrior___AboutLayer__

#include "BasicLayer.h"

class AboutLayer : public BasicLayer
{
    
public:
    
public:
    AboutLayer();
    ~AboutLayer();
    
    virtual bool init();
    
    
    static CCScene* scene();
    
    CREATE_FUNC( AboutLayer );
    
    
    void setupViews();
    
    void back_callback( CCObject* pSender );
   
    
};

#endif /* defined(__MyMoonWarrior___AboutLayer__) */
