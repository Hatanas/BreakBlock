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
#include "CellIndex.hpp"

namespace breakblock::model::tetris::tetrisobjects {

using namespace breakblock::model::tetris::tetrisobjects;

using BlockSet = std::unordered_set<CellIndex, CellIndex::Hasher>;

using BlockMap = std::unordered_map<CellIndex, BlockType, CellIndex::Hasher>;

template <class X>
concept FromBlockMap = requires(X&x){
    X(std::declval<BlockMap>());
};

struct TetrisObject
{
    BlockMap blocks;
    
    TetrisObject(BlockMap const &blocks = BlockMap{}):blocks(blocks){}
    TetrisObject(TetrisObject const &) = default;
    TetrisObject(TetrisObject &&) = default;
    TetrisObject &operator=(TetrisObject const &) = default;
    TetrisObject &operator=(TetrisObject &&) = default;
    
    bool collidesWith(TetrisObject const &other)const{
        for (auto const&[cellIndex, blockType] : other.blocks) {
            if(blocks.count(cellIndex)){
                return true;
            }
        }
        return false;
    }
    
    template<FromBlockMap OutTetrisObject = TetrisObject>
    OutTetrisObject mergeIfAbsent(TetrisObject const &other)const{
        BlockMap outBlocks = blocks;
        for (auto const&[cellIndex, blockType] : other.blocks) {
            if(outBlocks.count(cellIndex)) continue;
            outBlocks.insert({cellIndex, blockType});
        }
        return OutTetrisObject(outBlocks);
    }
    
    template<FromBlockMap OutTetrisObject = TetrisObject>
    OutTetrisObject remove(TetrisObject const &other) const {
        BlockMap outBlocks = blocks;
        for (auto const&[cellIndex, blockType] : other.blocks) {
            outBlocks.erase(cellIndex);
        }
        return OutTetrisObject(outBlocks);
    }
    
};
}
#endif /* TetrisObject_hpp */
