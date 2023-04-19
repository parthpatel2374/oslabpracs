#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int n,temp[10],t,count=0,short_p;
    float TWT=0,TTAT=0,AWT,ATAT;
    printf("Enter the number of the process : ");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        
        temp[i]=a[i].BT;
    }
    
    // BT of maximum process
    a[9].PT=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        
        // if any process is completed
        if(a[short_p].BT==0)
        {
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            
            // total calculation
            TWT=TWT+a[short_p].WT;
            TTAT=TTAT+a[short_p].TAT;
            
        }
    }
    
    AWT=TWT/n;
    ATAT=TTAT/n;
    
    // outcome
    printf("p-id WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d    %d   %d\n",i+1,a[i].WT,a[i].TAT);
    }
    
    printf("Avg waiting time of the process  is %.2f\n",AWT);
    printf("Avg turn around time of the process is %.2f\n",ATAT);
    
    return 0;
}
