#include "LayerMapGrid.h"
#include "LayerBorder.h"
#include "LayerPlant.h"
#define TOUCH_MIN_LENGTH 32

#define MAX_CRASH_LENGTH 50
bool LayerMapGrid::init()
{
    GameLayerRollY::init();
    _gameManager = GameManager::getInstance();
    
    _mapGrid._maxViewHeight = _gameManager->getMapGridUnitVisibleSize().height;
    _mapGrid._unitGridSize = _gameManager->getMapGridUnitSize();
    _mapGrid._sceneGame = _gameManager->getGameScene();
    _mapGrid._layerPlant = static_cast<LayerPlant_1*>(_gameManager->_layerplant);
    _gameManager->setLayerMapGrid(this);
    
    cocos2d::Size visibleSize = Director::getInstance()->getWinSize();
    cocos2d:: Size gridSize =_gameManager->getMapGridUnitVisibleSize();
    _mapGrid.resize(gridSize.width, gridSize.height*2);
    
    _mapGrid.setData(0, 0, 255);
    _textureAlphaMask = new Texture2D();
    _textureAlphaMask->initWithData(_mapGrid._gridData,gridSize.width*(gridSize.height+1), Texture2D::PixelFormat::A8,gridSize.width, gridSize.height+1, cocos2d::Size(gridSize.width,gridSize.height+1));
    _textureAlphaMask->autorelease();
    
    _maskAlphaSprite = Sprite::createWithTexture(_textureAlphaMask);
    _maskAlphaSprite->setScale(_gameManager->getMapGridUnitSize().width,_gameManager->getMapGridUnitSize().height);
    BlendFunc funcMaskSprite = {GL_ONE,GL_ZERO};
    _maskAlphaSprite->setBlendFunc(funcMaskSprite);
    _maskAlphaSprite->setAnchorPoint(Vec2(0.5,1));
    _maskAlphaSprite->setRotationX(180);
    _maskAlphaSprite->setPosition(Vec2(_gameManager->getVisibleSize().width*0.5,0));
    addChild(_maskAlphaSprite);
    return  true;
}
 bool LayerMapGrid::initGameInfo()
{
    _mapGrid._layerBorder = _gameManager->getLayerBorder();
    return true;
}
void LayerMapGrid::update(float dt)
{
    _textureAlphaMask->updateWithData(_mapGrid.getDataByOriginY(), 0,0, _mapGrid._gridWidth, _mapGrid._maxViewHeight+1);

}

void LayerMapGrid::moveDown(float yLen)
{
    moveDownAlphaMask(yLen);
    moveDownMapGrid(yLen);
}
#include "LayerItem.h"
//向下移动单元格 同时移动边缘层
void LayerMapGrid::moveDownMapGrid(int moveLen)
{
    _mapGrid._startHeight += moveLen;
    if (_mapGrid._startHeight+ _mapGrid._maxViewHeight >= _mapGrid._maxViewHeight+MAX_CRASH_LENGTH) {
        
        memmove(_mapGrid._gridData, _mapGrid._gridData+(_mapGrid._startHeight)*_mapGrid._gridWidth,(_mapGrid._maxViewHeight)*_mapGrid._gridWidth);
        _mapGrid.setData(0,_mapGrid._maxViewHeight,_mapGrid._gridWidth,MAX_CRASH_LENGTH,GridType::Dirt);
        _gameManager->getLayerBorder()->moveDownGridCell(_mapGrid._startHeight);
        _mapGrid._startHeight=0;
        
        auto list = _gameManager->_layerItem->getPolygons();
        auto size = _gameManager->getMapGridUnitVisibleSize();
        
        auto map = _gameManager->getMapGrid();
        for (int j = _mapGrid._maxViewHeight ; j< _mapGrid._maxViewHeight +MAX_CRASH_LENGTH; j++) {
            for (int i = 0; i<size.width; i++) {
                for (auto& ip: list) {
                    Vec2 pt = map->getPositionByMapGridCell(i,j);
                    b2Vec2 vec(pt.x/PTM_RATIO,pt.y/PTM_RATIO);
                    for (b2Fixture* fixture = ip->getBody()->GetFixtureList(); fixture; fixture=fixture->GetNext()) {
                        if(fixture->TestPoint(vec))
                        {
                            map->changeGridCell(i,j, GridType::None);
                        }
                    }
                    
                }
            }
        }
        GameManager::getInstance()->getLayerBorder()->updateBorder(0, _mapGrid._maxViewHeight,size.width, MAX_CRASH_LENGTH);
        
    }
    _gameManager->getLayerBorder()->suboutViewBorderCell();
}

