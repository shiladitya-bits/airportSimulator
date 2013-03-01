#include "header.h"
void inputAll(passenger *plist,int num)
{
	int i,j,k;
	char tmp[20];
	FILE *fp = fopen("input.txt","r");	
	fscanf(fp," %d",&num);
	i=0;
	for(i=0;i<num;i++)
	{
		fscanf(fp,"%d",&(plist[i].ret_flag)); // return flight?
		//scan entry time
		fscanf(fp,"%s",tmp);
		plist[i].etime.hour = atoi(tmp);
		plist[i].etime.min = atoi(&tmp[3]);
		
		//scan entry date
		fscanf(fp,"%s",tmp);
		plist[i].edate.dd = atoi(tmp);
		plist[i].edate.mm = atoi(&tmp[3]);
		plist[i].edate.yy = atoi(&tmp[6]);
				
		fscanf(fp,"%s",plist[i].flt.ticket_no);//ticket		
		fscanf(fp,"%s",plist[i].flt.flt_no);//flight number
		//scan flight time
		fscanf(fp,"%s",tmp);
		plist[i].flt.ftime.hour = atoi(tmp);
		plist[i].flt.ftime.min = atoi(&tmp[3]);
				
		//scan flight date
		fscanf(fp,"%s",tmp);
		plist[i].flt.fdate.dd = atoi(tmp);
		plist[i].flt.fdate.mm = atoi(&tmp[3]);
		plist[i].flt.fdate.yy = atoi(&tmp[6]);		
		fscanf(fp,"%s",plist[i].flt.destination); //dest
			
		//return ticket
		if(plist[i].ret_flag)
		{
			fscanf(fp,"%s",plist[i].ret_flt.ticket_no);//return ticket		
			fscanf(fp,"%s",plist[i].ret_flt.flt_no);//return flight number
			//scan return flight time
			fscanf(fp,"%s",tmp);
			plist[i].ret_flt.ftime.hour = atoi(tmp);
			plist[i].ret_flt.ftime.min = atoi(&tmp[3]);
				
			//scan flight date
			fscanf(fp,"%s",tmp);		
			plist[i].ret_flt.fdate.dd = atoi(tmp);
			plist[i].ret_flt.fdate.mm = atoi(&tmp[3]);
			plist[i].ret_flt.fdate.yy = atoi(&tmp[6]);		
			fscanf(fp,"%s",plist[i].ret_flt.destination); //return to
		}		
		//passport details
		fscanf(fp,"%s",plist[i].passNo);
		fscanf(fp,"%s",tmp);
		plist[i].pass_exp.dd = atoi(tmp);
		plist[i].pass_exp.mm = 	atoi(&tmp[3]);
		plist[i].pass_exp.yy = atoi(&tmp[6]);
		fscanf(fp,"%s",plist[i].nation);	
		//visa details
		fscanf(fp,"%s",tmp);
		plist[i].visa_exp.dd = atoi(tmp);
		plist[i].visa_exp.mm = 	atoi(&tmp[3]);
		plist[i].visa_exp.yy = atoi(&tmp[6]);
		fscanf(fp,"%s",plist[i].visa_country);
		
		//personal details
		fscanf(fp,"%s",plist[i].fname);
		fscanf(fp,"%s",plist[i].lname);
		fscanf(fp," %c",&plist[i].gender);
		fscanf(fp,"%d",&plist[i].age);	
		//number of bags
		fscanf(fp,"%d",&plist[i].num_bags);
		int nbag = plist[i].num_bags;
		plist[i].wt_bags = (int *)malloc(nbag*sizeof(int));
		plist[i].content = (int **)malloc(nbag*sizeof(int *));
		//plist[i].explosives = (int **)malloc(nbag*sizeof(int *));
				
		//weight of each bag		
		for(j=0;j<nbag;j++)
		{
			fscanf(fp,"%d",&(plist[i].wt_bags[j]));
		}
		//contents of each bag
		for(j=0;j<nbag;j++)
		{
			plist[i].content[j] = (int *)malloc(10*sizeof(int));
			//plist[i].explosives[j] = (int *)malloc(10*sizeof(int));
			
			for(k=0;k<10;k++)
			{
				fscanf(fp,"%d",&(plist[i].content[j][k]));
			}
			
		}
				
	}
	fclose(fp);
	
}
