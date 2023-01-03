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
  for( int col = 0; col < n-1; col++ ) { // col - przemieszczamy się po colch, n-1 bez ostatniej
 	double maxWartosc = fabs(mat->data[col][col]); 
	int maxWartoscIndex = col; 
	
	for( int row = col+1; row < n; row++) {
      if(fabs(mat->data[row][col]) > maxWartosc) {
		maxWartoscIndex = row;
		maxWartosc = mat->data[row][col];
		for( int i= 0; i < n; i++) {
			double *tmpMat = malloc(n * sizeof (double));
			tmpMat[i] = mat->data[col][i];
			mat->data[col][i] = mat->data[maxWartoscIndex][i];
			mat->data[maxWartoscIndex][i]= tmpMat[i];
			free(tmpMat);
		}
		double tmpB;
		tmpB = b->data[col][0];
		b->data[col][0] = b->data[maxWartoscIndex][0]; 
		b->data[maxWartoscIndex][0] = tmpB;
	  }
	}
	 

  	 for( int row = col+1; row < n; row++){ // row - przemieszczamy się po wierszach
       if( mat->data[col][col] == 0)
	     return 1;
	   double ratio = mat->data[row][col] / mat->data[col][col]; // colsub - przemieszczenie po colch celem substrakcji
	   for( int colsub = 0; colsub < n; colsub++)
		 mat->data[row][colsub] -= ratio * mat->data[col][colsub];
	   b->data[row][0] -= ratio*b->data[col][0];
	 } 
  	
  }
return 0;
}