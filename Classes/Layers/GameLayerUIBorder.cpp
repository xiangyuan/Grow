#include "GameLayerUIBorder.h"
#include "GameRuntime.h"
#include "GamePhysicalWorld.h"
bool GameLayerUIBorder::init()
{
    GameLayerBase::init();
    setContentSize(GameRuntime::getInstance()->getVisibleSize());
    UIHelper::layout(this, UIHelper::ViwePoistionType::BottomCenter);
    _borderLeftLayer = nullptr;
    _borderRightLayer = nullptr;

    for (auto& i: bodys) {
        i = nullptr;
    }
    return true;
}
bool GameLayerUIBorder::releaseGameInfo()
{
    //removeAllChildren();
    _borderLeftLayer = nullptr;
    _borderRightLayer = nullptr;
    for(auto& i: bodys)
    {
        if(i) GamePhysicalWorld::getInstance()->getBox2dWorld()->DestroyBody(i);
        i = nullptr;
    }

    return true;
}
bool GameLayerUIBorder::initGameInfo()
{
    auto runtime = GameRuntime::getInstance();
    auto texture = GameRunningConfig::getInstance()->getTextureUIBorder();
    _borderLeftLayer = GameLayerRollImage::create();
    _borderLeftLayer->_itemAnchorPoint =runtime->getGameLayerUIBorderAPLeft();
    _borderLeftLayer->_xPosition = 0;
    _borderLeftLayer->setImage(texture);
    
    _borderRightLayer = GameLayerRollImage::create();
    _borderRightLayer->_itemAnchorPoint =runtime->getGameLayerUIBorderAPRight();

    _borderRightLayer->_itemIsFlippedx = true;
    _borderRightLayer->_xPosition = 1;
    _borderRightLayer->setImage(texture);
 
    _borderLeftLayer->setImageStartY(0);
    _borderRightLayer->setImageStartY(0);
    
    UIHelper::layout(_borderLeftLayer, UIHelper::ViwePoistionType::BottomCenter);
    UIHelper::layout(_borderLeftLayer, UIHelper::ViwePoistionType::BottomCenter);
    
    addChild(_borderLeftLayer);
    addChild(_borderRightLayer);
    addUIBorderBody();
    return true;
}

#include "ItemModel.h"
void   GameLayerUIBorder::addUIBorderBody()
{
    
//    auto runtime = GameRuntime::getInstance();
    Size win = GameRuntime::getInstance()->getVisibleSize();
    float scale = 1;
    if (win.width < 750) {
        scale = 0.4;
    }
    float xvec[3]={
        55 * scale,
        win.width- 55* scale,
        win.width * 0.5f
    };

    static ItemModel _sUIBorderBody;
    _sUIBorderBody.setType(TypeUIBorderLine);
    for (int i = 0 ; i<2; i++) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        bodyDef.position = b2Vec2(0,0);
        bodyDef.userData =&_sUIBorderBody;
        bodys[i]= GamePhysicalWorld::getInstance()->getBox2dWorld()->CreateBody(&bodyDef);
        b2FixtureDef fixtureDef;
        b2ChainShape b2line;
        b2Vec2 verts[2]=
        {
            b2Vec2(xvec[i]/PTM_RATIO,0),
            b2Vec2(xvec[i]/PTM_RATIO,win.height/PTM_RATIO)
        };
        b2line.CreateChain(verts,2);
        fixtureDef.shape = &b2line;
        fixtureDef.filter.groupIndex = -1;
        bodys[i]->CreateFixture(&fixtureDef);
    }
    
}
void  GameLayerUIBorder::update(float dt)
{

}
void GameLayerUIBorder::moveDown(float yLen)
{
    _borderLeftLayer->moveDown(yLen*1.2);
    _borderRightLayer->moveDown(yLen*1.2);
}