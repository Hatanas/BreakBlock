//
//  CellPos.hpp
//  BreakBlock
//
//  Created by Jumpaku on 2022/06/19.
//

#ifndef CellPos_hpp
#define CellPos_hpp


namespace breakblock::model::tetris::tetrisobjects {

struct CellPos
{
    struct Hasher
    {
        int operator()(CellPos const &cellPos) const
        {
            return cellPos.row * 31 + cellPos.col;
        }
    };
    
    int row;
    
    int col;
    
    bool operator==(CellPos const&other) const {
        return row == other.row && col == other.col;
    }
};

}

#endif /* CellPos_hpp */
