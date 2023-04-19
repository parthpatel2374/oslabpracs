#include<stdio.h>
#include "swap&print.c"
#define size 10

int process[size], priority[size];
float arival[size], burst[size], completion[size], waiting[size], turnaround[size];

void sort_at(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arival[j] < arival[i]){
                swapInt(process, i, j);
                swapInt(priority, i, j);
                swapFloat(arival, i, j);
                swapFloat(burst, i, j);
            }
        }
    }    
}
void sort_priority(int n, int upperIndex, int lowerIndex){
    for(int i=upperIndex; i<n; i++){
        for(int j=i; j<=lowerIndex; j++){
            if(priority[j] < priority[i]){
                swapInt(process, i, j);
                swapInt(priority, i, j);
                swapFloat(arival, i, j);
                swapFloat(burst, i, j);
            }
        }
    }
}
int main(){
    int totalProcess;
    //taking input
    printf("Enter the number of processes : ");
    scanf("%d", &totalProcess);
    printf("Enter the arrival time : ");
    for(int i=0; i<totalProcess; i++){
        scanf("%f", &arival[i]);
        process[i] = i+1;
    }
    printf("Enter the burst time : ");
    for(int i=0; i<totalProcess; i++){
        scanf("%f", &burst[i]);
    }
    printf("Enter the priority : ");
    for(int i=0; i<totalProcess; i++){
        scanf("%d", &priority[i]);
    }
    float sumBurst=0;
    //getting total run time required
    for(int i=0; i<totalProcess; i++){
        sumBurst += burst[i];
    }
    //sorting with arrival time
    sort_at(totalProcess);
    
    print_values(totalProcess);

    //completion calculation
    for(int i=0; i<totalProcess; i++){
        for(float j=0; j<sumBurst; j++){
            int index=0, k=i;
            if(arival[i] == 0){
                completion[i] = burst[i];
                j += burst[i];
            }
            else{
                if(j > arival[i]){
                    while(j < arival[index]){
                        index++;
                    }
                    sort_priority(totalProcess, i, index);
                    while(k < index){
                        completion[k] = arival[k] + completion[k-1];
                        j += burst[k];
                        k++;
                    }
                }
                else{
                    completion[i] = arival[i] + burst[i];
                }
            }
        }
    }
    print_values(totalProcess);

    return 0;
}