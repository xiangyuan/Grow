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

#define DefiniteSize cocos2d::Size(768,1024)
#define ScreenSize Director::getInstance()->getOpenGLView()->getFrameSize() //屏幕分辨率(pix)
#define VisibleSize Director::getInstance()->getVisibleSize()  //设计分辨率可视区域大小(points)
#define VisibleOrigin Director::getInstance()->getVisibleOrigin()  //设计分辨率可视区域起点

#define PTM_RATIO 16
#define PAGE_COUNTS 10.000
#define FLOWER_COUNT 50
#define LEVEL_COUNT 4

#define cc_to_b2Vec(x,y) (b2Vec2((x)/PTM_RATIO,(y)/PTM_RATIO))

enum Item_Type{
    Flame_Blue = 1,
    Flame_Orange,
    Flame_Violet,
    Flame_White,
    Cicada,
    DoubDragon_Anti,
    DoubDragon_Clockwise,
    Serpent_,
    Gear_Button,
    Gear_Gate,
    Gear_Reversal,
    Barrier_,
    Decoration_Bridge,
    Decoration_Flower,
    Decoration_FlowerInv,
    Decoration_Pendant,
    Sprouts_Dextro,
    Sprouts_Levo,
    Sprouts_Slope,
    Polygon_,
    Trigger,
    
    Rock_Circle = 101,
    Rock_Cover,
    Rock_Crinkle,
    Rock_Cross,
    Rock_Dagger,
    Rock_Ellipse,
    Rock_Mount,
    Rock_MountInv,
    Rock_Ordinary,
    Rock_Ovoid,
    Rock_Pebble,
    Rock_Pillar,
    Rock_Pocket,
    Rock_Rect,
    Rock_Trape
};

enum class GuideCourse1{
    StrokeDirt,
    FlameWhite,
    FlameBlue
};

enum class GuideCourse2{
    EncounterCicada
};

enum class GuideCourse3{
    EncounterSerpent
};

enum class GuideCourse4{
    EncounterGear
};

#define IMAGE_FLAME_BLUE "Flame_Blue.png"
#define IMAGE_FLAME_ORANGE "Flame_Orange.png"
#define IMAGE_FLAME_VIOLET "Flame_Violet.png"
#define IMAGE_FLAME_WHITE "Flame_White.png"
#define IMAGE_CICADA_RED "Cicada_Red.png"
#define IMAGE_CICADA_BLUE "Cicada_Blue.png"
#define IMAGE_DOUBDRAGON_ANTI "DoubDragon_Anti.png"
#define IMAGE_DOUBDRAGON_CLOCKWISE "DoubDragon_Clockwise.png"
#define IMAGE_SERPENT "Serpent.png"
#define IMAGE_GEARBUTTON "GearButton.png"
#define IMAGE_GEARGATE "GearGate.png"
#define IMAGE_GEARREVERSAL "GearReversal.png"
#define IMAGE_BARRIER_RED "Barrier_Red.png"
#define IMAGE_DECORATION_BRIDGE "Decoration_Bridge.png"
#define IMAGE_DECORATION_FLOWER "Decoration_Flower.png"
#define IMAGE_DECORATION_FLOWERINV "Decoration_FlowerInv.png"
#define IMAGE_DECORATION_PENDANT "Decoration_Pendant.png"
#define IMAGE_SPROUTS_DEXTRO "Sprouts_Dextro.png"
#define IMAGE_SPROUTS_LEVO "Sprouts_Levo.png"
#define IMAGE_SPROUTS_SLOPE "Sprouts_Slope.png"
#define IMAGE_TRIGGER "Trigger.png"
#define IMAGE_POLYGON "Polygon.png"
#define IMAGE_ROCK_CIRCLE "Rock_Circle"
#define IMAGE_ROCK_COVER "Rock_Cover"
#define IMAGE_ROCK_CRINKLE "Rock_Crinkle"
#define IMAGE_ROCK_CROSS "Rock_Cross"
#define IMAGE_ROCK_DAGGER "Rock_Dagger"
#define IMAGE_ROCK_ELLIPSE "Rock_Ellipse"
#define IMAGE_ROCK_MOUNT "Rock_Mount"
#define IMAGE_ROCK_MOUNTINV "Rock_MountInv"
#define IMAGE_ROCK_ORDINARY "Rock_Ordinary"
#define IMAGE_ROCK_OVOID "Rock_Ovoid"
#define IMAGE_ROCK_PEBBLE "Rock_Pebble"
#define IMAGE_ROCK_PILLAR "Rock_Pillar"
#define IMAGE_ROCK_POCKET "Rock_Pocket"
#define IMAGE_ROCK_RECT "Rock_Rect"
#define IMAGE_ROCK_TRAPE "Rock_Trape"

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

#endif
