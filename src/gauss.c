#include "gauss.h"
#include "mat_io.h"
#include <stdlib.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
  int n = mat->r;
  for( int col = 0; col < n-1; col++ ) { // col - przemieszczamy się po kolumnach, n-1 bez ostatniej
    int maxelindex = col; // index elementu maksymalnego
    double maxel = fabs(mat->data[col][col]); // maxel - element maksymalny
	for( int row = col+1; row < n; row++) {
      if(fabs(mat->data[row][col]) > maxel) {  // poszukiwanie elementów większych
		maxel = mat->data[row][col];
		maxelindex = row;
		for( int i= 0; i < n; i++) {                       // zamiana wierszy
			double *tmp = malloc(n * sizeof (double));
			tmp[i] = mat->data[col][i];
			mat->data[col][i] = mat->data[maxelindex][i];
			mat->data[maxelindex][i]= tmp[i];
			free(tmp);
		}
		double tmp2;
			tmp2 = b->data[col][0];
			b->data[col][0] = b->data[maxelindex][0];
			b->data[maxelindex][0] = tmp2;
	  }
	 }
  	 for( int row = col+1; row < n; row++){ // row - przemieszczamy się po wierszach
       if( mat->data[col][col] == 0)
	     return 1;
	   double ratio = mat->data[row][col] / mat->data[col][col]; // colsub - przemieszczenie po kolumnach celem substrakcji
	   for( int colsub = 0; colsub < n; colsub++)
		 mat->data[row][colsub] -= ratio * mat->data[col][colsub];
	   b->data[row][0] -= ratio*b->data[col][0];
	 } 
  }
return 0;
}