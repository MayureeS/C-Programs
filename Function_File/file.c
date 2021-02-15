/*
 * file.c
 *
 *  Created on: 26-Nov-2019
 *      Author: hp
 */
#include<stdio.h>
#include<stddef.h>
#include<stdio_ext.h>
#define ORGFILE "abc.txt"
#define TMPFILE "xyz.txt"
struct student
{
    int roll;
    char fname[10];
    int total;
    float avg;
    char grade;
};
int addrecord(struct student s);
int deleterecord(int roll);
int modifyrecord(struct student m,int *f);
int displayarecord( int roll);
int displayall(void);
int main (void)
{
    int f=0;
    int ch =0;
    int roll=0;
    int x=0;
    struct student s={0};

    do
    {

        do
        {
        printf("\n\t--------FILE OPERATION MENU------");
        printf("\n\t 1. ADD A RECORD");
        printf("\n\t 2. DELETE A RECORD");
        printf("\n\t 3. MODIFY A RECORD");
        printf("\n\t 4. DISPLAY A RECORD");
        printf("\n\t 5. DISPLAY ALL RECORDS");
        printf("\n\t 0. EXIT");
        printf("\n\t ENTER YOUR CHOICE");
        scanf("%d" , &ch);

        }while(ch<0 || ch>5);
        switch (ch)
        {
        case 1:

                printf("\n\t Enter roll=");
                scanf("%d",&s.roll);
                __fpurge(stdin);
                printf("\n\t Enter first name=");
                scanf("%9s",s.fname);
                printf("\n\t Enter total=");
                scanf("%d",&s.total);
                printf("\n\t Enter average=");
                scanf("%f",&s.avg);
                printf("\n\t Enter grade=");
                __fpurge(stdin);
                scanf("%c",&s.grade);
                x=addrecord(s);
                if(x==1)
                {
                    printf("File opening failed\n");
                }


                break;

        case 2:
                printf("Enter the roll no of the record to be deleted:\n");
                scanf("%d",&roll);
                x=deleterecord(roll);
                if(x==1)
                {
                    printf("File opening failed .\n");
                }
                else
                {
                    if(x==2)
                    {
                        printf("file not opened.\n");
                    }
                    else
                    {
                        if(x==3)
                        {
                            printf("Successfully deleted.\n");
                        }
                        else
                        {
                            printf("No such record present.\n");
                        }
                    }
                }


                break;

        case 3:
                printf("Enter modifications:\n");
                printf("Enter the roll no of the record to be modified:\n");
                scanf("%d",&s.roll);
                __fpurge(stdin);
                printf("\n\t Enter first name=");
                scanf("%9s",s.fname);
                printf("\n\t Enter total=");
                scanf("%d",&s.total);
                printf("\n\t Enter average=");
                scanf("%f",&s.avg);
                printf("\n\t Enter grade=");
                __fpurge(stdin);
                scanf("%c",&s.grade);
                x=modifyrecord (s,&f);
                if(x==1)
                {
                    printf("File opening failed .\n");
                }
                else
                {
                    if(f==1)
                    {
                        printf("Successfully modified.\n");
                    }
                    else
                    {
                        printf("No record modified.\n");
                    }
                }

                break;

        case 4 :
                printf("\tEnter the roll.no of record you want to display.\n\t");
                scanf("%d",&roll);
                x=displayarecord(roll);
                if(x==1)
                {
                    printf("File opening error.\n");
                }else
                {
                	if(x==2)
                	{
                		printf("No such record.\n");
                	}
                }


                break;

        case 5 :
                x=displayall();
                if(x==1)
                {

                    printf("File opening error .\n");
                }
                break;

        }
    }while(ch!=0);


    return 0;
}

