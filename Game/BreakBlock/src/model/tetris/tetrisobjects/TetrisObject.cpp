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

/// このテトリスオブジェクトが持たないブロックを，指定されたテトリスオブジェクトが持っている場合，それを追加する
void TetrisObject::mergeIfAbsent(TetrisObject const &other) {
    for (auto const&[cellIndex, blockType] : other.blocks) {
        if(blocks.count(cellIndex)) continue;
        blocks.insert({cellIndex, blockType});
    }
}

/// このテトリスオブジェクトが持つブロックを，指定されたテトリスオブジェクトも持っている場合，それを削除する
void TetrisObject::remove(TetrisObject const &other) {
    for (auto const&[cellIndex, blockType] : other.blocks) {
        blocks.erase(cellIndex);
    }
}

}
