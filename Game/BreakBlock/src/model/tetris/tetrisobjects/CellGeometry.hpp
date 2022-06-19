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

CellPos operator+(CellPos const &l, CellMove const &r);

CellPos operator+(CellMove const &l, CellPos const &r);

CellPos operator-(CellPos const &l, CellMove const &r);

CellMove operator-(CellPos const &l, CellPos const &r);

}
#endif /* CellGeometry_hpp */
