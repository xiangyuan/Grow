//
//  Macro.h
//  GrowUp
//
//  Created by wlg on 14-8-11.
//
//

#ifndef GrowUp_Macro_h
#define GrowUp_Macro_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameConstants.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define WinSize cocos2d::Size(768,1024) //设计分辨率，绘制区，可能包含空白
#define VisibleSize Director::getInstance()->getVisibleSize()  //设计分辨率可视区域大小，绘制区的可见部分
#define VisibleOrigin Director::getInstance()->getVisibleOrigin()  //可见区 原点

#define PTM_RATIO 16
#define PAGE_COUNTS 10.000

#define cc_to_b2Vec(x,y) (b2Vec2((x)/PTM_RATIO,(y)/PTM_RATIO))

enum Item_Type{
    Flame_Blue = 1,
    Flame_Orange,
    Flame_Violet,
    Flame_White,
    Cicada,
    Dragon_Anti,
    Dragon_Clockwise,
    DoubDragon_Anti,
    DoubDragon_Clockwise,
    Serpent_,
    Gear_Button,
    Gear_Gate,
    Barrier_,
    Decoration_Bridge,
    Decoration_Pendant,
    Polygon_,
    Rock_Circle = 101,
    Rock_Ellipse,
    Rock_Mount,
    Rock_MountInv,
    Rock_Ovoid,
    Rock_Rect,
    Rock_Trape
};

enum
{
    TypeDirtLine = 111,
};


#define IMAGE_FLAME_BLUE "Flame_Blue.png"
#define IMAGE_FLAME_ORANGE "Flame_Orange.png"
#define IMAGE_FLAME_VIOLET "Flame_Violet.png"
#define IMAGE_FLAME_WHITE "Flame_White.png"
#define IMAGE_CICADA "Cicada.png"
#define IMAGE_DRAGON_ANTI "Dragon_Anti.png"
#define IMAGE_DRAGON_CLOCKWISE "Dragon_Clockwise.png"
#define IMAGE_DOUBDRAGON_ANTI "DoubDragon_Anti.png"
#define IMAGE_DOUBDRAGON_CLOCKWISE "DoubDragon_Clockwise.png"
#define IMAGE_SERPENT "Serpent.png"
#define IMAGE_GEARBUTTON "GearButton.png"
#define IMAGE_GEARGATE "GearGate.png"
#define IMAGE_BARRIER "Barrier.png"
#define IMAGE_DECORATION_BRIDGE "Decoration_Bridge.png"
#define IMAGE_DECORATION_PENDANT "Decoration_Pendant.png"
#define IMAGE_POLYGON "Polygon.png"
#define IMAGE_ROCK_CIRCLE "Rock_Circle.png"
#define IMAGE_ROCK_ELLIPSE "Rock_Ellipse.png"
#define IMAGE_ROCK_MOUNT "Rock_Mount.png"
#define IMAGE_ROCK_MOUNTINV "Rock_MountInv.png"
#define IMAGE_ROCK_OVOID "Rock_Ovoid.png"
#define IMAGE_ROCK_RECT "Rock_Rect.png"
#define IMAGE_ROCK_TRAPE "Rock_Trape.png"


#define IMAGE_EDITOR_ADDITEM_NORMAL "addItem_normal.png"
#define IMAGE_EDITOR_ADDITEM_SELECTED "addItem_addItem_selected.png"
#define IMAGE_EDITOR_SAVE_NORMAL "save_normal.png"
#define IMAGE_EDITOR_SAVE_SELECTED "save_selected.png"
#define IMAGE_EDITOR_RESET_NORMAL "reset_normal.png"
#define IMAGE_EDITOR_RESET_SELECTED "reset_selected.png"
#define IMAGE_EDITOR_COPY_NORMAL "copy_normal.png"
#define IMAGE_EDITOR_COPY_SELECTED "copy_selected.png"
#define IMAGE_EDITOR_DELETE_NORMAL "delete_normal.png"
#define IMAGE_EDITOR_DELETE_SELECTED "delete_selected.png"
#define IMAGE_EDITOR_PLAY_NORMAL "play_normal.png"
#define IMAGE_EDITOR_PLAY_SELECTED "play_selected.png"
#define IMAGE_EDITOR_ZOOMIN_NORMAL "zoomin_normal.png"
#define IMAGE_EDITOR_ZOOMIN_SELECTED "zoomin_selected.png"
#define IMAGE_EDITOR_ZOOMOUT_NORMAL "zoomout_normal.png"
#define IMAGE_EDITOR_ZOOMOUT_SELECTED "zoomout_selected.png"
#define IMAGE_EDITOR_HIDE_NORMAL "hide_normal.png"
#define IMAGE_EDITOR_HIDE_SELECTED "hide_selected.png"


#define IMAGE_MATERIAL_DIRT "dirt512_2.png"


#endif
