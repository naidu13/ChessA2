#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"

using Student::ChessBoard;
using Student::PawnPiece;


PawnPiece::PawnPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){
    mType = Pawn;
}


bool PawnPiece::isValidDiagonalMove(int toRow, int toColumn) {
    
    int row = getRow();
    int column = getColumn();
    Color color = getColor();

    if (color == White){
        if (((toRow - row) == -1) && (abs(toColumn - column) == 1)) {
            if (mBoard.isOccupiedWithColor(toRow, toColumn, Black) ){
                return true;
            }
        }
    }
    else if (color == Black){
        if (((toRow - row) == 1) && (abs(toColumn - column) == 1)) {
            if (mBoard.isOccupiedWithColor(toRow, toColumn, White)){
                return true;
            }
        }
    }
    return false;
}

bool PawnPiece::isValidRowMove(int toRow) {
    int numRows = mBoard.getNumRows();
    int row = getRow();
    int toColumn = getColumn();
    Color color = getColor();

    int diffRow = toRow - mRow;
    if(abs(diffRow) == 1){
        if(color == White && diffRow == -1){
            if(!mBoard.isOccupied(toRow, toColumn)){
                return true;
            }
        }
        if(color == Black && diffRow == 1){
            if(!mBoard.isOccupied(toRow, toColumn)){
                return true;
            }
        }
    }
    else if(abs(diffRow) == 2){
        if(color == White && diffRow == -2 && row == numRows - 2){
            if(!mBoard.isOccupied(toRow, toColumn) && !mBoard.isOccupied(toRow + 1, toColumn)){
                return true;
            }
        }
        if(color == Black && diffRow == 2 && row == 1){
            if(!mBoard.isOccupied(toRow, toColumn) && !mBoard.isOccupied(toRow - 1, toColumn)){
                return true;
            }
        }
    }
    return false;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
     
    int column = getColumn();

    if (isValidDiagonalMove(toRow, toColumn)){
        return true;
    }
    if (isValidRowMove(toRow) && column == toColumn){
        return true;
    }
    return false;
}

const char* PawnPiece::toString() {
    if (mColor == White) {
        return "\u2659";
    }

    return "\u265F";
}