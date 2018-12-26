#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

struct student
{
    char name[20];
    int rollno;
    char attend;
}s[100];

int main()
{
    system("COLOR F4");
    FILE *f;
    FILE *t;
    FILE *o;
    FILE *u;
    FILE *T;
    int i,n,a,b,d,dd,mm,yy,m,j;
    char c,fl[500],strn[10][150],buffer[150],k;
    printf("\n\n\n\n*******************************************************************************************************************\n");
    printf("\t\t\t\t\tATTENDANCE SYSTEM\n");
    printf("*******************************************************************************************************************\n\n");
    printf("\n\t           *PRESS 1 For Giving Input\n");
    printf("\t           *PRESS 2 For Taking Attendance\n");
    printf("\t           *PRESS 3 To View Attendance if had taken\n");
    printf("\t           *PRESS 4 For Exit\n\n");
    printf("   \n\n\t\t    :  ");
    scanf("%d",&m);




    //                    1    TAKING INPUT

    if(m==1)
    {
        //system("cls");
        printf("\n\nEnter class strength :\t");
        scanf("%d",&n);

        //                      SAVING VALUE OF N

        t=fopen("num.txt","w+");
        fprintf( t,"%d", n );
        fclose(t);
        t=fopen("num.txt","r+");
        fscanf(t,"%d",&d);
        fclose(t);
        //printf("\n%d\n",d);
        //printf("%d",n);


        printf("\n");
        for(i=1;i<=n;i++)
        {
            printf("Enter %d student name :\t",i);
            scanf("\n%[^\n]s",s[i].name);
            printf("Enter Roll no  :\t");
            scanf("%d",&s[i].rollno);
        }

        f=fopen("make.txt","w+");
        for(i=1;i<=n;i++)
        {
            fprintf(f,"Name: %s\nRoll no: %d\n",s[i].name, s[i].rollno);
        }
        fclose(f);


        u=fopen("make2.txt","w+");
        for(i=1;i<=n;i++)
        {
            fprintf(u,"%d\n",s[i].rollno);
        }
        fclose(u);


        T=fopen("make3.txt","w+");
        for(i=1;i<=n;i++)
        {
            fprintf(T,"%s\n",s[i].name);
        }
        fclose(T);

        return main();
    }



    //                      2     TAKING ATTENDANCE

    else if(m==2)
    {
        system("cls");

        //                  RETAKING d VALUE

        t=fopen("num.txt","r+");
        fscanf(t,"%d",&d);
        fclose(t);

        printf("\n\t\t\t\t________Taking ATTENDANCE________\n\n");
        printf("DATE (DD/MM/YY)  :\t");
        scanf("%d %d %d",&dd,&mm,&yy);
        printf("\n\t\tPress Enter when Ready\n");
        getc(k);

        /*f = fopen("make.txt","r+");
        while(fgets(buffer,150,file_in))
        {
            strcpy(strn[i],buffer);
            printf("Line %d: %s",i,strn[i]);
            i++;
        }
        fclose(f);*/


        /*
        f=fopen("make.txt","r");
        while( fgets(fl,50,f) != NULL )
        {
            printf("%s",fl);
        }
        fclose(f);
        //printf("%d",d);
        */

        u=fopen("make2.txt","r");
        for(i=1;i<=d;i++)
        {
            fscanf(u,"%d",&s[i].rollno);
        }
        fclose(u);

        T=fopen("make3.txt","r");
        for(i=1;i<=d;i++)
        {
            fscanf(T,"%[^\n]s",s[i].name);
        }
        fclose(T);




        printf("\nEnter attendance 'A' or 'P' roll n.o wise\n\n");
        for(i=1;i<=d;i++)
        {
            printf("\nRoll no: %d",s[i].rollno);
            printf("\t\tName : %s   :: \t",s[i].name);
            scanf("\n%c",&s[i].attend);
            //continue;
        }
        o=fopen("make1.txt","w+");
        fprintf(o,"ATTENDANCE ON %d-%d-%d\n",dd,mm,yy);
        for(i=1;i<=d;++i)
        {
            fprintf(o,"Attendance: %c       Roll no:%d      Name:%s\n",s[i].attend,s[i].rollno,s[i].name);
        }
        fclose(f);

        getch();
        return main();

    }

    else if(m==3)
    {
        system("cls");
        o=fopen("make1.txt","r+");
        while( fgets(fl,50,f) != NULL )
        {
            printf("%s",fl);
        }
        fclose(o);
        //return main();
    }

    else if(m==4)
         {
             //system("cls");
             printf("THANK YOU");
         }

    else
         {
            //system("cls");
            printf("INVALID SELECTION!!!");
            return main();
         }
    return 0;

}
