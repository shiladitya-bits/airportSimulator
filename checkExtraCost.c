#include "header.h"
int checkExtraCost(passenger p)
{
	int n = p.num_bags;
	int extra = (n-3>0)? 40*(n-3):0;
	while(n)
	{
		if(p.wt_bags[n-1] > 20)
			extra = extra + (p.wt_bags[n-1] - 20) *2;
		n--;
	}
	return extra;
}
