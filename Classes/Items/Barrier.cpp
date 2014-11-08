//
//  Barrier.cpp
//  GrowUp
//
//  Created by wlg on 11/7/14.
//
//

#include "Barrier.h"
#include "GameManager.h"
#include "LayerItem.h"


Barrier* Barrier::create(Item &item)
{
    Barrier* barrier = new Barrier();
    if (barrier&&barrier->init(item)) {
        barrier->autorelease();
        return barrier;
    }
    CC_SAFE_DELETE(barrier);
    return nullptr;
}

bool Barrier::init(Item &item)
{
    if (ItemModel::init(item)) {
        
        setTexture(IMAGE_BARRIER);
        setRotation(CC_RADIANS_TO_DEGREES(item.angle));
        setScale(item.scale);
        
        _collisionCallBack = std::bind(&Barrier::collisionWithPlant,this,std::placeholders::_1);
        return true;
    }
    
    return false;
}

void Barrier::createBody()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = cc_to_b2Vec(getParent()->convertToWorldSpace(getPosition()).x, getParent()->convertToWorldSpace(getPosition()).y);
    bodyDef.angle = -CC_DEGREES_TO_RADIANS(getRotation());
    bodyDef.userData = this;
    _body = GameManager::getInstance()->getBox2dWorld()->CreateBody(&bodyDef);
    
    ((LayerItem*)getParent())->_fixturesCache->addFixturesToBody(_body, "Barrier");
    
}

void Barrier::collisionWithPlant(ItemModel* plantHead)
{
    GameManager::getInstance()->getBox2dWorld()->DestroyBody(_body);
    _body = nullptr;
    ((LayerItem*)getParent())->getItems().remove(this);
    FadeTo* disappear = FadeTo::create(1,0);
    CallFunc* remove = CallFunc::create([&](){
        this->removeFromParent();
    });
    runAction(Sequence::create(disappear,remove, NULL));
    //other effect
    
    
}
