#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;
using Student::KingPiece;

KingPiece::KingPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){
    mType = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
    return true;
}

const char* KingPiece::toString() {
    return NULL;
}