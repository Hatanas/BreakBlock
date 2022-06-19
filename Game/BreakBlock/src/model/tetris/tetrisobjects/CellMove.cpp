//
//  CellMove.cpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#include "CellMove.hpp"

namespace breakblock::model::tetris::tetrisobjects {

bool CellMove::operator==(CellMove const&other) const {
    return rowDelta == other.rowDelta && colDelta == other.colDelta;
}

CellMove CellMove::operator+()const{
    return *this;
}

CellMove CellMove::operator-()const {
    return CellMove{-rowDelta, -colDelta};
}

CellMove &CellMove::operator+=(CellMove const&other){
    rowDelta += other.rowDelta;
    colDelta += other.colDelta;
    return *this;
}

CellMove &CellMove::operator-=(CellMove const&other){
    return *this += -other;
}

CellMove CellMove::operator+(CellMove const&other)const {
    return CellMove(*this) += other;
}

CellMove CellMove::operator-(CellMove const&other)const {
    return CellMove(*this) -= other;
}

}
