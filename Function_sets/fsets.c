/*
 * fsets.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stdlib.h>
int uni(int fa[] , int fb[] , int fu[] , int fca , int fcb);
int inter(int fa[] , int fb[] , int fin[] ,int fca , int fcb);
int diff(int fa[] , int fb[] , int fdiff[] , int fca , int fcb);
int sdiff(int fa[] , int fb[] , int fsdif[] , int fca , int fcb );
int constr( int fa[] , int fn1);
void display_set(int fs[] , int fc);
int menu();
int main(void)
{

	int *a = NULL ;
	int *b = NULL ;
	int *u = NULL ;
	int *in = NULL ;
	int *dif = NULL ;
	int *sdif = NULL ;
	int choice = 0 ;
	int ca = 0 ;
	int cb = 0 ;
	int m = 0 ;
	int cnt = 0 ;

	printf("For set A :\n");
	do
	{
		printf("How many elements are there in set ?");
		scanf("%d" , &m);
	}while(m <= 0);
	a = (int *)calloc(m , sizeof(int));
	ca = constr(a , m) ;

	printf("For set B :\n");
	do
	{
		printf("How many elements are there in set ?");
		scanf("%d" , &m);
	}while(m <= 0);
	b = (int *)calloc(m , sizeof(int));
	cb = constr(b , m) ;

	do
	{
		choice = menu() ;
		switch(choice)
		{
		case 1 :
			 printf(" The set A you entered is :");
			 display_set(a , ca);
			 printf("\n The set B you entered is :");
			 display_set(b , cb);
		break ;
		case 2 :
			u = (int *)calloc(ca+cb,sizeof(int));
			m = uni(a , b , u , ca , cb);
			printf(" The set A you entered is :");
			display_set(a , ca);
			printf("\n The set B you entered  is :");
			display_set(b , cb);
			printf("\n The union set entered is :");
			display_set(u , m);
			free(u);
			u = NULL ;
		break ;
		case 3 :
			in = (int *)calloc(ca+cb-m , sizeof(int));
			m = inter(a , b , in , ca , cb);
			printf(" The set A you entered is :");
			display_set(a , ca);
			printf("\n The set B you entered  is :");
			display_set(b , cb);
			printf("\n The intersection set =");
			display_set(in , m);
			free(in);
			in = NULL ;
		break ;
		case 4 :
		do
		{
			 printf("\n Menu");
			 printf("\n1 A - B");
			 printf("\n2 B - A");
			 printf("\n3 Go to main menu");
			 printf("\n\n Enter your choice =");
			 scanf("%d" , &cnt);
			 switch(cnt)
			 {
			 case 1 :
				dif = (int *)calloc(m-cb , sizeof(int));
				m = diff(a , b , dif , ca , cb );
				printf(" The set A you entered is :");
				display_set(a , ca);
				printf("\n The set B you entered  is :");
				display_set(b , cb);
				printf("\n The difference A - B =");
				display_set(dif , m);
				free(dif);
				dif = NULL ;
			 break ;
			 case 2 :
				dif = (int *)calloc(m-ca , sizeof(int));
				m = diff(b , a , dif , cb , ca );
				printf(" The set A you entered is :");
				display_set(a , ca);
				printf("\n The set B you entered  is :");
				display_set(b , cb);
				printf("\n The difference B - A =");
				display_set(dif , m);
				free(dif);
				dif = NULL ;
			 break ;
			 }
		}while(cnt != 3);
		break ;
		case 5 :
			sdif = (int *)calloc(m*2-ca-cb , sizeof(int));
			m = sdiff(a , b , sdif , ca , cb );
			printf(" The set A you entered is :");
			display_set(a , ca);
			printf("\n The set B you entered  is :");
			display_set(b , cb);
			printf("\n The symmetric difference set  is :");
			display_set(sdif , m);
			free(sdif);
			sdif = NULL ;
		break ;
		case 6 :
			main() ;
			break ;
		case 7 :
			free(a);
			a = NULL ;
			free(a);
			a = NULL ;
			printf("Thank you ...Good Bye !!");
			break ;
		}
	}while(choice != 7);
	return 0 ;
}
int constr( int fa[] , int fn1)
{
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	int flag = 0 ;
	int no = 0 ;
	printf("Enter the set elements =");
	for(j = 0 ;j < fn1 ;++j)
	{
		printf("\n\t Enter %d Element = " , i+1);
		scanf("%d" , &no);
		for(k = 0 ; k < i ; ++k)
		{
			 if(no == fa[k])
			 {
				   flag = 1 ;
				   k = i ;
			 }
			 else
			 {
				   flag = 0 ;
			 }
		}
		if(flag == 0)
		{
			fa[i] = no ;
			i = i + 1 ;
		}
	}
	return i ;
}
void display_set(int fs[] ,int fc)
{
	int j = 0 ;
	printf("{");
	while(j < fc)
	{
		if(j == fc-1)
		{
			printf("%d" , fs[j]);
			j = j + 1 ;
		}
		else
		{
			printf("%d," , fs[j]);
			j = j + 1 ;
		}

	}
	printf("}");
}
int menu()
{
	int choice = 0 ;
	printf("\n Menu") ;
	printf("\n 1 Print both sets");
	printf("\n 2 Print the union");
	printf("\n 3 Print the intersection");
	printf("\n 4 Print the difference ");
	printf("\n 5 Print the symmetric difference");
	printf("\n 6 Enter different pair of sets");
	printf("\n 7 Exit\n");
	printf("\n Enter your choice =\n");
	scanf("%d" , &choice);
	return choice ;
}
int uni(int fa[] , int fb[] , int fu[] , int fca , int fcb)
{
	int flag = 0 ;
	int j = 0 ;
	int m = 0 ;
	int i = 0 ;
	int fca1 = 0 ;
	int no = 0 ;
	fca1 = fca ;
	flag = 0 ;
	for(j = 0 ;j < fca ; ++j)
	{
		fu[j] = fa[j] ;
	}
	m = j  ;
	for(i = 0 ; i < fcb ; ++i)
	{
		no = fb[i] ;
		for(j = 0 ; j < fca1 ; ++j)
		{
			 if(no == fu[j])
			 {
				   flag  = 1 ;
				   j = fca1 ;
			 }
			 else
			 {
				   flag = 0 ;
			 }
		}
		if(flag == 0)
		{
			 fu[m] = no ;
			 m = m + 1 ;
		}
	}
	return m ;
}
int inter(int fa[] , int fb[] , int fi[] ,int fca , int fcb)
{
	int flag = 0;
	int m = 0 ;
	int i = 0 ;
	int j = 0 ;
	int no = 0 ;
	flag = 0 ;
	m = 0 ;
	i = 0 ;
	for(i = 0 ; i < fcb ; ++i)
	{
		no = fb[i] ;
		for(j = 0 ; j < fca ; ++j)
		{
			 if(no == fa[j])
			 {
				   flag  = 0 ;
				   j = fca ;
			 }
			 else
			 {
				   flag = 1 ;
			 }
		}
		if(flag == 0)
		{
			 fi[m] = no ;
			 m = m + 1 ;
		}
	}
	return m ;
}
int diff(int fa[] , int fb[] , int fdiff[] , int fca , int fcb )
{
	int m = 0 ;
	int flag = 0 ;
	int no = 0 ;
	int i = 0 ;
	int j = 0 ;
	m = 0 ;
	flag = 0 ;
	for(i = 0 ; i < fca ; ++i)
	{
		no = fa[i] ;
		for(j = 0 ; j < fcb ; ++j)
		{
			 if(no == fb[j])
			 {
				   flag  = 0 ;
				   j = fcb ;
			 }
			 else
			 {
				   flag = 1 ;
			 }
		}
		if(flag == 1)
		{
			 fdiff[m] = no ;
			 m = m + 1 ;
		}
	}
	return m ;
}

int sdiff(int fa[] , int fb[] ,int fsdif[] , int fca , int fcb )
{
	int m = 0 ;
	int d1 = 0;
	int d2 = 0 ;
	int fdiff1[30] = {0} ;
	int fdiff2[30] = {0} ;
	d1 = diff(fa , fb , fdiff1 , fca , fcb ) ;
	d2 = diff(fb , fa , fdiff2 , fca , fcb);
	m = uni(fdiff1 , fdiff2 , fsdif , d1 , d2);
	return m ;
}


