#include "LayerBorder.h"
#include "MapGrid.h"
#include "GameManager.h"
#include "MathHelper.h"
#include "BorderLine.h"
#include "TypeBase.h"
#include "Macro.h"
#define BORDER_WIDTH 32
#define TABLE(T) _sQuadVecMap.insert(std::make_pair(T,quad))
#define BORDER_HEIGHT 8.0f
std::map<BorderMaskType,QuadVec> LayerBorder::_sQuadVecMap;
     V3F_C4B_T2F_Quad LayerBorder::_sRawQuad;
 int LayerBorder::initQuadMap()
{
    memset(&_sRawQuad, 0, sizeof(_sRawQuad));
    QuadVec quad;
    Size unit = GameManager::getInstance()->getMapGridUnitSize();
    quad.rb = Vec3(2*unit.width,0,0);
    quad.rt = Vec3(2*unit.width,unit.height,0);
    quad.lb = quad.rb + Vec3(-BORDER_WIDTH,0,0);
    quad.lt = quad.rt + Vec3(-BORDER_WIDTH,0,0);
    TABLE(r_rb_rt);
////
    quad.rb = Vec3(2*unit.width,0,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(-BORDER_WIDTH,0,0);
    quad.lt = MathHelper::getRotatePosition(quad.rb, quad.lb, 45);
    TABLE(r_rb);
 ////
    quad.rb = Vec3(unit.width,-unit.width,0);
    quad.rt = Vec3(2* unit.width,0,0);
    quad.lb = quad.rb + Vec3(-BORDER_WIDTH,0,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(-BORDER_WIDTH,0,0);
    quad.lt = MathHelper::getRotatePosition(quad.rt,quad.lt,45);
    TABLE(rb_r_b);
////
    quad.rb = Vec3(unit.width,-unit.width,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(-BORDER_WIDTH,0,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(0,BORDER_WIDTH,0);
    TABLE(b_rb);
///

    quad.rb = Vec3(0,-unit.width,0);
    quad.rt =  Vec3(unit.width,-unit.width,0);
    quad.lb = quad.rb + Vec3(0,BORDER_WIDTH,0);
    quad.lt = quad.rt + Vec3(0,BORDER_WIDTH,0);
    TABLE(b_lb_rb);
///
    
    
    quad.rb = Vec3(0,-unit.width,0);
    quad.rt = quad.rb ;
    quad.lb = quad.rb + Vec3(0,BORDER_WIDTH,0);
    quad.lt = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    TABLE(b_lb);
///
    
    quad.rb = Vec3(-unit.width,0,0);
    quad.rt = Vec3(0,-unit.height,0);
    quad.lb = quad.rb + Vec3(0,BORDER_WIDTH,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(0,BORDER_WIDTH,0);
    quad.lt = MathHelper::getRotatePosition(quad.rt,quad.lt,45);
    TABLE(lb_l_b);
///
    
    quad.rb = Vec3(-unit.width,0,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(0,BORDER_WIDTH,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(BORDER_WIDTH,0,0);
    TABLE(l_lb);
///
    
    quad.rb = Vec3(-unit.width,unit.width,0);
    quad.rt = Vec3(-unit.width,0,0);
    quad.lb = quad.rb + Vec3(BORDER_WIDTH,0,0);
    quad.lt = quad.rt + Vec3(BORDER_WIDTH,0,0);
    TABLE(l_lb_lt);
///
    
    quad.rb = Vec3(-unit.width,unit.width,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(BORDER_WIDTH,0,0);
    quad.lt = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    TABLE(l_lt);
///
    
    quad.rb = Vec3(0,2*unit.width,0);
    quad.rt = Vec3(-unit.width,unit.width,0);

    quad.lb = quad.rb + Vec3(BORDER_WIDTH,0,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(BORDER_WIDTH,0,0);
    quad.lt = MathHelper::getRotatePosition(quad.rt,quad.lt,45);
    TABLE(lt_l_t);
///
    
    
    quad.rb = Vec3(0,2*unit.width,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(BORDER_WIDTH,0,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(0,-BORDER_WIDTH,0);
    TABLE(t_lt);
///
    
    quad.rb = Vec3(unit.width,2*unit.width,0);
    quad.rt = Vec3(0,2*unit.width,0);
    quad.lb = quad.rb + Vec3(0,-BORDER_WIDTH,0);
    quad.lt = quad.rt + Vec3(0,-BORDER_WIDTH,0);
    TABLE(t_lt_rt);
///
    
    quad.rb = Vec3(unit.width,2*unit.width,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(0,-BORDER_WIDTH,0);
    quad.lt = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    TABLE(t_rt);
///
    
    quad.rb = Vec3(2*unit.width,unit.width,0);
    quad.rt = Vec3(unit.width,2*unit.width,0);
    quad.lb = quad.rb + Vec3(0,-BORDER_WIDTH,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(0,-BORDER_WIDTH,0);
    quad.lt = MathHelper::getRotatePosition(quad.rt,quad.lt,45);
    TABLE(rt_r_t);
///
    quad.rb = Vec3(2*unit.width,unit.width,0);
    quad.rt = quad.rb;
    quad.lb = quad.rb + Vec3(0,-BORDER_WIDTH,0);
    quad.lb = MathHelper::getRotatePosition(quad.rb,quad.lb,45);
    quad.lt = quad.rt + Vec3(-BORDER_WIDTH,0,0);
    TABLE(r_rt);
///
//////////////
    
    quad.rb = Vec3(unit.width,2*unit.width,0);
    quad.rt = Vec3(-unit.width,unit.width,0);
    quad.lb = quad.rb + Vec3(0,-BORDER_WIDTH,0);
    quad.lt = quad.lb;
    TABLE(lt_l_t_rt);
/////
    quad.rb = Vec3(0,2*unit.width,0);
    quad.rt = Vec3(-unit.width,0,0);
    quad.lb = quad.rt + Vec3(BORDER_WIDTH,0,0);
    quad.lt = quad.lb;
    TABLE(lt_l_t_lb);
///
    
    quad.rb = Vec3(2*unit.width,unit.width,0);
    quad.rt = Vec3(0,2*unit.width,0);
    quad.lb = quad.rt + Vec3(0,-BORDER_WIDTH,0);
    quad.lt = quad.lb;
    TABLE(rt_r_t_lt);
/////
    
    quad.rb = Vec3(2*unit.width,0,0);
    quad.rt = Vec3(unit.width,2*unit.width,0);
    quad.lb = quad.rb + Vec3(-BORDER_WIDTH,0,0);
    quad.lt = quad.lb;
    TABLE(rt_r_t_rb);
///
    
    quad.rb = Vec3(-unit.width,0,0);
    quad.rt = Vec3(unit.width,-unit.width,0);
    quad.lb = quad.rt + Vec3(0,BORDER_WIDTH,0);
    quad.lt = quad.lb;
    TABLE(lb_l_b_rb);
/////
    quad.rb = Vec3(-unit.width,unit.width,0);
    quad.rt = Vec3(0,-unit.width,0);
    quad.lb = quad.rb + Vec3(BORDER_WIDTH,0,0);
    quad.lt = quad.lb;
    TABLE(lb_l_b_lt);
///
    
    
    quad.rb = Vec3(0,-unit.width,0);
    quad.rt = Vec3(2*unit.width,0,0);
    quad.lb = quad.rb + Vec3(0,BORDER_WIDTH,0);
    quad.lt = quad.lb;
    TABLE(rb_r_b_lb);
/////
    
    quad.rb = Vec3(unit.width,-unit.width,0);
    quad.rt = Vec3(2*unit.width,unit.width,0);
    quad.lb = quad.rt + Vec3(-BORDER_WIDTH,0,0);
    quad.lt = quad.lb;
    TABLE(rb_r_b_rt);
/////
    
    quad.rb = Vec3(unit.width,2*unit.width,0);
    quad.rt = Vec3(-unit.width,0,0);
    quad.lb = quad.rt + Vec3(BORDER_WIDTH,0,0);
    quad.lt = quad.lb;
    TABLE(lt_l_t_lb_rt);
    
    return 0;
}

V3F_C4B_T2F_Quad LayerBorder::createQuadByBorderCell(const GridCell& cell,BorderMaskType _type,float bHeight)
{
    V3F_C4B_T2F_Quad t;
    float step =1/_quads->getTexture()->getContentSize().height;
    float h = 8.0f;
    t.bl.texCoords = Tex2F(0,bHeight*step-1);
    t.bl.colors = Color4B::WHITE;
    t.br.texCoords = Tex2F(1,bHeight*step-1);
    t.br.colors = Color4B::WHITE;
    t.tl.texCoords = Tex2F(0,(bHeight+h)*step-1);
    t.tl.colors = Color4B::WHITE;
    t.tr.texCoords = Tex2F(1,(bHeight+h)*step-1);
    t.tr.colors = Color4B::WHITE;
    
    QuadVec vec = _sQuadVecMap.find(_type)->second;
    auto p = _mapGrid->getPositionByMapGridCell(cell);
    Vec3 v(p.x,p.y,0);
    t.bl.vertices = vec.lb + v;
    t.tl.vertices = vec.lt + v;
    t.br.vertices = vec.rb + v;
    t.tr.vertices = vec.rt + v;
    
    return t;
}

bool LayerBorder::init()
{
    GameLayerRollY::init();
    GameManager::getInstance()->_layerBorder = this;
    setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR));
    _mapGrid = GameManager::getInstance()->getMapGrid();
    _quads = TextureAtlas::create("border_2.png", 100);
    //_quads = TextureAtlas::createWithTexture(nullptr, 100);
    Texture2D::TexParams  parms = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
    _quads->getTexture()->setTexParameters(parms);
    _moveDownLenght = 0;
    _quads->retain();
    _world = GameManager::getInstance()->getBox2dWorld();
    return true;
}

void LayerBorder::setTexture(Texture2D* texture)
{
    if(!texture)return;
    _quads->setTexture(texture);
    Texture2D::TexParams  parms = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
    _quads->getTexture()->setTexParameters(parms);
}
inline void LayerBorder::releaseQuad(int index)
{
    _quads->updateQuad(&_sRawQuad, index);
    _quadsPool.push_back(index);
}
int LayerBorder::createOneQuad()
{
    int index = 0;
    if(!_quadsPool.empty())
    {
        index = *_quadsPool.rbegin();
        _quadsPool.pop_back();
    }
    else
    {
        index = _quads->getTotalQuads();
        if (index>=_quads->getCapacity()) {
            _quads->resizeCapacity(_quads->getCapacity()+100);
        }
        _quads->insertQuad(&_sRawQuad,index);
    }
    return index;
}
bool LayerBorder::isHasBorder(const GridCell& cell)
{
    return _borderMap.find(cell)!=_borderMap.end();
}

void  LayerBorder::addBorderCell(int x,int y)
{
    
}
void  LayerBorder::addBorderCell(BorderCell cell)
{
    //_borderMap.insert(std::make_pair(, <#_T2 &&__t2#>))
}
void  LayerBorder::updateQuad(const GridCell& cell, const BorderContext& context)
{
    auto quad = createQuadByBorderCell(cell, context._maskType, context._quadStartHeight);
    _quads->updateQuad(&quad, context._quadIndex);
}
void LayerBorder::addBorderLine(const BorderLine& line)
{
    if (line._borderList.empty()) return ;
    float h = 0;
    auto start = *line._borderList.begin();
    auto  pre = _borderMap.find(start.getPreMapCell());
    if(pre != _borderMap.end())
    {
        h = pre->second._quadStartHeight+BORDER_HEIGHT;
        BorderCell cell;
        if(isBorderCell(pre->first._x, pre->first._y, GridType::None, cell))
        {
            pre->second._maskType=cell._maskDir;
            
            updateQuad(pre->first, pre->second);
        }
        
    }
    auto rstart = *line._borderList.rbegin();
     auto  endNext = _borderMap.find(rstart.getNextMapCell());
    if(endNext != _borderMap.end())
    {
        BorderCell cell;
        if(isBorderCell(endNext->first._x, endNext->first._y, GridType::None, cell))
        {
            endNext->second._maskType=cell._maskDir;
            
            updateQuad(endNext->first, endNext->second);
        }
    }
    Size size =_quads->getTexture()->getContentSize();
    if(h>size.height)
    {
        int n = h/size.height;
        h = h - size.height* n;
    }
    for (auto i : line._borderList) {
        V3F_C4B_T2F_Quad quad = createQuadByBorderCell(i._cell, i._maskDir, h);
        int index = createOneQuad();
        BorderContext context(i._maskDir,h,index);
        _borderMap.insert(std::make_pair(i._cell, context));
        updateQuad(i._cell, context);
        h += 8.0f;
    }
}
void LayerBorder::removeBorder(const GridCell& cell)
{
    auto ip = _borderMap.find(cell);
    if (ip!= _borderMap.end() ) {
        releaseQuad(ip->second._quadIndex);
        _borderMap.erase(ip);
    }
    
}
void LayerBorder::updateBorder(int x,int y, int width,int height)
{
    std::set<BorderCell> borderSet;
    for (int i = x; i < x+width; i++)
    {
        for (int j = y; j< y+height; j++)
        {
            GridCell gridCell = GridCell(i,j);//=_mapGrid->getGridCellByView(i, j);
            if (_mapGrid->isOutMapGrid(gridCell._x, gridCell._y)) {
                continue;
            }
        
            BorderCell cell;
            if (isBorderCell(gridCell._x, gridCell._y,(unsigned char)GridType::Dirt,cell)&&
                !isHasBorder(cell._cell)) {
                borderSet.insert(cell);
            }
        }
    }
    std::list<BorderLine> list(std::move(getBorderlines(std::move(borderSet))));
    if (list.size()<=0) {
        return;
    }

    removeAllBorderLineInBox2dWorld();
    for(auto& line :list)
    {
        addBorderLine(line);
    }
    std::set<BorderCell> oldSet;;
    for(auto& i:_borderMap)
    {
        oldSet.insert(BorderCell(i.first,i.second._maskType));
    }

    std::list<BorderLine> oldList(std::move(getBorderlines(std::move(oldSet))));
    for(auto& line :oldList)
    {
        addBorderLineToBox2dWorld(line);
    }
    
}

void LayerBorder::linkBorderLines(std::list<BorderLine>& lineList)
{
    
    if(lineList.size()<2)return;
    BorderLine line;
    auto ip = lineList.begin();
    auto end = lineList.end();
    while (ip!=lineList.end()) {
        auto now = ip;
        ip++;
        bool islink =false;
        while (ip!=lineList.end()) {
            if (now->LinkBorderLine(*ip)) {
                ip = lineList.erase(ip);
                islink = true;
            }
            else ip++;
        }
        if (!islink) now++;
        
        ip = now;
    }
}

std::list<BorderLine> LayerBorder::getBorderlines( std::set<BorderCell>&& set)
{
    std::list<BorderLine> ret;
    if (set.empty()) {
        return  std::move(ret);
    }
    while(!set.empty())
    {
        ret.push_back(BorderLine());
        BorderLine& line = *ret.rbegin();
        BorderCell cell;
        std::set<BorderCell>::const_iterator ip=set.begin();
        cell = *ip;
        line.push_back(cell);
        set.erase(ip);
        GridCell tgrid;
        for (int i=0; i<2; i++) {
            BorderCell tcell = cell;
            for (; ; ) {
                if(i==0) tgrid =tcell.getNextMapCell();
                else tgrid = tcell.getPreMapCell();
                if(set.empty())break;
                auto ipn = set.find(tgrid);// std::find(set.begin(),set.end(),tgrid);
                if(ipn == set.end()){ break;}
                if(i==0)line.push_back(*ipn);
                else line.push_fornt(*ipn);
                tcell =*ipn;
                set.erase(ipn);
            }
        }
    }
     return std::move(ret);
}bool  LayerBorder::isBorderCell(int x,int y,unsigned char type,BorderCell& cellOut)
{
    static int vecs[][2]=
    {
        {-1,0},{1,0},
        {0,1},{0,-1},
        {-1,1},{-1,-1},
        {1,1},{1,-1}
    };
    
    bool bRet=false;
    if(_mapGrid->getValue(x,y)==GridType::None)return false;
    int mask = 0;
    
    for (int i=0; i<8; i++) {
        if (_mapGrid->isOutMapGrid(x+vecs[i][0], y+vecs[i][1])) {
            continue;
        }
        if(_mapGrid->getValue(x+vecs[i][0], y+vecs[i][1]) == GridType::None)
        {
            mask |= (int)pow(2,i);
            bRet=true;
            
        }
    }
    if (bRet&&BorderCell::isValidBorderCell((BorderMaskType)mask))
    {
        cellOut._cell=GridCell(x,y);
        cellOut._maskDir = (BorderMaskType)mask;
    }
    else {bRet=false;}
    return bRet;
}
void LayerBorder::moveDownGridCell(int len)
{
    if (_borderMap.empty()) return;
    std::multimap<GridCell,BorderContext> tmap;
    auto ip = _borderMap.begin();
    auto end = _borderMap.end();
    while (ip!=end) {
        GridCell cell = ip->first;
        cell._y-=len;
        if (cell._y >= 0) {
            tmap.insert(std::make_pair(cell, ip->second));
        }
        else{
            releaseQuad(ip->second._quadIndex);
        }
        ip++;
    }
    _borderMap = std::move(tmap);
}
void LayerBorder::suboutViewBorderCell()
{
  
    auto ip = _borderMap.begin();
    auto end = _borderMap.end();
    while (ip!=end) {
        GridCell cell = ip->first;
         ip++;
        if(cell._y < _mapGrid->_startHeight)removeBorder(cell);
    }
}
void  LayerBorder::moveDown(float y)
{
    auto ip = _borderMap.begin();
    auto end = _borderMap.end();
    while (ip!=end) {
        BorderContext context = ip->second;
         GridCell cell = ip->first;
         updateQuad(cell, context);
            ip->second = context;
        ip++;
    }
    for (auto& i : _bodies) {
       auto pt =  i->GetPosition();
        i->SetTransform(b2Vec2(pt.x,pt.y-y/PTM_RATIO), 0);
    }
}

void LayerBorder::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(LayerBorder::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}
void LayerBorder::onDraw(const Mat4 &transform, uint32_t flags)
{
    //auto pt =this->getPosition();
    getGLProgram()->use();
    getGLProgram()->setUniformsForBuiltins(transform);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    _quads->drawQuads();
}

void LayerBorder::addBorderLineToBox2dWorld(const BorderLine& line)
{
   
    int size =line._borderList.size();
    if (size<2) {
        return ;
    }
    static TypeBase dirtLine(111);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position = b2Vec2(0,0);
    bodyDef.userData = GameManager::getInstance()->_sLineItemModel;
    b2Body* body = _world->CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    b2Vec2* verts = new b2Vec2[line._borderList.size()];
    int index =0 ;
    float count = 0;

    memset(verts,0,sizeof(line._borderList.size()*sizeof(b2Vec2)));
    BorderDirection oldDir = BorderDirection::RightBottom_In;
    float index2 = -1;
    for (auto i : line._borderList ) {

     
        auto dir = i.getNextBorderDirection();
        if ((index2+1 < size-1)&&oldDir==dir){count++; continue;}
           index2++;
        oldDir = dir;
        QuadVec vec = _sQuadVecMap.find(i._maskDir)->second;
        
        auto p = _mapGrid->getPositionByMapGridCell(i._cell);
        auto pt =Vec2(vec.rb.x,vec.rb.y)+ p;
        //auto pt = Vec2(4,4)+p;
        auto v = b2Vec2(pt.x / PTM_RATIO, pt.y / PTM_RATIO);
    
        if(index > 0 && ((int)v.x == (int)verts[index-1].x)&&
           ((int)v.y == (int)verts[index-1].y)){count++;continue;}
        verts[index] =v;
            index++;
        count = 0;
    }
    
    if(index>=2)
    {
    b2ChainShape b2line;
    b2line.CreateChain(verts,index);
   // b2line.CreateLoop(verts, index);
    fixtureDef.shape = &b2line;
    fixtureDef.filter.groupIndex = -1;
    body->CreateFixture(&fixtureDef);
    _bodies.push_back(body);
    }
    delete [] verts;
}
void LayerBorder::removeAllBorderLineInBox2dWorld()
{

    for (auto& i : _bodies) {
        _world->DestroyBody(i);
    }
    _bodies.clear();
}
