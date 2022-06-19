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
    
    TetrisObject(BlockMap const &blocks = BlockMap{});
    TetrisObject(TetrisObject const &);
    TetrisObject(TetrisObject &&);
    TetrisObject &operator=(TetrisObject const &);
    TetrisObject &operator=(TetrisObject &&);
    ~TetrisObject();

    /// このテトリスオブジェクトと指定されたテトリスオブジェクトが同じ座標のブロックを持つ場合，trueを返す
    bool overlapsWith(TetrisObject const &other)const;
    
    /// このテトリスオブジェクトが持たないブロックを，指定されたテトリスオブジェクトが持っている場合，それを追加する
    void mergeIfAbsent(TetrisObject const &other);
    
    /// このテトリスオブジェクトが持つブロックを，指定されたテトリスオブジェクトも持っている場合，それを削除する
    void remove(TetrisObject const &other);
};
}
#endif /* TetrisObject_hpp */
