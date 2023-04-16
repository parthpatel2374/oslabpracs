#include<stdio.h>
#define size 10

int process[size];
float arival[size], burst[size], completion[size], waiting[size], turnaround[size], sumwt=0, sumtt=0, avgwt, avgtt;

void swapFloat(float arr[], int upperIndex, int lowerIndex){
    float temp = arr[lowerIndex];
    arr[lowerIndex] = arr[upperIndex];
    arr[upperIndex] = temp;
}
void swapInt(int arr[], int upperIndex, int lowerIndex){
    int temp = arr[lowerIndex];
    arr[lowerIndex] = arr[upperIndex];
    arr[upperIndex] = temp;
}
void sort_at(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            int index = i;
            if(arival[j] > arival[i]){
                swapInt(process, i, j);
                swapFloat(arival, i, j);
                swapFloat(burst, i, j);
            }
        }
    }
}
void print_values(int n){
    printf("ProcNum\tArivalTime\tBurstTime\tCompletionTime\tWaitingTime\tTurnaroundTime\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            switch(j){
                case 0:
                    printf("\n%.1d\t\t", process[i]);
                    break;
                case 1:
                    printf("%.1f\t\t", arival[i]);
                    break;
                case 2:
                    printf("%.1f\t\t", burst[i]);
                    break;
                case 3:
                    printf("%.1f\t\t", completion[i]);
                    break;
                case 4:
                    printf("%.1f\t\t", waiting[i]);
                    break;
                case 5:
                    printf("%.1f\t\t", turnaround[i]);
                    break;
            }
        }   
    }
    printf("\n");
}
int main(){
    int totalProcess; 
    printf("Enter number of processes : ");
    scanf("%d", &totalProcess);
    
    //input for processes
    printf("Enter the arrivaltime : ");
    for(int i=0; i<totalProcess; i++){
        process[i] = i+1;
        scanf("%f", &arival[i]);
    }
    printf("Enter the bursttime : ");
    for(int i=0; i<totalProcess; i++){
        scanf("%f", &burst[i]);
    }
    
    //sorting by arival time
    sort_at(totalProcess);
    printf("\n");

    //completion time
    completion[0] = burst[0];
    for(int i=1; i<totalProcess; i++){
        if(completion[i-1] < arival[i]){
            completion[i] = arival[i] + burst[i];
        }
        else{
            completion[i] = completion[i-1] + burst[i];
        }
    }
    
    //waiting and turnaround calc
    for(int i=0; i<totalProcess; i++){
        waiting[i] = completion[i] - arival[i] - burst[i];
        turnaround[i] = completion[i] - arival[i];
    }
    for(int i=0; i<totalProcess; i++){
        sumwt = sumwt+waiting[i];
        sumtt = sumtt+turnaround[i];
    }
    avgwt = sumwt/totalProcess; avgtt = sumtt/totalProcess;

    //printing values
    print_values(totalProcess);
    printf("AverageWaitingTime = %0.2f, and AverageTurnaroundTime = %0.2f\n", avgwt, avgtt);
    return 0;
}