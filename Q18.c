#include<stdio.h>
#include<conio.h>
int main()
{
    int brt[20],p[20],wat[20],tat[20],pri[20],i,j,n,total=0,po,tem,avgwt,avgtat;
    printf("Enter The Number of Processes:");
    scanf("%d",&n);
    printf("Enter The Burst Time and Priority of the Processes\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst-Time:");
        scanf("%d",&brt[i]);
        printf("Priority:");
        scanf("%d",&pri[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        po=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[po])
                po=j;
        }
        tem=pri[i];
        pri[i]=pri[po];
        pri[po]=tem;
        tem=brt[i];
        brt[i]=brt[po];
        brt[po]=tem;
        tem=p[i];
        p[i]=p[po];
        p[po]=tem;
    }
    wat[0]=0;
    for(i=1;i<n;i++)
    {
        wat[i]=0;
        for(j=0;j<i;j++)
            wat[i]+=brt[j];
 
        total+=wat[i];
    }
    avgwt=total/n;
    total=0;
    printf("\nProcess\t  Burst-Time  \tWaiting-Time\tTurnaround-Time");
    for(i=0;i<n;i++)
    {
        tat[i]=brt[i]+wat[i];
        total+=tat[i];
        printf("\nP[%d]\t\t   %d\t\t      %d\t\t\t%d",p[i],brt[i],wat[i],tat[i]);
    }
    avgtat=total/n;
    printf("\n\nAverage Waiting-Time=%d",avgwt);
    printf("\nAverage Turnaround-Time=%d\n",avgtat);
    return 0;
}
