#ifndef __Grow_Demo__LayerDirt__
#define __Grow_Demo__LayerDirt__
#include "Macro.h"
#include "PlantBase.h"

class LayerDirt1 : public Node
{
public:
    CREATE_FUNC(LayerDirt1);
    virtual  bool init();
    
    void updateSprites();
    void  moveDown(float yLen);
    BlendFunc _blendFunc;
    std::list<Sprite*> _dirtList;
};


class LayerRollImage : public GameLayerRollY
{
public:
    CREATE_FUNC(LayerRollImage);
    virtual ~LayerRollImage()
    {
        CC_SAFE_RELEASE_NULL(_imageTexture);
    }
    virtual  bool  init();
    virtual  void  moveDown(float yLen) override;
    
    void  setImage(const std::string& imageName);
    void  setImage(Texture2D* imageTexture);
    
    void  setBlendFunc(BlendFunc);
    
    Sprite*  addImage(bool topDir);
    void  reSet();
    
    void  setImageStartY(float y);
    
    void  autoAddImage();
    
    void  checkReleaseOutViweSprite();
    
    void  _clearImages();
    
    void _LayoutImage(Sprite* sprite,float y);
    std::list<Sprite*> _imageList;
    BlendFunc _blendFunc;
    Texture2D*  _imageTexture;

};
#endif /* defined(__Grow_Demo__LayerDirt__) */
