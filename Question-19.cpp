#include<stdio.h>
int find_max_index(int a[])
{
	
	int maxindex = 0;
	for(int i=0; i<10; i++)
	{
		if(a[maxindex] < a[i])
		{
			maxindex = i;
		}
	}
	return maxindex;
}
int main()
{
	int no_of_gifts[10], no_of_gifts_d[10]; 
	int s[10];
	printf("Enter number of gifts for students: \n");
	for(int i=0; i<10; i++)
	{
		printf("Student[%d] : ",i+1);
		scanf("%d",&no_of_gifts[i]); 
		no_of_gifts_d[i] = no_of_gifts[i];
	}
	
	for(int i=0; i<10 ; i++)
	{
		int max_index = find_max_index(no_of_gifts);
		s[i] = max_index+1;
		no_of_gifts[max_index] = -1;
	}
	printf("\n*******************************************\n");
	printf("\nOrder of billing is: \n");
	for(int i=0; i<10; i++)
	{
		printf("Student[%d]  -  %d\n",s[i], no_of_gifts_d[s[i]-1]);
	}
	printf("\n");
	printf("**********************************************");
	printf("\n");
}

