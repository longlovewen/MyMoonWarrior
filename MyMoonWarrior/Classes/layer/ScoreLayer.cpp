//
//  ScoreLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "ScoreLayer.h"


ScoreLayer::ScoreLayer(){}
ScoreLayer::~ScoreLayer(){}

bool ScoreLayer::init(){
    
    if( !BasicLayer::init() ){
        
        return false;
    }
    setupViews();
    
    return true;
}


//  初始化控件
void ScoreLayer::setupViews(){

    do {
        CCLabelBMFont* scoreFont = CCLabelBMFont::create("Score:20", "arial-14.fnt");
        scoreFont->setAnchorPoint( CCPointZero );
        scoreFont->setPosition( CCPointZero );
        scoreFont->setScale( 1.5f);
        this->addChild( scoreFont );
        
    } while (0);
    
    
}


