//
//  Barrier.h
//  GrowUp
//
//  Created by wlg on 11/7/14.
//
//

#ifndef __GrowUp__Barrier__
#define __GrowUp__Barrier__

#include <iostream>
#include "Macro.h"
#include "ItemModel.h"

class Barrier : public ItemModel
{
public:
    static Barrier* create(Item& item);
    bool init(Item& item);
    
    void createBody();
    void collisionWithPlant(ItemModel* plantHead);
    
};



#endif /* defined(__GrowUp__Barrier__) */