int addrecord(struct student s)
{

    FILE*fout =NULL;
    int x =0;


    fout=fopen(ORGFILE,"a+b");
    if(fout==NULL)
    {
        x=1;
    }
    else
    {
        fwrite(&s,sizeof(struct student),1,fout);
        fclose(fout);
        fout=NULL;

    }
    return x;
}
int deleterecord(int roll )
{
    int rsucc=0;
    FILE*fout =NULL;
    FILE*fin =NULL;
    int f=0;
    int x =0;
    struct student s ={0};

    fin=fopen(ORGFILE,"r+b");
    if(fin==NULL)
    {
        x=1;
    }
    else
    {
        fout =fopen(TMPFILE,"wb");
        if(fout==NULL)
        {
            x=2;
        }
        else
        {

            f=0;
            do
            {
                rsucc=fread(&s,sizeof(struct student),1,fin);
                if(rsucc==1)
                {
                    if(roll!=s.roll)
                    {

                        fwrite(&s,sizeof(struct student),1,fout);

                    }
                    else
                    {
                        f=1;
                        x=3;
                    }
                }
            }while(rsucc==1);


            fclose(fout);
            fout=NULL;
        }
        fclose(fin);
        fin = NULL;
    }
    if(f==1)
    {
        remove(ORGFILE);
        rename (TMPFILE,ORGFILE);
    }
    else
    {
        remove(TMPFILE);

    }

    return x;
}
int modifyrecord(struct student m,int *f)
{
    int rsucc=0;
    FILE*fout =NULL;
    FILE*fin =NULL;
    int x =0;
    struct student s={0};
    *f=0;

    fin=fopen(ORGFILE,"rb");
    if(fin==NULL)
    {
        x=1;
    }
    else
    {
        fout =fopen(TMPFILE,"wb");
        if(fout==NULL)
        {
            x=1;
        }
        else
        {

            do
            {
                rsucc=fread(&s,sizeof(struct student),1,fin);
                if(rsucc==1)
                {
                    if(m.roll!=s.roll)
                    {
                        fwrite(&s,sizeof(struct student),1,fout);
                    }
                    else
                    {
                        *f=1;

                        fwrite(&m,sizeof(struct student),1,fout);

                    }
                }

            }while(rsucc==1);
            fclose(fout);
            fout=NULL;
        }
        fclose(fin);
        fin = NULL;
    }

    if (*f==1)
    {
        remove(ORGFILE);
        rename (TMPFILE,ORGFILE);
    }
    else
    {
        remove(TMPFILE);
    }
    return x;
}

int displayarecord( int roll)
{
    int rsucc=0;
    FILE  *fin =NULL;
    int x =0;
    struct student s={0};
    fin=fopen(ORGFILE,"rb");
    if(fin==NULL)
    {
        x=1;
    }
    else
    {
        do
        {
            rsucc=fread(&s,sizeof(struct student),1,fin);
            if(rsucc==1)
            {
                if(roll==s.roll)
                {
                	x=2;
                    printf("\n\t Details : ");
                    printf("\n\t roll=%d",s.roll);
                    printf("\n\t first name= %s",s.fname);
                    printf("\n\t total=%d",s.total);
                    printf("\n\t average=%f",s.avg);
                    printf("\n\t grade=%c",s.grade);
                    rsucc=0;  //to terminate
                }
            }

        }while(rsucc==1);

            fclose(fin);
            fin=NULL;
    }
    return x;
}
int displayall(void)
{
    int rsucc=0;
    FILE*fin =NULL;
    int x =0;
    struct student s={0};
    fin = fopen(ORGFILE,"rb");
    if(fin == NULL)
    {
        x=1;
    }

    else
    {
        do
        {
            rsucc = fread(&s,sizeof(struct student),1,fin);

            if(rsucc == 1)
            {
                printf("\n");
                printf("\n\t Details : ");
                printf("\n\t roll=%d",s.roll);
                printf("\n\t first name= %s",s.fname);
                printf("\n\t total=%d",s.total);
                printf("\n\t average=%f",s.avg);
                printf("\n\t grade=%c",s.grade);
            }

        }while(rsucc == 1);

        fclose(fin);
        fin = NULL;
       }
    return x;
}


