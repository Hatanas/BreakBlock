//
//  TetrisObject.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/05.
//

#ifndef TetrisObject_hpp
#define TetrisObject_hpp

#include <unordered_map>
#include <unordered_set>

#include "BlockType.hpp"
#include "CellPos.hpp"

namespace breakblock::model::tetris::tetrisobjects {

using namespace breakblock::model::tetris::tetrisobjects;

struct TetrisObject
{
    using BlockMap = std::unordered_map<CellPos, BlockType, CellPos::Hasher>;

    BlockMap blocks;
    
    TetrisObject(BlockMap const &blocks = BlockMap{}):blocks(blocks){}
    TetrisObject(TetrisObject const &) = default;
    TetrisObject(TetrisObject &&) = default;
    TetrisObject &operator=(TetrisObject const &) = default;
    TetrisObject &operator=(TetrisObject &&) = default;
    ~TetrisObject() = default;

    bool collidesWith(TetrisObject const &other)const{
        for (auto const&[cellIndex, blockType] : other.blocks) {
            if(blocks.count(cellIndex)){
                return true;
            }
        }
        return false;
    }
    
    void mergeIfAbsent(TetrisObject const &other) {
        for (auto const&[cellIndex, blockType] : other.blocks) {
            if(blocks.count(cellIndex)) continue;
            blocks.insert({cellIndex, blockType});
        }
    }
    
    void remove(TetrisObject const &other) {
        for (auto const&[cellIndex, blockType] : other.blocks) {
            blocks.erase(cellIndex);
        }
    }
    
};
}
#endif /* TetrisObject_hpp */
