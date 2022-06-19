//
//  CellMove.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#ifndef CellMove_hpp
#define CellMove_hpp

namespace breakblock::model::tetris::tetrisobjects {

struct CellMove {
    
    int rowDelta;
    
    int colDelta;
    
    bool operator==(CellMove const&other) const {
        return rowDelta == other.rowDelta && colDelta == other.colDelta;
    }
};

}
#endif /* CellMove_hpp */
