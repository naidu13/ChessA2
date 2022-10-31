#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "RookPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;
using Student::RookPiece;

RookPiece::RookPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){
    mType = Rook;
}

bool RookPiece::isValidRowMove(int toRow) {
    int row = getRow();
    int col = getColumn();
    int checkRow = row;

    int incRow = (toRow - row) / abs(toRow - row);

    for(int i = 0; i < abs(toRow - row) - 1; i++){
        checkRow+= incRow;
        if(mBoard.isOccupied(checkRow, col)){
            return false;
        }
    }
    return true;  
}

bool RookPiece::isValidColumnMove(int toColumn) {
    int row = getRow();
    int col = getColumn();
    int checkCol = col;

    int incCol = (toColumn - col) / abs(toColumn - col);

    for(int i = 0; i < abs(toColumn - col) - 1; i++){
        checkCol += incCol;
        if(mBoard.isOccupied(row, checkCol)){
            return false;
        }
    }
    return true;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {

    int cRow = getRow();
    int cCol = getColumn();

    if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor())) {
        return false;
    }
    if((toRow - cRow) == 0){
        if(!isValidColumnMove(toColumn)){
            return false;
        }
        return true;
    }
    else if((toColumn - cCol) == 0){
        if(!isValidRowMove(toRow)){
            return false;
        }
        return true;
    }
    return false;
}

const char* RookPiece::toString() {
    if (getColor() == White) {
        return "\u2656";
    }

    return "\u265C";
}