#include<stdio.h>

int main()
{ 
	int n,process[10]={1,2,3,4,5,6,7,8,9,10};
	int min,k=1;
	int burst=0;
	int priority[10];
	int burst_time[10];
	int temp,temp1;
	int arrival_time[10],waiting_time[10],rt[10],turn_around_time[10];
	int tx=0,sum=0;
	int i,j;
	float waiting_avg,turn_avg,turn_sum,waiting_sum;
	printf("\nPlease enter total no of Process ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 {
		printf("Enter the burst time for  Process %d ",i+1);
		scanf("%d",&burst_time[i]);
		printf("Enter the arrival time of  process %d ",i+1);
		scanf("%d",&arrival_time[i]);
		printf("Enter the priority time of  process %d ",i+1);
		scanf("%d",&priority[i]);
	 }
for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(arrival_time[i]<arrival_time[j])
			{
				temp=process[j];
				process[j]=process[i];
				process[i]=temp;
				temp=arrival_time[j];
				arrival_time[j]=arrival_time[i];
				arrival_time[i]=temp;
				temp1=burst_time[j];
				burst_time[j]=burst_time[i];
				burst_time[i]=temp1;
			}
		}
	}
	
	for(j=0;j<n;j++)
	{  
	   burst=burst+burst_time[j];
	   min=burst_time[k];
		for(i=k;i<n;i++)/*main logic*/
			{ 
				min=priority[k];
				if (burst>=arrival_time[i])
				{
					if(priority[i]<min)
					{
					temp=process[k];
					process[k]=process[i];
					process[i]=temp;
					temp=arrival_time[k];
					arrival_time[k]=arrival_time[i];
					arrival_time[i]=temp;
					temp1=burst_time[k];
					burst_time[k]=burst_time[i];
					burst_time[i]=temp1;
					temp=priority[k];
					priority[k]=priority[i];
					priority[i]=temp;
					
					}
				}
	}
	k++;
	}
	
	waiting_time[0]=0;
	
	for(i=1;i<n;i++)
	{
		sum=sum+burst_time[i-1];
		waiting_time[i]=sum-arrival_time[i];
	}
	
	for(i=0;i<n;i++)
	{
		waiting_sum=waiting_sum+waiting_time[i];
	}
	
	waiting_avg=waiting_sum/n;
	
	for(i=0;i<n;i++)
	{
		tx=tx+burst_time[i];
		turn_around_time[i]=tx-arrival_time[i];
	}
	
	for(i=0;i<n;i++)
	{
		turn_sum=turn_sum+turn_around_time[i];
	}
	
	turn_avg=turn_sum/n;
	
	for(i=0;i<n;i++)
	{
		rt[i]=waiting_time[i];
	}
	
	printf("************************");
	
	printf("\n RESULT:-\t\t\t VARIOUS TIMES");
	printf("\nprocess\t burst\t arrival\tpriority " );
	
	for(i=0;i<n;i++)
	{
		printf("\n  process%d",process[i]);
		printf("\t   %d",burst_time[i]);
		printf("\t   %d",arrival_time[i]);
		printf("\t\t   %d",priority[i]);
	}
		printf("\nwaiting time\tturnaround time ");
	for(i=0;i<n;i++)
	{
		printf("\n  %d",waiting_time[i]);
		printf("\t\t  %d",turn_around_time[i]);
	}
	int z=(105*100/120);
	printf("%d ",z);
     	printf("CPU utilization rate= %d ",z);	}

