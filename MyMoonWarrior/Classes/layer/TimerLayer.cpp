//
//  TimerLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "TimerLayer.h"



TimerLayer::TimerLayer(){
    
    counter = 0;

}
TimerLayer::~TimerLayer(){}

bool TimerLayer::init(){

    if( !BasicLayer::init() ){
        return false;
    }
    
    setupViews();
    
    return true;
}

void TimerLayer::setupViews(){

    do {
        
        CCLabelBMFont* timer_font = CCLabelBMFont::create("Time:0", "arial-14.fnt");
        
        timer_font->setAnchorPoint( CCPointZero );
        timer_font->setPosition( CCPointZero );
        timer_font->setScale( 1.5f);
        this->addChild( timer_font,0,15);
        
        
        
        //  加入计时的定时任务
        this->schedule( schedule_selector(TimerLayer::time_counting_down),1.0f );
        
        
    } while (0);
}


//  计时的逻辑
void TimerLayer::time_counting_down( float t ){
    
    CCLabelBMFont* timer_font = ( CCLabelBMFont*)getChildByTag( 15 );
    
    char str[20] = {0};
    ++counter;
    sprintf(str, "Time:%d",counter );
    timer_font->setString( str );
  
}