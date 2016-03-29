#include "Sudoku.h"

int main() {

	Sudoku<3>  foo("sudoku.dat")  ;
	if ( foo.find_solution() )   cout << "solution :\n" << foo << endl ;

	Sudoku<3>  bar("sudoku.dat2",Entire_Map)  ;
	if ( bar.find_solution() )   cout << "solution :\n" << bar << endl ;
    return 0 ;
}

