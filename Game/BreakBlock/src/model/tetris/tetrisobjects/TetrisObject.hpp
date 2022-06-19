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

class TetrisObject
{
protected:
    using BlockMap = std::unordered_map<CellPos, BlockType, CellPos::Hasher>;

    BlockMap blocks;
    
public:
    TetrisObject(BlockMap const &blocks = BlockMap{});
    TetrisObject(TetrisObject const &) = default;
    TetrisObject(TetrisObject &&) = default;
    TetrisObject &operator=(TetrisObject const &) = default;
    TetrisObject &operator=(TetrisObject &&) = default;
    virtual ~TetrisObject() = default;

    /// このテトリスオブジェクトと指定されたテトリスオブジェクトが同じ座標のブロックを持つ場合，trueを返す
    bool overlapsWith(TetrisObject const &other) const;
    
    /// このテトリスオブジェクトが持たないブロックを，指定されたテトリスオブジェクトが持っている場合，それを追加する
    void mergeIfAbsent(TetrisObject const &other);
    
    /// このテトリスオブジェクトが持つブロックを，指定されたテトリスオブジェクトも持っている場合，それを削除する
    void remove(TetrisObject const &other);
};
}
#endif /* TetrisObject_hpp */
