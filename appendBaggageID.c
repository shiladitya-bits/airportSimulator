#include "header.h"
static int id =1;
void appendBaggageID(passenger p)
{
	int i;
	int n= p.num_bags;
	FILE *fp = fopen(p.flt.ticket_no,"a");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"Baggage ID for bag %d\n",id);
		id++;
	}
	fclose(fp);
}
	
