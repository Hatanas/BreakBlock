//
//  CellGeometry.cpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#include "CellGeometry.hpp"

namespace breakblock::model::tetris::tetrisobjects {

CellPos operator+(CellPos const &l, CellMove const &r) {
    return CellPos{l.row + r.rowDelta, l.col + r.colDelta};
}

CellPos operator+(CellMove const &l, CellPos const &r) {
    return r + l;;
}

CellPos operator-(CellPos const &l, CellMove const &r) {
    return l + (-r);
}

CellMove operator-(CellPos const &l, CellPos const &r) {
    return CellMove{l.row - r.row, l.col - r.col};
}

}
