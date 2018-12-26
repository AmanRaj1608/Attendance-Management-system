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
    FILE *f;
    FILE *t;
    int i,n,a,b,d,dd,mm,yy,m,j;
    char c;
    printf("\n\n\n\n******************************************************************************************************\n");
    printf("\t\t\t\t\tATTENDANCE SYSTEM\n");
    printf("******************************************************************************************************\n\n");
    printf("           *PRESS 1 For Giving Input\n");
    printf("           *PRESS 2 For Taking Attendance\n");
    printf("           *PRESS 3 To View Attendance if had taken\n");
    printf("           *PRESS 4 For Exit\n\n");
    printf("   \n\n\t\t    :  ");
    scanf("%d",&m);

    //                        TAKING INPUT

    if(m==1)
    {
        printf("Enter class strength :\t");
        scanf("%d",&n);
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

        t=fopen("num.dat","wb+");
        fwrite(&n,sizeof(int),1,t);
        //fclose(t);
        //f=fopen("num.txt","r+");
        fread(&d,sizeof(int),1,t);
        fclose(t);
        printf("%d",d);
        printf("%d",n);

        fclose(f);
        return main();
    }




    //                            TAKING ATTENDANCE

    else if(m==2)
    {
        //t=fopen("num.txt","r+");
        //fscanf(t,"%d",d);
        printf("\n\t\t\t\tTaking ATTENDANCE\n\n");
        printf("DATE(DD/MM/YY)  :\t");
        scanf("%d %d %d",&dd,&mm,&yy);
        printf("\n\t\tPress Enter when Ready\n");
        f=fopen("main.txt","r+");
        printf("%d",d);
        for(i=1;i<=d;i++)
        {
            printf("\nRoll no: %d",s[i].rollno);
            printf("\t\tName : %s",s[i].name);
            scanf("%c",&s[i].attend);
            //continue;
        }
        f=fopen("make1.txt","a");
        printf("ATTENDANCE ON %d-%d-%d",dd,mm,yy);
        for(i=0;i<=n;++i)
        fprintf(f,"Attendance: %c       Roll no:%d      Name:%s\n",s[i].attend,s[i].rollno,s[i].name);

        getch();
        fclose(f);

    }

    else if(m==4)
          printf("THANK YOU");

    else
         {
           printf("INVALID SELECTION!!!");
           return main();
         }

}
