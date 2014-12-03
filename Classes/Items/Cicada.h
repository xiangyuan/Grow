//
//  Cicada.h
//  Grow
//
//  Created by 林纲 王 on 14-10-8.
//
//

#ifndef __Grow__Cicada__
#define __Grow__Cicada__

#include <iostream>
#include "Box2d/Box2d.h"
#include "Macro.h"
#include "ItemModel.h"
//#define CICADA_OLD 1

class Cicada : public ItemModel
{
public:
    Cicada();
    ~Cicada();
    
    static Cicada* create(Item& item);
    bool init(Item& item);
    
    void createBody();
    
protected:
#ifdef CICADA_OLD
    Sprite* _head;
    Sprite* _belly;
    Sprite* _leftwing;
    Sprite* _rightwing;
    
    float w;
    float includedAngle;
    float fanningDuration;
    float interval;
    float bellyTransparency;
#else
    Sprite* _eye;
    
#endif
    
};

#endif /* defined(__Grow__Cicada__) */