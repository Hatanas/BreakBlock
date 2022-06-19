//
//  TetrisObject.cpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/05.
//

#include "TetrisObject.hpp"

namespace breakblock::model::tetris::tetrisobjects {

using namespace breakblock::model::tetris::tetrisobjects;

TetrisObject::TetrisObject(BlockMap const &blocks):blocks(blocks){}

/// このテトリスオブジェクトと指定されたテトリスオブジェクトが同じ座標のブロックを持つ場合，trueを返す
bool TetrisObject::overlapsWith(TetrisObject const &other)const{
    for (auto const&[cellIndex, blockType] : other.blocks) {
        if(blocks.count(cellIndex)){
            return true;
        }
    }
    return false;
}

}
