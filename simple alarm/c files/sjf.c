#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int i,j,n,bt[10],compt[10],tat[10],wt[10],temp;
    float sumwt=0.0,sumtat=0.0,avgwt,avgtat;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the burst time of  %d process:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    for (i=1;i<n;i++)
    for (j=i-1;j<n;j++)
    if(bt[i]>bt[j])
    {
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
    }
    compt[0]=bt[0];
    for(i=1;i<n;i++)
    compt[i]=bt[i]+compt[i-1];
    for(i=0;i<n;i++)
    { 
        tat[i]=compt[i];
        wt[i]=tat[i]-bt[i];
        sumtat+=tat[i];
        sumwt+=wt[i];
    }
    avgwt=sumwt/n;
    avgtat=sumtat/n;
    printf("____________\n");
    printf("Bt\tCt\tTat\tWt\n");
    printf("____________\n");
    for(i=0;i<n;i++)
    {
        printf("%2d\t%2d\t%2d\t%2d\n,i,bt[i],compt[i],tat[i],wt[i]");
    }
    printf("____________\n");
    printf("Avgwt=%.2f\tAvgtat=%.2f\n",avgwt,avgtat);
    printf("____________\n");
    getch();
}