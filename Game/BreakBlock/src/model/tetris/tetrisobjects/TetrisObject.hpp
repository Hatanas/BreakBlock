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
#include <concepts>

#include "BlockType.hpp"
#include "CellPos.hpp"

namespace breakblock::model::tetris::tetrisobjects {

using namespace breakblock::model::tetris::tetrisobjects;


using BlockMap = std::unordered_map<CellPos, BlockType, CellPos::Hasher>;

class TetrisObject;
template <class X>
concept ModifiedTetrisObject =
    requires(X &x){ X(std::declval<BlockMap>()); } &&
    std::is_base_of_v<X, TetrisObject>;

/// テトリスブロック集合のベースクラス
class TetrisObject
{
protected:
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
    template<ModifiedTetrisObject Out = TetrisObject>
    Out mergeIfAbsent(TetrisObject const &other) const {
        auto out = blocks;
        for (auto const&[cellIndex, blockType] : other.blocks) {
            if(out.count(cellIndex)) continue;
            out.insert({cellIndex, blockType});
        }
        return Out(out);
    }
    
    /// このテトリスオブジェクトが持つブロックを，指定されたテトリスオブジェクトも持っている場合，それを削除した新しい
    template<ModifiedTetrisObject Out = TetrisObject>
    Out remove(TetrisObject const &other) const {
        auto out = blocks;
        for (auto const&[cellIndex, blockType] : other.blocks) {
            out.erase(cellIndex);
        }
        return Out(out);
    }
};
}
#endif /* TetrisObject_hpp */
