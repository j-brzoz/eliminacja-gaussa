#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
/**
* Tutaj należy umieścić właściwą implemntację.
 */
	if(mat->c != mat->r)
		return 2;

	int wymiar = mat->c;
	for(int wiersz = wymiar - 1; wiersz >= 0; wiersz--){
		double suma = 0;
		for(int kolumna = wiersz + 1; kolumna < wymiar; kolumna++)
			suma += mat->data[wiersz][kolumna] * x->data[kolumna][0];
		
		if(mat->data[wiersz][wiersz] == 0)
			return 1;

		x->data[wiersz][0] = (b->data[wiersz][0] - suma) / mat->data[wiersz][wiersz];
	}

/* To ponizej jest przepisaniem b do x. Nalezy to poprawic!
	int i;
	for (i =0; i < x->r; i++) {
		x->data[i][0] = b->data[i][0];
	}
 */
	return 0;
}



