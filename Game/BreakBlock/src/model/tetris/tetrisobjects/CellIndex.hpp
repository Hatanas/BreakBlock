//
//  CellIndex.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#ifndef CellIndex_hpp
#define CellIndex_hpp


namespace breakblock::model::tetris::tetrisobjects {

struct CellIndex
{
    struct Hasher
    {
        int operator()(CellIndex const &cellIndex) const
        {
            return cellIndex.row * 31 + cellIndex.column;
        }
    };
    
    int row;
    
    int column;
    
    bool operator==(CellIndex const&other) const {
        return row == other.row && column == other.column;
    }
};

}

#endif /* CellIndex_hpp */
