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
void DLog::d( const char * pszFormat, ...){
    
    if( flag ){
        printf("龙灵修的Log: ");
        char szBuf[kMaxLogLen];
        
        va_list ap;
        va_start(ap, pszFormat);
        vsnprintf(szBuf, kMaxLogLen, pszFormat, ap);
        va_end(ap);
        printf("%s", szBuf);
        printf("\n");
    }

    
}

static DLog* instance = NULL;
DLog* DLog::sharedDLog(){

    if (!instance ) {
        
        instance = new DLog();
    }
    
    return instance;

}


void DLog::purge(){

    CC_SAFE_DELETE( instance );
}
