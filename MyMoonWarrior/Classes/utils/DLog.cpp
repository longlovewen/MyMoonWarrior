//
//  DLog.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "DLog.h"

DLog::DLog(){}
DLog::~DLog(){}


//  显示字符串log
void DLog::d( const char* content ){
    
    if( flag ){
        CCLOG( "Log==>%s", content  );
    }

    
}