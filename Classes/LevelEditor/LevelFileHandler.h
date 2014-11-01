//
//  LevelFileHandler.h
//  GrowUp
//
//  Created by wlg on 8/21/14.
//
//

#ifndef __GrowUp__LevelFileHandler__
#define __GrowUp__LevelFileHandler__

#include <iostream>
#include "Macro.h"
#include "Item.h"

class LevelFileHandler:public Ref
{
public:
    LevelFileHandler();
    ~LevelFileHandler();

    static LevelFileHandler* createWithFileName(const char* filename);
    bool init(const char* filename);
    
    void removeItemWithID(int id);
    int saveFile();
    void reload();
    
    std::list<Item> _items;
    __Dictionary* _polygonsDict;
    std::string _filename;
    
protected:
    void loadFile();
    
};
#endif /* defined(__GrowUp__LevelFileHandler__) */
