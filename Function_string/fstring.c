/*
 * fstring.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stdio_ext.h>
void accept_string(char fa[]);
int menu();
int find_len(char fa[]);
void copy(char fa[] , char fb[]);
void concat(char fa[] , char fb[]);
void reverse(char fa[]);
int compare(char fa[] , char fb[]);
int sub(char fa[] , char fb[]);
void case_change(char fa[] , int fd);
int main(void)
{
	char a[30] = {'\0'};
	char b[30] = {'\0'} ;
    int cnt = 0 ;
    int d = 0 ;
    int l = 0 ;
    int i = 0 ;
    int flag = 0 ;
    printf("Enter the string :");
	accept_string(a);
	do
	{
		cnt = menu();
		switch (cnt)
		{
		case 1 :
			l = find_len(a);
			printf("\n Length of string = %d" , l);
			break ;
		case 2 :
			if(sizeof(b) > find_len(a))
			{
				copy(a , b);
				printf("\n The copied string = %s" , b);
			}
			else
			{
				printf("\n The string can't be coppied");
			}
			break ;
		case 3 :
			printf("\n Enter the string to be joined to previous string =");
			accept_string(b);
			if(sizeof(b) > (find_len(a) + find_len(b)))
			{
				concat(a , b);
				printf("\n The joined string = %s" , a);
			}
			else
			{
				printf("\n The strings can't be joined");
			}
			break ;
		case 4 :
			reverse(a);
			printf("\n Reversed string = %s" , a);
			break ;
		case 5 :

			printf("\n Enter the string to be compared =");
			accept_string(b);
			i = compare(a , b);
			if(a[i] > b[i])
			{
				printf("\n String1 is greater than String2");
			}
			else
			{
				if(a[i] < b[i])
				{
					printf("\n String1 is less than String2");
				}
				else
				{
					printf("\n String1 is equal to String2");
				}
			}
			break ;
		case 6 :
			printf("\n Enter the string to be checked for substring");
			accept_string(b);
			flag = sub(a , b);
			if(flag == 1)
			{
				printf("\n Substring found");
			}
			else
			{
				printf("\n Substring not found");
			}
			break ;
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
		case 9 :
			printf("Thank You....");
			break ;
		}
	}while(cnt != 9);
	return 0 ;
}
void accept_string(char fa[])
{
	__fpurge(stdin);
	scanf("%9s" ,fa);
}
int menu()
{
	int cnt = 0 ;
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
	return cnt ;
}
int find_len(char fa[])
{
	int l = 0 ;
	int i = 0 ;
	for(i = 0 ; fa[i] != '\0' ; ++i)
	{
		l = l + 1 ;
	}
	return l ;
}
void copy(char fa[] , char fb[])
{
	int i = 0 ;
	for(i = 0 ; fa[i] != '\0' ; ++i)
	{
		fb[i] = fa[i];
	}
}
void concat(char fa[] , char fb[])
{
	int i = 0 ;
	int j = 0 ;
	j = find_len(fa) ;
	for(i = 0 ; fb[i] != '\0' ; ++i , ++j)
	{
		fa[j] = fb[i] ;
	}
}
void reverse(char fa[])
{
	int i = 0 ;
	int j = 0 ;
	int t = 0 ;
	int temp = 0 ;
	int l = 0 ;
	l = find_len(fa);
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
	int i = 0 ;
	for(i = 0 ;fa[i] == fb[i] && fa[i] != '\0' ; ++i)
	{
	}
	return i ;
}
int sub(char fa[] , char fb[])
{
	int i = 0 ;
	int j = 0 ;
	int flag = 0 ;
	for(i=0 ; fb[i] != '\0' ; ++i)
	{
		for(j=0 ; fa[j] != '\0' ; ++j)
		{
			if(fb[i] == fa[j])
			{
				while(fb[i] != '\0')
				{
					if(fb[i] == fa[j])
					{
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
					i = i + 1 ;
					j = j + 1 ;
				}
			}
		}
	}
	return flag ;
}
void case_change(char fa[] , int fd)
{
	int i = 0 ;
	switch(fd)
	{
	case 1 :
		for(i=0 ; fa[i] != '\0' ; ++i)
		{
			if(fa[i] >= 'A' && fa[i] <= 'Z')
			{
				fa[i] = fa[i] + 32 ;
			}
		}
		break ;
	case 2 :
		for(i=0 ; fa[i] != '\0' ; ++i)
		{
			if(fa[i] >= 'a' && fa[i] <= 'z')
			{
				fa[i] = fa[i] - 32 ;
			}
		}
		break ;
	case 3 :
		for(i=0 ; fa[i] != '\0' ; ++i)
		{
			if(fa[i] >= 'A' && fa[i] <= 'Z')
			{
				fa[i] = fa[i] + 32 ;
			}
			else
			{
				if(fa[i] >= 'a' && fa[i] <= 'z')
				{
					fa[i] = fa[i] - 32 ;
				}
			}
		}
		break ;
	}
}


