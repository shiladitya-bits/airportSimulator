#include "header.h"
static seatno=1000;
void makePass(passenger p)
{
	FILE *fout = fopen(p.flt.ticket_no,"w");
	char *meals[3]={"Vegetarian","Non-Vegetarian","Asian Vegetarian"};
	srand(time(NULL));
	int choice=rand()%3;
	
	fprintf(fout,"Name = %s %s\n",p.fname,p.lname);
	fprintf(fout,"Age= %d\n",p.age);
	fprintf(fout,"Gender= %c\n",p.gender);
	fprintf(fout,"Seat No= %d\n",seatno++);
	fprintf(fout,"Food choice= %s\n",meals[choice]);
	fclose(fout);
}
