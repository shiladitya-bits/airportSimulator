#include "header.h"
void checkMFbag(passenger p)
{
	int n = p.num_bags,i,tmp;
	for(i=0;i<10;i++)
	{
		tmp = p.content[n-1][i];
		if(checkPalin(tmp) || colorful(tmp) || checkPrime(tmp))
		printf("%d ",p.content[n-1][i]);
	}
	printf("\n");		
}
int checkPrime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

