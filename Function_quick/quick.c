/*
 * quick.c
 *
 *  Created on: 21-Nov-2019
 *      Author: hp
 */
#include <stdio.h>
#include<stdlib.h>
#include<stddef.h>
void quicksort(int a[], int first, int last) ;
int main(void)
{
	int *a = NULL ;
	int n= 0 ;
	int i = 0 ;
	do
	{
		printf("Enter number of elements in an array");
		scanf("%d" , &n);
	}while(n <= 0);
	a = (int *)calloc(n , sizeof(int));
	printf("Enter the array here \n");
	for(i=0 ; i < n ; ++i)
	{
		printf("Enter element %d =" ,i);
		scanf("%d" , &a[i]);
	}
	quicksort(a, 0, n-1) ;
	printf("\n");
	for(i=0 ; i < n ; ++i)
	{
		printf("%d \t" , a[i]);
	}
	return 0 ;
}
void quicksort(int a[],int first,int last)
{
	int pivot=0 ;
	int i=0 ;
	int j=0 ;
	int temp=0 ;
	if(first < last)
	{
		pivot = a[first];
		i = first;
		j = last;
		while(i < j)
		{
			while(a[i] <= pivot && i < last)
			{
				i++;
			}
			while(a[j] > pivot)
			{
				j--;
			}
			if(i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = pivot;
		a[first] = a[j];
		a[j] = temp;
		printf ("quicksort(a , %d , %d) \n\n)" ,first , last);
		for(i=0 ; i < last-1 ; ++i)
		{
			printf("%d \t" , a[i]);
		}
		printf("\n");
		quicksort(a, first, j-1);
		quicksort(a, j+1, last);
	}
}

