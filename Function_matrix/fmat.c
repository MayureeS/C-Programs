/*
 * fmat.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
int matrixrow();
int matrixcolumn() ;
void faccept(int *fa[] , int fr ,int fc );
void fdisplay(int *fa[] , int fr , int fc);
int diagonal_sum(int *fa[], int fr , int fc);
void fadd(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fadd[]);
void fsub(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fsub[]);
void fmulti(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fmulti[]);
void ftrans(int *fa[] , int fr , int fc , int *ftrans[]);
int upper(int *fa[] , int fr , int fc);
int main(void)
{
	int ra1 = 0 ;
	int ca1 = 0 ;
	int ra2 = 0 ;
	int ca2 = 0 ;
	int c = 0 ;
	int d = 0 ;
	int flag = 0 ;
	int i = 0 ;
	int **a = NULL;
	int **b = NULL;
	int **add = NULL;
	int **sub = NULL;
	int **multi = NULL;
	int **trans = NULL;
	printf("For matrix A :\n");
    ra1 = matrixrow() ;
	ca1 = matrixcolumn();
	a = (int**)calloc(ra1 , sizeof(int*));
	for(i=0 ; i<ra1 ; ++i)
	{
		a[i] = (int*)calloc(ca1 , sizeof(int));
	}
	faccept(a , ra1 , ca1);
	do
	{
		printf("\n\n MENU");
		printf("\n 1 Display the  matrix");
		printf("\n 2 Sum of diagonal elements");
		printf("\n 3 Check matrix for upper triangular matrix");
		printf("\n 4 Transpose of the matrix");
		printf("\n 5 Addition of two matrices(A + B)");
		printf("\n 6 Subtraction of two matrices(A - B)");
		printf("\n 7 Multiplication of two matrices(A * B)");
		printf("\n 8 Enter the another set of matrices");
		printf("\n 9 Exit");
		printf("\n Enter your choice =");
		scanf("%d" , &c);
		switch(c)
		{
		case 1 :
			printf("\n The matrix A Entered is :\n");
			fdisplay(a , ra1 , ca1);
			break ;
		case 2 :
			if(ra1 == ca1)
			{
				d = diagonal_sum(a , ra1 , ca1);
				printf("\n Sum of diagonal elements = %d" , d);
			}
			else
			{
				printf("There are no diagonal elements");
			}
			break ;
		case 3 :
			if(ca1 == ra1)
			{
				flag = upper(a , ra1 , ca2);
				if(flag == 1)
				{
					printf("\n Given matrix is upper triangular");
				}
				else
				{
					printf("\n Given matrix is not an upper triangular");
				}
			}
			else
			{
				printf("\n This is not an square matrix.Hence not an upper triangular ");
			}
			break ;
		case 4 :
			trans = (int**)calloc(ra1 , sizeof(int*));
			for(i=0 ; i<ra1 ; ++i)
			{
				trans[i] = (int*)calloc(ca1 , sizeof(int));
			}
			ftrans(a , ra1 , ca1 , trans);
			printf("The matrix A Entered is :\n");
			fdisplay(a , ra1 , ca1);
			printf("\n Transpose of matrix A :\n");
			fdisplay(trans , ra1 , ca1);
			free(trans);
			trans = NULL ;
			break ;
		case 5 :
			printf("\n Enter matrix B");
			printf("\n For matrix B :\n");
			ra2 = matrixrow() ;
			ca2 = matrixcolumn();
			b = (int**)calloc(ra2 , sizeof(int*));
			for(i=0 ; i<ra2 ; ++i)
			{
				b[i] = (int*)calloc(ca2 , sizeof(int));
			}
			faccept(b , ra2 , ca2);
			if((ra1 == ra2) && (ca1 == ca2))
			{
				add = (int**)calloc(ra1 , sizeof(int*));
				for(i=0 ; i<ra1 ; ++i)
				{
					add[i] = (int*)calloc(ca1 , sizeof(int));
				}
				fadd(a , b , ra1 , ca1 , ra2 , ca2 , add);
				printf("The matrix A Entered is :\n");
				fdisplay(a , ra1 , ca1);
				printf("The matrix B Entered is :\n");
				fdisplay(b , ra2 , ca2);
				printf("\n Addition of two matrices = \n");
				fdisplay(add , ra1 , ca1);
				free(add);
				add = NULL ;
			}
			else
			{
			    printf("\n Addition can't be performed\n");
			}
			break ;
		case 6 :
			printf("\n For matrix B :\n");
			ra2 = matrixrow() ;
			ca2 = matrixcolumn();
			b = (int**)calloc(ra2 , sizeof(int*));
			for(i=0 ; i<ra2 ; ++i)
			{
				b[i] = (int*)calloc(ca2 , sizeof(int));
			}
			faccept(b , ra2 , ca2);
			if((ra1 == ra2) && (ca1 == ca2))
			{
				sub = (int**)calloc(ra1 , sizeof(int*));
				for(i=0 ; i<ra1 ; ++i)
				{
					sub[i] = (int*)calloc(ca1 , sizeof(int));
				}
				fsub(a , b , ra1 , ca1 , ra2 , ca2 , sub);
				printf("The matrix A Entered is :\n");
				fdisplay(a , ra1 , ca1);
				printf("The matrix B Entered is :\n");
				fdisplay(b , ra2 , ca2);
				printf("\n Subtraction of two matrices = \n");
				fdisplay(sub , ra1 , ca1);
				free(sub);
				sub = NULL ;
			}
			else
			{
				printf("\n Subtraction can't be performed\n");
			}
			break ;
		case 7 :
			printf("\n For matrix B :\n");
			ra2 = matrixrow() ;
			ca2 = matrixcolumn();
			b = (int**)calloc(ra2 , sizeof(int*));
			for(i=0 ; i<ra2 ; ++i)
			{
				b[i] = (int*)calloc(ca2 , sizeof(int));
			}
			faccept(b , ra2 , ca2);
			if(ca1 == ra2)
			{
				multi = (int**)calloc(ra1 , sizeof(int*));
				for(i=0 ; i<ra1 ; ++i)
				{
					multi[i] = (int*)calloc(ca1 , sizeof(int));
				}
				fmulti(a , b , ra1 , ca1 , ra2 , ca2 , multi);
				printf("The matrix A Entered is :\n");
				fdisplay(a , ra1 , ca1);
				printf("The matrix B Entered is :\n");
				fdisplay(b , ra2 , ca2);
				printf("\n Multiplication of 2 matrices =\n");
				fdisplay(multi , ra1 , ca2);
				free(multi);
				multi = NULL ;

			}
			else
			{
				printf("\n Multiplication can't be performed\n");
			}
			break ;
		case 8 :
			main();
			break ;
		case 9 :
			free(a);
			a = NULL ;
			free(b);
			b = NULL ;
			printf("\n Thank you...");
			break ;
		}
	}while(c != 9);
	return 0 ;
}
int matrixrow()
{
	int ra = 0 ;
	do
	{
		printf("Enter the number of rows of matrix=");
		scanf("%d" , &ra);
	}while(ra < 1 || ra > 5);
	return ra ;
}
int matrixcolumn()
{
	int ca = 0 ;
	do
	{
		printf("Enter the number of columns of matrix =");
		scanf("%d" , &ca);
	}while(ca < 1 || ca > 5);
	return ca ;
}
void faccept(int *fa[] , int fr ,int fc )
{
	int i = 0 ;
	int j = 0 ;
	for(i = 0 ; i < fr ;++ i)
	{
		for(j = 0 ;j < fc ; ++j)
		{
			printf("Enter element[%d][%d] = " , i , j);
			scanf("%d" , &fa[i][j]);
		}
	}
}
void fdisplay(int *fa[] , int fr , int fc)
{
	int i = 0 ;
	int j = 0 ;
	for(i = 0 ; i < fr ;++ i)
	{
		for(j = 0 ;j < fc ; ++j)
		{
			printf("%d\t" , fa[i][j]);
		}
		printf("\n");
	}
}
void fadd(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fadd[])
{
	int i = 0 ;
	int j = 0 ;
	for(i = 0 ; i < fra2 ;++ i)
	{
		for(j = 0 ;j < fca2 ; ++j)
		{
			fadd[i][j] = fa[i][j] + fb[i][j];
		}
	}
}
void fsub(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fsub[])
{
	int i = 0 ;
	int j = 0 ;
	for(i = 0 ; i < fra2 ;++ i)
	{
		for(j = 0 ;j < fca2 ; ++j)
		{
			fsub[i][j] = fa[i][j] + fb[i][j];
		}
	}
}
void fmulti(int *fa[] , int *fb[] ,int fra1 , int fca1 ,int fra2 , int fca2 , int *fmulti[])
{
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	for(i = 0 ; i < fra1 ;++ i)
	{
		for(j = 0 ;j < fca2 ; ++j)
		{
			for(k = 0 ; k < fca1 ; ++k)
			{
				fmulti[i][j] = fmulti[i][j] + fa[i][k] * fb[k][j] ;
			}
		}
	}
}
void ftrans(int *fa[] , int fr , int fc , int *ftrans[])
{
	int i = 0 ;
	int j = 0 ;
	for(i = 0 ; i < fr ; ++i)
	{
		for(j = 0 ; j < fc ; ++ j)
		{
			ftrans[j][i] = fa[i][j];
		}
	}
}
int diagonal_sum(int *fa[], int fr , int fc)
{
	int d = 0 ;
	int i = 0 ;
	for(i=0 ; i<fr&&i<fc ; ++i )
	{
		d = d + fa[i][i];
	}
	return d ;
}
int upper(int *fa[] , int fr , int fc)
{
	int flag = 0 ;
	int i = 0 ;
	int j =0 ;
	for(i=0 ; i <fr ; ++i)
	{
		for(j=0 ; j<fc ; ++j)
		{
			if(fc < fr && fa[fr][fc] != 0)
			{
				flag = 1 ;
			}
		}
	}

	return flag ;
}