void LayerMapGrid::moveDownMapGrid(float yLen)
{
    _mapGrid._mapGridStarty += yLen;
    int n =  _mapGrid._mapGridStarty/_mapGrid._unitGridSize.height;
    if (n>0)
    {
        _mapGrid._mapGridStarty -= n*_mapGrid._unitGridSize.height;
        moveDownMapGrid(n);
    }
}

void LayerMapGrid::moveDownAlphaMask(float yLen)
{
    float y = _maskAlphaSprite->getPositionY();
    y -= yLen;
    _maskAlphaSprite->setPositionY(y);
    
    cocos2d::Size visibleSize = Director::getInstance()->getWinSize();
    if (y <= -_mapGrid._unitGridSize.height)
    {
        int n = fabs(y)/_mapGrid._unitGridSize.height;
        _maskAlphaSprite->setPositionY(y+n*_mapGrid._unitGridSize.height);
    }
}

bool LayerMapGrid::onTouchBegan(Touch* touch,Event* event)
{
    //_clearList.clear();
    Point pt = touch->getLocation();
   // _clearList.push_back(pt);
    _touchPrePoint = pt;
    _isFirstMoveTouch = true;
    return true;
}
#include "LayerPlant.h"
void LayerMapGrid::onTouchMoved(Touch* touch,Event* event)
{
        cocos2d::Point pt = touch->getLocation();
        if (fabs(pt.x-_touchPrePoint.x)>TOUCH_MIN_LENGTH||
            fabs(pt.y-_touchPrePoint.y)>TOUCH_MIN_LENGTH) {
           //_clearList.push_back(pt);
          if(_mapGrid.touchClearGrid(touch->getLocation()))
//                //  _borderlayer->updateBorder(0, 0, _mapGrid._gridWidth, _mapGrid._maxViewHeight);
            _touchPrePoint = pt;
            if(_isFirstMoveTouch)
            {
            auto node =((LayerPlant_1*)(GameManager::getInstance()->getLayerPlant()))->_plant;
            Vec2 pt1 =node->convertToWorldSpace(node->_headCur.getPosition());
            float len = pt1.getDistance(pt);
            if (len <150) {
                GridCell cell = _mapGrid.getMapGridCellByPosition(pt1);
                // log("Touch Clear Grid x: %f , y: %f",touchPoint.x,touchPoint.y);
                // return   clearGridCell(cell._x,cell._y);
                _mapGrid.clearGridCellBorderByRange(cell,6);
               
            }
            }
                _isFirstMoveTouch =false;
        }

}

void LayerMapGrid::onTouchEnded(Touch* touch,Event* event)
{
    if(_isFirstMoveTouch)
    {
        auto node =((LayerPlant_1*)(GameManager::getInstance()->getLayerPlant()))->_plant;
        Vec2 pt1 =node->convertToWorldSpace(node->_headCur.getPosition());
        float len = pt1.getDistance(touch->getLocation());
        if (len <150) {
            GridCell cell = _mapGrid.getMapGridCellByPosition(pt1);
            // log("Touch Clear Grid x: %f , y: %f",touchPoint.x,touchPoint.y);
            // return   clearGridCell(cell._x,cell._y);
            _mapGrid.clearGridCellBorderByRange(cell,6);
            
        }
    }
    _mapGrid.touchClearGrid(touch->getLocation());
}

bool LayerMapGrid::clearGridByTouchPoint(Vec2 pt)
{
    
}