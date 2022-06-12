//
//  TetrisObject.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/05.
//

#ifndef TetrisObject_hpp
#define TetrisObject_hpp

#include <unordered_map>

namespace breakblock::model::tetris::tetrisobjects {

enum BlockType
{
    Default,
};

struct CellIndex
{
    int row;
    int column;
    struct Hasher
    {
        int operator()(CellIndex const &cellIndex) const
        {
            return cellIndex.row * 31 + cellIndex.column;
        }
    };
    bool operator==(CellIndex const&other)const{
        return row == other.row && column == other.column;
    }
};

struct TetrisObject
{
    std::unordered_map<CellIndex, BlockType, CellIndex::Hasher> blocks;
    bool intersects(TetrisObject const&other)const{
        TetrisObject out;
        for (auto const&[cellIndex, blockType] : blocks) {
            if(other.blocks.find(cellIndex) != other.blocks.end()){
                out.blocks.insert({cellIndex, blockType});
            }
        }
        return out.blocks.size() > 0;
    }
    TetrisObject merge(TetrisObject const&other)const{
        TetrisObject out = *this;
        for (auto const&[cellIndex, blockType] : blocks) {
            out.blocks.insert({cellIndex, blockType});
        }
        return out;
    }
    
};
}
#endif /* TetrisObject_hpp */
