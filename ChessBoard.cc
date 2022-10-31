#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol) {
  if(numRow != 0 || numCol != 0)
  {
    numRows = numRow;
    numCols = numCol; 
    board.resize(numRow);
    for(int i=0; i < numRow; i++){
      board[i].resize(numCol);
      for(int j=0; j < numCol; j++){
        board[i][j] = nullptr;
      }
    }
  }
}

ChessBoard::ChessBoard(ChessBoard& other) {
  numRows = other.numRows;
  numCols = other.numCols;
  if(!other.board.empty()){
    for(int i; i < numRows; i++){
      for(int j; j <numCols; j++){
      board[i][j] = other.board[i][j];
      }
    }
  }
}

ChessBoard::~ChessBoard() {
  for(int i=0; i < numRows; i++){
    for(int j=0; j < numCols; j++){
      delete board[i][j];
    }
  }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
  if(isOccupied(startRow, startColumn)){
    removeChessPiece(startRow, startColumn);
  }
  ChessPiece * piece;
  if (ty == Pawn){
    piece = new PawnPiece(*this, col, startRow, startColumn);
  }
  else if(ty == Bishop){
    piece = new BishopPiece(*this, col, startRow, startColumn);
  }
  else if(ty == Rook){
   piece = new RookPiece(*this, col, startRow, startColumn);
  }
  board[startRow][startColumn] = piece;
  if(col == White){
    whitePieces.push_back(piece);
  }
  else if(col == Black){
    blackPieces.push_back(piece);
  }
  return;
}

void ChessBoard::removeChessPiece(int row, int column) {
  ChessPiece* deletePiece = getPiece(row, column);
  Color color = deletePiece->getColor();
  if(color == White){
    whitePieces.remove(deletePiece);
  }
  else if(color == Black){
    blackPieces.remove(deletePiece);
  }
  delete deletePiece;
  board[row][column] = nullptr;
}

bool ChessBoard::isOccupied(int row, int column){
  ChessPiece * piece = getPiece(row, column);
  if(piece == nullptr){
    return false;
  }
  return true;
}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color) {
  ChessPiece * piece = getPiece(row, column);
  if(piece == nullptr){
    return false;
  }
  else if(piece->getColor() == color){
    return true;
  }
  else{
    return false;
  }
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  ChessPiece * piece = getPiece(fromRow, fromColumn);
  piece->setPosition(toRow, toColumn);
  if(isOccupied(toRow, toColumn)){
    removeChessPiece(toRow, toColumn);
  }
  board[toRow][toColumn] = piece;
  board[fromRow][fromColumn] = nullptr;

}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
  ChessPiece * piece = getPiece(fromRow, fromColumn);
  Color color = piece->getColor();

  if(isValidMove(fromRow, fromColumn, toRow, toColumn)){
    if(color == turn){
      forceMove(fromRow, fromColumn, toRow, toColumn);
      if(color == Black){
        turn = White;
      }
      else{
        turn = Black;
      }
      return true;
    }
  }

  return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  ChessPiece * piece = getPiece(fromRow, fromColumn);

  if(piece == nullptr){
    return false;
  }
  else if(fromRow == toRow && fromColumn == toColumn){
    return false;
  }
  else if(toRow >= numRows || toRow < 0){
    return false;
  }
  else if(toColumn >= numCols || toColumn < 0){
    return false;
  }
  else if(piece->canMoveToLocation(toRow, toColumn)){
    return true;
  }
  return false;
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
  /*ChessPiece * piece = getPiece(row, column);
  if(piece == nullptr){
    return false;
  }
  else if(piece->getColor() == White){
    int size = sizeof(blackPieces) / sizeof(blackPieces[0])
    for(int i; i < size; i++){
      if(blackPieces[i]->canMoveToLocation(row, column)){
        return true;
      }
    }
    return false;
  }
  else if(piece->getColor() == Black){
    size = sizeof(whitePieces) / sizeof(whitePieces[0])
    for(int i; i < size; i++){
      if(whitePieces[i]->canMoveToLocation(row, column)){
        return true;
      }
    }
    return false;
  }*/
  return false;

}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  return true;
}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
  // top scale
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << i;
  }
  outputString << std::endl << "  ";
  // top border
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl;

  for(int row = 0; row < numRows; row++) {
    outputString << row << "|";
    for(int column = 0; column < numCols; column++) {
      ChessPiece* piece = board.at(row).at(column);
      outputString << (piece == nullptr ? " " : piece->toString());
    }
    outputString << "|" << std::endl;
  }

  // bottom border
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl << std::endl;

  return outputString;
}
