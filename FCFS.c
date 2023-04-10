#include<stdio.h>
void sort_at(float FCFS[100][6], int n){
    
}
void printarr(float FCFS[100][6], int n){
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            printf("%.2f\t", FCFS[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    float FCFS[100][6];

    printf("Enter the arrival and burst time for processes;\n");
    for(int i=0; i<n; i++){
        scanf("%f %f", &FCFS[i][1], &FCFS[i][2]);
        FCFS[i][0] = i+1;
    }
    // sort_at(FCFS, n);
    for(int i=0; i<n; i++){
        int index=i;
        for(int j=i+1; j<n; j++){
            if(FCFS[i][1] > FCFS[j][1]){
                index = j;
            }
            int temp = FCFS[index][0];
            FCFS[index][0] = FCFS[i][0];
            FCFS[i][0] = temp;
            
            temp = FCFS[index][1];
            FCFS[index][1] = FCFS[i][1];
            FCFS[i][1] = temp;
            
            temp = FCFS[index][2];
            FCFS[index][2] = FCFS[i][2];
            FCFS[i][2] = temp;
        }
    }
    printarr(FCFS, n);
    //calculation for completion time;
    FCFS[0][3] = 0;
    for(int i=1; i<n; i++){
        FCFS[i][3] = FCFS[i][2] + FCFS[i-1][3];
    }
    //calculation for arrival and tat time;
    for(int i=0; i<n; i++){
        FCFS[i][4] = FCFS[i][3] - FCFS[i][1] - FCFS[i][2];
        FCFS[i][5] = FCFS[i][3] - FCFS[i][1];
    }
    //calculating average of times;
    float sumwi=0, sumti=0, avgwi, avgti;
    for(int i=0; i<0; i++){
        sumwi += FCFS[i][4]; 
        sumti += FCFS[i][5]; 
    }
    avgwi = sumwi / n;
    avgti = sumti / n;

    //printing values;
    printf("proc\ta-time\tb-time\tc-time\tw-time\tta-time");
    printarr(FCFS, n);
    printf("The average waiting time and\naverage turn around time is %.2f, %.2f.\n", avgwi, avgti);
}