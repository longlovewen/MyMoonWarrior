//
//  TimerLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#ifndef __MyMoonWarrior__TimerLayer__
#define __MyMoonWarrior__TimerLayer__

#include <iostream>
#include "BasicLayer.h"



class TimerLayer: public BasicLayer {
    
    
public:
    TimerLayer();
    ~TimerLayer();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( TimerLayer );
    
    
    void time_counting_down( float t );
    
private:
    int counter;
    
};

#endif /* defined(__MyMoonWarrior__TimerLayer__) */
