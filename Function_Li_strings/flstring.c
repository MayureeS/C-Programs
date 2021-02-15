/*
 * flstring.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stddef.h>
#include<ctype.h>
int len(char fa[]);
int copy(char fa[] , char fb[]);
int concat(char fa[] , char fb[]);
void reverse(char fa[]);
int compare(char fa[] , char fb[]);
char* sub(char fa[] , char fb[]);
void case_change(char fa[] , int fd);
int main(void)
{
	char a[30] = {'\0'};
	char b[30] = {'\0'} ;
    int cnt = 0 ;
    int d = 0 ;
    char *flag = NULL ;
    int l = 0 ;
    int f = 0 ;
    printf("Enter the string :");
    __fpurge(stdin);
	scanf("%29s" ,a);
	do
	{
		do
		{
			printf("\n\n MENU");
			printf("\n 1 Length of string");
			printf("\n 2 Copy of string");
			printf("\n 3 Join 2 string");
			printf("\n 4 Reverse of string");
			printf("\n 5 compare two  strings");
			printf("\n 6 Substrings of given string");
			printf("\n 7 Change the case of string");
			printf("\n 8 Enter another string ");
			printf("\n 9 Exit");
			printf("\n\n Enter your choice =");
			scanf("%d" , &cnt);

			if(cnt <= 0 || cnt > 8)
			{
				printf("Wrong input , Enter the choice again");
			}
		}while(cnt <= 0 || cnt > 8);
		switch (cnt)
		{
			case 1 :
				l = len(a);
				printf("String length = %d", l);
				break;
			case 2 :
				 f = copy(a ,b);
				if(f == 1)
				{
					printf("\n The copied string = %s" , b);
				}
				else
				{
					printf("\n String cannot be copied");
				}
				break;
			case 3 :
				printf("\n Enter the string to be joined to previous string =");
				__fpurge(stdin);
				scanf("%29s" ,b);
				f = concat(a , b);
				if(f == 1)
				{
					printf("\n The joined string = %s" , a);
				}
				else
				{
					printf("\n String cannot be joined");
				}
				break;
			case 4 :
				reverse(a);
				printf("\n Reversed string = %s" , a);
				break;
			case 5 :
				printf("\n Enter the string to be compared =");
				__fpurge(stdin);
					scanf("%9s" ,b);
				f = compare(a , b);
				if(f == 0)
				{
					printf("\n String1 is equal to String2");
				}
				else
				{
					if(f < 0)
					{
						printf("\n String1 is less than String2");
					}
					else
					{
						printf("\n String1 is greater than String2");
					}
				}
				break;
			case 6 :
				printf("\n Enter the string to be checked for substring");
				__fpurge(stdin);
				scanf("%9s" ,b);
				flag = sub(a , b);
				if(flag == NULL)
				{
					printf("\n Substring not found");
				}
				else
				{
					printf("\n Substring found");
				}
				break;
			case 7 :
				 do
				{
					printf("\n MENU");
					printf("\n 1 Upper case to lower case");
					printf("\n 2 Lower case to upper case");
					printf("\n 3 Toggle");
					printf("\n 4 Exit");
					printf("\n Enter your choice =");
					scanf("%d" , &d);
					case_change(a , d);
					printf("\n String after change in case =%s" , a);
			}while(d != 4);
				break;
			case 8 :
				main();
				break ;
				break;
			case 9 :
				printf("Thank You....");
				break;
		}
	}while(cnt != 9);
	return 0 ;
}
int len(char fa[])
{
	int l = 0 ;
	l = strlen(fa);
	return l ;
}
int copy(char fa[] , char fb[])
{
	int l = 0 ;
	int flag = 0 ;
	l = strlen(fa);
	if(sizeof(char*) > l)
	{
		strcpy(fb , fa);
		flag = 1 ;
	}
	else
	{
		flag = 0 ;
	}
	return flag ;
}
int concat(char fa[] , char fb[])
{
	int l = 0 ;
	int l1 = 0 ;
	int flag = 0 ;
	l = strlen(fa) ;
	l1 = strlen(fb);
	if(sizeof(char*) > (l + l1))
	{
		strcat(fa , fb);
		flag = 1 ;
	}
	else
	{
		flag = 0 ;
	}
	return flag ;
}
void reverse(char fa[])
{
	int l = 0 ;
	int t = 0 ;
	int i = 0 ;
	int j = 0 ;
	char temp = '\0';
	l = strlen(fa) ;
	t = l/2 ;
	for(i = 0 , j = 1 ; i < t ; i++, j++)
	{
		temp = fa[i];
		fa[i] = fa[l - j];
		fa[l -j] = temp;
	}
}
int compare(char fa[] , char fb[])
{
	int l = 0 ;
	l = strcmp(fa , fb);
	return l ;
}
char *sub(char fa[] , char fb[])
{
	char *flag = 0 ;
	flag = strstr(fa , fb);
	return flag ;
}
void case_change(char fa[] , int fd)
{
	int i = 0 ;
	switch(fd)
	{
		case 1 :
			for(i=0; fa[i] != '\0' ; ++i)
			{
				fa[i]= tolower(fa[i]);
			}
			break ;
		case 2 :
			for(i=0 ; fa[i] != '\0' ; ++i)
			{
				fa[i]=toupper(fa[i]);
			}
			break ;
		case 3 :
			for(i=0 ; fa[i] != '\0' ; ++i)
			{
				if(fa[i] >= 'A' && fa[i] <= 'Z')
				{
					fa[i]=tolower(fa[i]);
				}
				else
				{
					if(fa[i] >= 'a' && fa[i] <= 'z')
					{
						fa[i]=toupper(fa[i]);
					}
				}
			}
			break ;
	}
}
