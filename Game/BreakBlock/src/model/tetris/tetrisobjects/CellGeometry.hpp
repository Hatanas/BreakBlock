//
//  CellGeometry.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#ifndef CellGeometry_hpp
#define CellGeometry_hpp

#include "CellPos.hpp"
#include "CellMove.hpp"

namespace breakblock::model::tetris::tetrisobjects {

using namespace breakblock::model::tetris::tetrisobjects;

CellMove operator+(CellMove const &m) {
    return m;
}

CellMove operator-(CellMove const &m) {
    return CellMove{-m.rowDelta, -m.colDelta};
}

CellMove operator+(CellMove const &l, CellMove const &r) {
    return CellMove{l.rowDelta + r.rowDelta, l.colDelta + r.colDelta};
}

CellPos operator+(CellMove const &l, CellPos const &r) {
    return CellPos{l.rowDelta + r.row, l.colDelta + r.col};
}

CellPos operator+(CellPos const &l, CellMove const &r) {
    return r + l;
}

CellPos operator-(CellPos const &l, CellMove const &r) {
    return l + (-r);
}

CellMove operator-(CellPos const &l, CellPos const &r) {
    return CellMove{l.row - r.row, l.col - r.col};
}

}
#endif /* CellGeometry_hpp */
