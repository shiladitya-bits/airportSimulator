#include "header.h"
void checkLuggage(passenger *plist,int index)
{
	passenger p = plist[index];
	int i,j,tmp;
	for(j=0;j<p.num_bags;j++)
	{
		for(i=0;i<10;i++)
		{
			tmp = p.content[j][i];
			if(checkPalin(tmp) || colorful(tmp))
			{	
				p.explosives[j][i] = 1;
			}
			else p.explosives[j][i] == 0;
			
		}
	}
	
		
}
int checkPalin(int n)
{
	int rev=0,copy = n;
	while(copy > 0)
	{
		rev = rev*10+copy%10;
		copy/=10;
	}
	return (rev == n) ? 1:0;
}
int colorful(int n)
{
	int copy = n,len=0,i,j,k,protmp=1;
	int dig[10];
	int prod[100];
	while(copy>0)
	{
		if(copy%10 == 0 || copy%10 == 1)
			return 0;
		for(i=0;i<len;i++)
		{
			if(copy%10 == dig[i]) return 0;
		}
		dig[len] = copy%10; // checked for single digit repititions
		prod[len++] = copy%10;
		copy/=10;
	}
	int ptr = len;
	for(i=0;i<len;i++)             // i stands for starting digit
	{
		for(j=2;j<=len-i;j++)  // j stands for length of substring 
		{
			protmp=1;
			for(k=i;k<j+i;k++)  //this loop is for calculating the product
			{
				protmp = protmp * dig[k];
			}
			for(k=0;k<ptr;k++)
			{
				if(protmp == prod[k])
					return 0;
			}
			prod[ptr++] = protmp;
		}
	}	
	return 1;
}
