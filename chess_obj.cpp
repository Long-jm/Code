#include <iostream>
#include <sstream>
#include <string>

using Piece = char;

class ChessBoard {
  Piece err;         // if illegal position requested, return a reference to err
  Piece board[8][8];
public:

  ChessBoard() {    
    for (int i=0; i<8; i++)
      for (int j=0; j<8; j++)
	board[i][j] = '-';

    operator[]("A1") = 'R'; 
    operator[]("A8") = 'R'; 
    operator[]("H1") = 'R'; 
    operator[]("H8") = 'R';

    operator[]("B1") = 'N'; 
    operator[]("B8") = 'N'; 
    operator[]("G1") = 'N'; 
    operator[]("G8") = 'N';

    operator[]("C1") = 'B'; 
    operator[]("C8") = 'B'; 
    operator[]("F1") = 'B'; 
    operator[]("F8") = 'B';

    operator[]("D8") = 'Q'; 
    operator[]("D1") = 'Q'; 

    operator[]("E8") = 'K'; 
    operator[]("E1") = 'K';

    operator[]("A2") = 'P';
    operator[]("B2") = 'P';
    operator[]("C2") = 'P';
    operator[]("D2") = 'P';
    operator[]("E2") = 'P';
    operator[]("F2") = 'P';
    operator[]("G2") = 'P';
    operator[]("H2") = 'P';

    operator[]("A7") = 'P';
    operator[]("B7") = 'P';
    operator[]("C7") = 'P';
    operator[]("D7") = 'P';
    operator[]("E7") = 'P';
    operator[]("F7") = 'P';
    operator[]("G7") = 'P';
    operator[]("H7") = 'P';

    operator[]("XX") = '-'; 

  }

  char& operator[](std::string index) {
    
    int col = index[0]-'A';
    int row = index[1]-'1';
    if (col < 0 || col > 8) {
        return err;
    }
    if (row < 0 || row > 8) {
        return err;
    } 
    return board[col][row];
     // return err if index is illegal
    }
};

std::ostream& operator<< (std::ostream& out, ChessBoard &board)
{

  for (int j=8; j>=1; j--)
    {
      for (char i='A'; i<='H'; i++)
	{	  std::string s = i + std::to_string(j); 
	  out << board[ s ];
	}
      out << "\n";
    }
  return out;
}

int main()
{
  ChessBoard b;



  std::cout << b;
  
  return 0;
}