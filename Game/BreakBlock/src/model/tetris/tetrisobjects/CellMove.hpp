//
//  CellMove.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#ifndef CellMove_hpp
#define CellMove_hpp

namespace breakblock::model::tetris::tetrisobjects {

/// マトリックス上のベクトル
struct CellMove {
    
    int rowDelta;
    
    int colDelta;
    
    bool operator==(CellMove const&other) const;
    
    CellMove operator+()const;
    
    CellMove operator-()const;
    
    CellMove &operator+=(CellMove const&other);
    
    CellMove &operator-=(CellMove const&other);
    
    CellMove operator+(CellMove const&other)const;
    
    CellMove operator-(CellMove const&other)const;
};

}
#endif /* CellMove_hpp */
