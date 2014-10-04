#ifndef __PlantOri__ContorlPoint__
#define __PlantOri__ContorlPoint__
#include "MathHelper.h"
#include "Macro.h"

class ContorlPoint
{
public:
    ContorlPoint(){}
    ContorlPoint(Vec3 point,float radius,float angle,float height):_point(point),_height(height),
    _angle(angle),_radius(radius){}
    
    Vec3  getContorlPosition(){return _point;}
    
    Vec3  getNextContorPosition( float angle);
    
    Vec3  getPositionLeft() const;
    
    Vec3  getPositionRight() const;
    
    Vec3  getPositionLeftByLength(float len) const
    {
        return getRotatePosition(_point,len,_angle);
    }
    
    Vec3  getPositionRightByLength(float len) const
    {
        return getRotatePosition(_point,len,_angle+180);
    }
    
    Vec3 getTopPositionByLength(float len) const;
    
    Vec3   _point;
    float  _angle;
    float  _radius;
    float  _height;  //保留
};

class ContorlPointV2
{
public:
    ContorlPointV2(){}
    ContorlPointV2(Vec2 point,float radius,float angle,float height,int zPosition =0):_point(point),_height(height),
    _angle(angle),_radius(radius),_zPosition(zPosition){}
    
    Vec2  getContorlPosition(){return _point;}
    
    Vec2  getNextContorPosition( float angle);
    
    Vec2  getPositionLeft() const;
    
    Vec2  getPositionRight() const;
    
    Vec2  getPositionLeftByLength(float len) const
    {
        return getRotatePosition(_point,len,_angle);
    }
    
    Vec2  getPositionRightByLength(float len) const
    {
        return getRotatePosition(_point,len,_angle+180);
    }
    
    Vec2 getTopPositionByLength(float len) const;
    
    int    _zPosition;
    Vec2   _point;
    float  _angle;
    float  _radius;
    float  _height;  //保留
};

#define MakeVec3(T,Z) Vec3(T.x,T.y,Z)
#endif /* defined(__PlantOri__ContorlPoint__) */
