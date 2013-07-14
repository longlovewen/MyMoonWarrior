//
//  CescMenu.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-7-14.
//
//

#include "CescMenu.h"


void CescMenu::registerWithTouchDispatcher()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, -129, true);
    
}


CescMenu* CescMenu::create(CCMenuItem* item, ...){

    va_list args;
    va_start(args,item);
    CescMenu *pRet = new CescMenu();
    if (pRet && pRet->initWithItems(item, args))
    {
        pRet->autorelease();
        va_end(args);
        return pRet;
    }
    va_end(args);
    CC_SAFE_DELETE(pRet);
    return NULL;
    
}

bool CescMenu::initWithItems(CCMenuItem* item, va_list args){

    CCArray* pArray = NULL;
    if( item )
    {
        pArray = CCArray::create(item, NULL);
        CCMenuItem *i = va_arg(args, CCMenuItem*);
        while(i)
        {
            pArray->addObject(i);
            i = va_arg(args, CCMenuItem*);
        }
    }
    
    return initWithArray(pArray);


}
