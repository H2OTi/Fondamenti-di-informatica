/*Una linea spezzata è una lista di punti (coordinate intere). Una linea spezzata aperta non degenere è tale se i suoi punti sono almeno due, 
e sono tutti diversi tra loro. Data una linea spezzata aperta non degenere, la sua lunghezza è la somma delle distanze euclidee tra i punti consecutivi
Date due linee spezzate aperte non degeneri A e B, A è una scorciatoia di B se hanno stesso punto di inizio e di fine e A è più corta di B.
Partendo dal tipo di dato punto_t riportato, si sviluppi un sottoprogramma scorciatoia che ricevute in ingresso due spezzate aperte non degenere 
restituisce 1 se la prima è una scorciatoia della seconda, 0 altrimenti.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _p {
       int x, y;
       struct _p * next;
} punto_t;

int scorciatoia(punto_t * a, punto_t * b)
{
	float somma_a, somma_b;
	punto_t* p, *lastb;

	somma_a = 0;
	somma_b = 0;

	for (p = a; p->next == NULL; p = p->next)
		;
	for (lastb = b; lastb->next == NULL; lastb = lastb->next)
		;

	if(((a->x != b->x || a->y != b->y) || (p->x != lastb->x || p->y != lastb->y)) && ((lastb->x != a->x || lastb->y != a->y) || (b->x != p->x || b->y != p->y )))
		return 0;

	for(p = a; p -> next != NULL; p = p -> next){
		somma_a = somma_a + (sqrt(pow(p->next->x - p->x, 2)+pow(p->next->y - p->y, 2)));
	}

	for(p = b; p->next != NULL; p = p->next){
		somma_b = somma_b + (sqrt(pow(p->next->x - p->x, 2)+pow(p->next->y - p->y, 2)));
	}

	if(somma_a < somma_b)
		return 1;

	return 0;

}