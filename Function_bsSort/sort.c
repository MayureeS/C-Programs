/*
 * sort.c
 *
 *  Created on: 21-Nov-2019
 *      Author: hp
 */
#include <stdio.h>
#include <string.h>
void bubble_sort(char fa[]);
void insertion_sort(char fa[]);
int main(void)
{
	char a[20] = {'\0'};
	int c = 0 ;
	int cnt = 0 ;
	do
	{
		printf("\n\t MENU");
		printf("\n\t 1.Sort a new string");
		printf("\n\t 2.Exit");
		printf("\n\t Enter your choice=");
		scanf("%d" , &c);
		switch(c)
		{
		case 1 :
			printf("Enter the string here:");
			scanf("%19s" , a);
			do
			{
				printf("\n\n MENU");
				printf("\n 1.Sort string in ascending order");
				printf("\n 2.Sort string in descending order");
				printf("\n 3.Return to main menu");
				printf("\n Enter your choice =");
				scanf("%d" , &cnt);
				switch(cnt)
				{
					case 1 :
						bubble_sort(a);
						printf("\n SORTED DATA : \n");
						printf(" %s\n " , a);
						break ;
					case 2 :
						printf("\n");
						printf("\n SORTED ARRAY = ");
						printf("%s " , a);
						break ;
				}
			}while(cnt != 3);
			break ;
		case 2 :
			printf("\n\t Thank you...");
			break ;
		}
	}while(c != 2);
	return 0 ;
}
void bubble_sort(char fa[] )
{
	int n = 0 ;
	int i = 0 ;
	int flag = 0 ;
	int j = 0 ;
	char t = '\0';
	n = strlen(fa);
	for(i=0 ; i < n ; ++i)
	{
		if(fa[i] > fa[i+1])
		{
			flag = 1 ;
			i = n ;
		}
	}
	if(flag == 1 )
	{
		for(j=0 ; j < n-1 ; ++j)
		{
			printf("\n");
			printf("PASS =  %d\n" , j+1);
			for(i=0 ; i < n-j-1 ; ++i)
			{
				if(fa[i] > fa[i+1])
				{
					t = fa[i] ;
					fa[i] = fa[i+1] ;
					fa[i+1] = t ;
				}
				printf(" %s " , fa);
				printf("\n");
			}
		}
	}
}
void insertion_sort(char fa[])
{
	int n = 0 ;
	int minpos = 0 ;
	char min = '\0';
	char t = '\0';
	int i = 0 ;
	int j = 0 ;
	n = strlen(fa);
	printf("BEFORE");
	printf("\n");
	printf("%s" , fa);
	for(i=0 ; i<n-1 ; ++i)
	{
		printf("\n\n");
		printf("PASS = %d" , i+1);
		printf("\n");
		min = fa[i];
		minpos = i;
		printf("MIN INTIAL = %c" , min);
		printf("\n");
		printf("MINPOS INTIAL = %d" , minpos);
		for(j = i+1 ; j<n ; j++)
		{
			if(min < fa[j])
			{
				min = fa[j];
				minpos = j;
			}
		}
		if(i!=minpos)
		{
			t = fa[i];
			fa[i] = fa[minpos];
			fa[minpos] = t;
		}
		printf("\n");
		printf("MIN = %c " , fa[i]);
		printf("MINPOS = %d" , minpos);
		printf("\n");
		printf("%s  " , fa);
	}
}
