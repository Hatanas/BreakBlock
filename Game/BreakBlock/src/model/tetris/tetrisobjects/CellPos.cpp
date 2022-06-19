//
//  CellIndex.cpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#include "CellPos.hpp"

namespace breakblock::model::tetris::tetrisobjects {

bool CellPos::operator==(CellPos const&other) const {
    return row == other.row && col == other.col;
}

int CellPos::Hasher::operator()(CellPos const&cellPos) const {
    return cellPos.row * 31 + cellPos.col;}

}
