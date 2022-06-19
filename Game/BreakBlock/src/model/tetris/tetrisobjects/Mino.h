#ifndef MINO_HPP
#define MINO_HPP

#include<concepts>
#include "TetrisObject.hpp"
#include "CellMove.hpp"

namespace breakblock::model::tetris::tetrisobjects
{
/// <summary>
/// ミノの向きを表す
/// </summary>
enum Facing
{
    NORTH,
    EAST,
    WEST,
    SOUTH
};
/// <summary>
/// テトリスのミノを表す
/// </summary>
template<class Self>
class Mino : public TetrisObject
{
protected:
    /// <summary>
    /// 基準点の座標値
    /// </summary>
    CellPos m_position;

    /// <summary>
    /// 向き
    /// </summary>
    Facing m_facing;
protected:
    Mino(BlockMap const& minoBlocks, const CellPos& pos, Facing facing) :
        TetrisObject(minoBlocks),
        m_position(pos),
        m_facing(facing) {}
    virtual ~Mino() = default;
public:
    /// <summary>
    /// 指定した分だけ移動したミノを取得する
    /// </summary>
    /// <param name="delta">移動量</param>
    Self moved(CellMove delta) const {
        BlockMap movedMinoBlocks;
        for (auto const& [pos, type] : blocks) {
            movedMinoBlocks[pos + delta] = type;
        }
        return Self(movedMinoBlocks, m_position + delta, m_facing);
    }

    /// <summary>
    /// 時計回りに回転したミノを取得する
    /// </summary>
    virtual Self rotated(bool clockwise) const = 0;
};
}
#endif  // MINO_HPP