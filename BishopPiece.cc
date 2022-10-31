#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "BishopPiece.hh"

using Student::ChessBoard;
using Student::BishopPiece;

BishopPiece::BishopPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){
    mType = Bishop;
}

bool BishopPiece::isValidDiagonalMove(int toRow, int toColumn) {
    int row = getRow();
    int column = getColumn();

    int horz = toRow - row;
    int vert = toColumn - column;

    int aHorz = abs(horz);
    int aVert = abs(vert);

    if (aHorz != aVert || aHorz == 0 || aVert == 0) {
        return false;
    }

    int horzInc = horz / aHorz;
    int vertInc = vert / aVert;
    for(int i = 0; i < aHorz - 1; i++){
        row += horzInc;
        column += vertInc;
        if(mBoard.isOccupied(row, column)){
            return false;
        }
    }
     if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor())) {
        return false;
    }

    return true;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = mBoard.getNumRows();
    int column = mBoard.getNumCols();

    if (toRow < 0 || toColumn < 0 || toRow >= row || toColumn >= column) {
        return false;
    }
    if (!isValidDiagonalMove(toRow, toColumn)) {
        return false;
    }

    return true;
}

const char* BishopPiece::toString() {
    if (mColor == White) {
        return "\u2657";
    }

    return "\u265D";
}

