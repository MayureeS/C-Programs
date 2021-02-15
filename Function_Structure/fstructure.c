/*
 * fstructure.c
 *
 *  Created on: 21-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
struct day
{
	unsigned int day ;
	unsigned int month ;
	unsigned int year ;
};
struct drivinglic
{
	char drvno[10] ;
	char fname[20] ;
	char lname[20] ;
	char address[3][20] ;
	struct day dob ;
	struct day doi ;
	char bg[4] ;
	int dflag ;
};
void addrecords(struct drivinglic fd[] , int i);
int menu();
void print(int fi , struct drivinglic fd[]);
int search(struct drivinglic fd[] , int fcnt , char fdrvno[] , int *fi);
void delete(struct drivinglic fd[] , int fcnt , char fdrvno[] , int fi);
void modify(struct drivinglic fd[] , int fcnt , char fdrvno[] , int fi);
void accept(char fdrv1[]);
int main(void)
{
	struct drivinglic * d = NULL ;
	int cnt = 0 ;
	int n = 0 ;
	char drv1[10] = {'\0'} ;
	int flag = 0 ;
	int i = 0 ;
	do
	{
		printf("How many entries are there?");
		scanf("%d" , &cnt);
		if(cnt > 10 || cnt <= 0)
		{
			printf("\n Wrong input , Enter Again !!");
		}
	}while(cnt > 10 || cnt < 1);
		do
		{
			n = menu();
			switch(n)
			{
			case 1 :
				d = (struct drivinglic *)calloc(cnt , sizeof(struct drivinglic));
				if(d == NULL)
				{
					printf("\n\t Operation not possible memory allocation failed");
				}
				else
				{
					for(i=0 ; i < cnt ; ++i)
					{
						addrecords(d , i);
					}
				}
				break ;
			case 2 :
				if(d == NULL)
				{
					printf("\n Add records first");
				}
				else
				{
					for(i = 0 ; i < cnt ; ++i)
					{
						print(i , d) ;
					}
				}
				break ;
			case 3 :
				if(d == NULL)
				{
					printf("\n Add records first");
				}
				else
				{
					flag = 1 ;
					printf("Enter the drv no to be searched =");
					accept(drv1);
					flag = search(d , cnt , drv1 , &i);
					if(flag == 0)
					{
						printf("Given drvno found");
						printf("The data of given drvno is :\n");
						print(i , d);
					}
					else
					{
						printf("Given drvno not found");
					}
				}
				break ;
			case 4 :
				if(d == NULL)
				{
					printf("\n Add records first");
				}
				else
				{
					printf("Enter the drv no to be deleted =");
					accept(drv1);
					flag = search(d , cnt , drv1 , &i);
					if(flag == 0)
					{
						delete(d , cnt , drv1 , i );
						printf("Record found and deleted successfully\n\n");
						printf("New record is :");
						for(i=0 ; i<cnt ; ++i)
						{
							if(d[i].dflag == 0)
							{
								print(i , d);
							}
						}
					}
					else
					{
						printf("Record not found");
					}
					delete(d , cnt ,drv1 , flag);
				}
				break ;
			case 5 :
				if(d == NULL)
				{
					printf("\n Add records first");
				}
				else
				{
					printf("Enter the drv no to be modified =");
					accept(drv1);
					flag = search(d , cnt , drv1 , &i);
					if(flag == 0)
					{
						printf("Record is found , Please enter new modifications");
						modify(d , cnt ,drv1 , i);
						printf("\n New Records are :");
						for(i=0 ; i <cnt ; ++i)
						{
							print(i , d);
						}
					}
					else
					{
						printf("No such record is found");
					}
				}
				break ;
			case 6 :
				main();
				break ;
		}
	}while(n != 7);

	free(d) ;
	d = NULL ;
	return 0 ;
}

void addrecords(struct drivinglic fd[] , int i)
{
	printf("\n Entry %d" , i + 1);
	printf("\n Enter Drv number =");
	__fpurge(stdin);
	scanf("%9s" ,fd[i].drvno);
	printf("\n Enter your first name =");
	__fpurge(stdin);
	scanf("%19s" ,fd[i].fname);
	printf("\n Enter your last name =");
	__fpurge(stdin);
	scanf("%19s" ,fd[i].lname);
	printf("\n Enter address =");
	__fpurge(stdin);
	scanf("%19s" ,fd[i].address[0]);
	__fpurge(stdin);
	scanf("%19s" ,fd[i].address[1]);
	__fpurge(stdin);
	scanf("%19s" ,fd[i].address[2]);
	printf("\n Enter the date of birth =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].dob.day);
	printf("\n Enter the month of birth =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].dob.month);
	printf("\n Enter the year of birth =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].dob.year);
	printf("\n Enter the date of identification =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].doi.day);
	printf("\n Enter the month of identification =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].doi.month);
	printf("\n Enter the year of identification =");
	__fpurge(stdin);
	scanf("%u" ,&fd[i].doi.year);
	printf("Enter the blood group =");
	__fpurge(stdin);
	scanf("%3s" ,fd[i].bg );
	fd[i].dflag = 0 ;
}
int menu()
{
	int n = 0 ;
	do
	{
		printf("\n\n MENU");
		printf("\n 1 Add records");
		printf("\n 2 Display record");
		printf("\n 3 Search record");
		printf("\n 4 Delete record");
		printf("\n 5 Modify record");
		printf("\n 6.Add another database");
		printf("\n 7 Exit");
		printf("\n Enter your choice =");
		scanf("%d" , &n);
	}while(n <= 0 || n > 6);
	return n ;
}
void print(int fi , struct drivinglic fd[])
{
	if(fd[fi].dflag == 0)
	{
		printf("\n\n Drv number = %s" , fd[fi].drvno);
		printf("\n First name = %s" , fd[fi].fname);
		printf("\n Last name = %s" , fd[fi].lname);
		printf("\n Address = \n %s \n %s \n %s" , fd[fi].address[0] , fd[fi].address[1] , fd[fi].address[2]);
		printf("\n Date of birth = %u . %u . %u " , fd[fi].dob.day , fd[fi].dob.month , fd[fi].dob.year);
		printf("\n Date of identification = %u . %u . %u " , fd[fi].doi.day , fd[fi].doi.month , fd[fi].doi.year);
		printf("\n Blood Group = %s" , fd[fi].bg);
	}
}
int search(struct drivinglic fd[] , int fcnt , char fdrvno[] , int *fi)
{
	int i = 0 ;
	int flag = 0 ;
	flag = 1 ;
	for(i = 0 ; i < fcnt ; ++i )
	{
		flag = strcmp(fdrvno , fd[i].drvno) ;
		if(flag == 0)
		{
			*fi = i ;
			i = fcnt ;
		}
	}
	return flag ;
}
void delete(struct drivinglic fd[] , int fcnt , char fdrvno[] ,int fi)
{
	fd[fi].dflag = 1 ;
}
void modify(struct drivinglic fd[] , int fcnt , char fdrvno[] , int fi)
{
	addrecords(fd , fi);
}
void accept(char fdrv1[])
{
	__fpurge(stdin);
	scanf("%9s" , fdrv1);
}





