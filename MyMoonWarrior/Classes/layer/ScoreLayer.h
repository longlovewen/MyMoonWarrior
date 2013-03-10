//
//  ScoreLayer.h
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#ifndef __MyMoonWarrior__ScoreLayer__
#define __MyMoonWarrior__ScoreLayer__


#include "BasicLayer.h"

class ScoreLayer: public BasicLayer {
    
    
public:
    ScoreLayer();
    ~ScoreLayer();
    
    virtual bool init();
    
    void setupViews();
    
    CREATE_FUNC( ScoreLayer );
    

    
};

#endif /* defined(__MyMoonWarrior__ScoreLayer__) */
