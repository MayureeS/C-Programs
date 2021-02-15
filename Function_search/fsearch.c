/*
 * fsearch.c
 *
 *  Created on: 25-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
struct string
{
	char a[20] ;
};
int linear(struct string fs[] , int n ,char fb[]);
int binary(struct string fs[] , int n , char fb[]);
int main(void)
{
	struct string *st = NULL ;
	int n = 0 ;
	int i = 0 ;
	int c = 0 ;
	int flag = 0 ;
	char b[20] ={'\0'};
	do
	{
		printf("Enter the number of strings =");
		scanf("%d" , &n);
	}while(n <= 0);
	st = (struct string*)calloc(n , sizeof(struct string));
	if(st == NULL)
	{
		printf("Memory allocation failed");
	}
	else
	{
		printf("Enter the strings here:");
		for(i=0 ; i < n ; ++i)
		{
			printf("Enter string %d:" , i + 1);
			scanf("%19s" , st[i].a);
		}
		do
		{
			printf("\n\t MENU");
			printf("\n\t 1.Search a string by linear search");
			printf("\n\t 2.Search a string by binary search");
			printf("\n\t 3.Enter another set of strings");
			printf("\n\t 4.Exit");
			printf("\n\t Enter your choice =");
			scanf("%d" , &c);
			if(c==1 || c==2)
			{
				printf("Enter the string to be searched");
				scanf("%19s" , b);
			}
			switch(c)
			{
			case 1 :
				flag = linear(st , n , b);
				if(flag == 0)
				{
					printf("\n STRING FOUND");
				}
				else
				{
					printf("\n STRING NOT FOUND");
				}
				break ;
			case 2 :
				flag = binary(st , n , b);
				if(flag == 0)
				{
					printf("\n STRING FOUND");
				}
				else
				{
					printf("\n STRING NOT FOUND");
				}
				break ;
			}
		}while(c != 4);
	}
	return 0 ;
}
int linear(struct string fs[] , int n , char fb[])
{
	int i = 0 ;
	int flag = 0 ;
	for(i = 0 ; i < n ; ++i)
	{
		flag = strcmp(fb , fs[i].a);
		if(flag == 0)
		{
			i = n ;
		}
	}
	return flag ;
}
int binary(struct string fs[] , int n , char fb[])
{
	int high = 0 ;
	int low = 0 ;
	int mid = 0 ;
	int flag = 0 ;
	high =  n - 1 ;
	low = 0 ;
	while(low <= high)
	{
		mid = (low + high) / 2 ;
		flag = strcmp(fb , fs[mid].a);
		if(flag == 0)
		{
			low = high + 1 ;
		}
		else
		{
			if(flag > 0)
			{
				low = mid + 1 ;
			}
			else
			{
				high = mid - 1 ;
			}
		}
	}
	return flag ;
}
