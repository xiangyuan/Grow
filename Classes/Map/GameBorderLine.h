#ifndef __Grow_Demo_test__GameBorderLine__
#define __Grow_Demo_test__GameBorderLine__
#include "common.h"
#include "Grid.hpp"
struct LineDirContext
{
    LineDirContext(BorderDirection next ,BorderDirection pre):_next(next),_pre(pre){}
    BorderDirection _next,_pre;
};
class  BorderCell
{
public:
    BorderCell():_cell(GridCell(0,0)),_maskDir(BorderMaskType::border_row){}
    BorderCell(const GridCell& cell,BorderMaskType type):_cell(cell),_maskDir(type){}
    BorderCell(const GridCell& cell):_cell(cell),_maskDir(BorderMaskType::border_row){}
    BorderCell(BorderMaskType type):_cell(GridCell(0,0)),_maskDir(type){}
    BorderCell(const BorderCell& border)
    {
        _cell = border._cell;_maskDir= border._maskDir;
    }
    BorderCell getNextBorderCell();
    BorderCell getPreBorderCell();
    BorderDirection getNextBorderDirection(bool  i= true);
    BorderDirection getPreBorderDirection(bool i = true);
    GridCell getNextMapCell();
    GridCell getPreMapCell();
    
    GridCell getNextMapCell(bool isUpper);
    GridCell getNextMapCell1(bool clockwise);
    
    bool isNearBorderCell(const BorderCell& cell,bool* isNext=NULL);
    void operator = (const BorderCell&  cell)
    {
        _cell= cell._cell;
        _maskDir = cell._maskDir;
    }
    bool operator == (const BorderCell&  cell)
    {
        return (_cell== cell._cell) && (_maskDir == cell._maskDir);
    }
    
    bool operator == (const BorderCell&  cell)const
    {
        return (_cell== cell._cell) && (_maskDir == cell._maskDir);
    }
    bool operator == (const GridCell&  cell)
    {
        return _cell== cell;
    }
    
    bool operator == (const GridCell&  cell)const
    {
        return _cell== cell;
    }
    
    bool operator < (const BorderCell& borderCell)
    {
        return _cell < borderCell._cell;
    }
    bool operator < (const BorderCell& borderCell) const
    {
        return _cell < borderCell._cell;
    }
    static bool isValidBorderCell(BorderMaskType type);
    
    GridCell _cell;
    BorderMaskType _maskDir;
    
    static std::map<unsigned char,LineDirContext> _sDirTable;
};
class GameBorderLine
{
public:
    bool  isRing();
    GameBorderLine(){}
    GameBorderLine(const GameBorderLine& line)
    {
        _borderList = line._borderList;
    }
    GameBorderLine(const GameBorderLine&& line)
    {
        _borderList = std::move(line._borderList);
    }
    static std::list<GameBorderLine>  getBorderlines(const std::list<BorderCell>&);
    void push_back(const BorderCell& );
    void push_fornt(const BorderCell& );
    BorderCell&  getFirstBorderCell()  ;
    BorderCell&  getLastBorderCell() ;
    
    
    
    bool isHasBorderCell(const BorderCell& );
    
    GameBorderLine subBorderLineByCell(const BorderCell& );
    
    void mergeBorderLine();
    
    bool isLinkBorderLine( GameBorderLine& borderLine) ;
    
    bool LinkBorderLine( GameBorderLine& borderLine);
    
    std::list<BorderCell> _borderList;
};

#endif /* defined(__Grow_Demo_test__GameBorderLine__) */
