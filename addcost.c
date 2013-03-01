#include "header.h"
void addCostoFile(passenger p,int cost)
{
	FILE *fout = fopen(p.flt.ticket_no,"a");
	fprintf(fout,"extra cost = %d\n",cost);
	fclose(fout);
}

