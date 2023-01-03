#include "gauss.h"
#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
  int n = mat->r;
  for( int col = 0; col < n-1; col++ ) { // col - przemieszczamy się po kolumnach, n-1 - bez ostatniej
  	 for( int row = col+1; row < n; row++){ // row - przemieszczamy się po wierszach
       if( mat->data[col][col] == 0)
	     return 1;
	   double ratio = mat->data[row][col] / mat->data[col][col]; // colsub - przemieszczenie po kolumnach celem substrakcji
	   for( int colsub = 0; colsub < n; colsub++)
		 mat->data[row][colsub] -= ratio * mat->data[col][colsub];
	   b->data[row][0] -= ratio*b->data[col][0];
	 } 
  }
  printToScreen(mat);
  printToScreen(b);
return 0;
}