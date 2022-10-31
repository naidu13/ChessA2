#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;


ChessPiece::ChessPiece(ChessBoard& board, Color color, int row, int column) : mBoard(board){
    mColor = color;
    mRow = row;
    mColumn = column;
}


Color ChessPiece::getColor(){
    return mColor;
}

Type ChessPiece::getType(){
    return mType;
}

int ChessPiece::getRow(){
    return mRow;
}

int ChessPiece::getColumn(){
    return mColumn;
}

void ChessPiece::setPosition(int row, int column){
    mRow = row;
    mColumn = column;
}




