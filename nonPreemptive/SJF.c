#include<stdio.h>
#include<stdbool.h>
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
void sort_arrivalTime(int procNo[], float arival[], float burst[], int numberOfProcess){
    for(int i=0; i<numberOfProcess; i++){
        for(int j=0; j<numberOfProcess-1; j++){
            if(arival[j] > arival[i]){
                swapInt(procNo, i, j);
                swapFloat(arival, i, j);
                swapFloat(burst, i, j);
            }
        }
    }
}
void sort_burst(int procNo[], float arival[], float burst[], int numberOfProcess, int k){
    for(int i=k; i<numberOfProcess; i++){
        int index=i;
        for(int j=i+1; j<numberOfProcess; j++){
            if(burst[j] < burst[i]){
                swapInt(procNo, i, j);
                swapFloat(arival, i, j);
                swapFloat(burst, i, j);
            }
        }
    }
}
void print_values(int procNo[], float arival[], float burst[], float completion[], float waiting[], float turnaround[], int numberOfProcess){
    printf("ProcNum\tArivalTime\tBurstTime\tCompletionTime\tWaitingTime\tTurnaroundTime\n");
    for(int i=0; i<numberOfProcess; i++){
        for(int j=0; j<6; j++){
            switch(j){
                case 0:
                    printf("\n%.1d\t\t", procNo[i]);
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
    int numberOfProcess; 
    printf("Enter number of processes : ");
    scanf("%d", &numberOfProcess);
    
    float arival[numberOfProcess];
    float burst[numberOfProcess];
    float completion[numberOfProcess];
    float waiting[numberOfProcess]; 
    float turnaround[numberOfProcess], sumwt=0, sumtt=0, avgwt, avgtt;
    int procNo[numberOfProcess]; bool flag = true;
   
    //input for processes
    printf("Enter the arrivaltime : ");
    for(int i=0; i<numberOfProcess; i++){
        procNo[i] = i+1;
        scanf("%f", &arival[i]);
    }
    printf("Enter the bursttime : ");
    for(int i=0; i<numberOfProcess; i++){
        scanf("%f", &burst[i]);
    }
    
    //sorting by arival time
    sort_arrivalTime(procNo, arival, burst, numberOfProcess);
    printf("\n");


    //checking if all processes arive at zero
    for(int i=0; i<numberOfProcess; i++){
        if(arival[i] != 0){
            flag = false;
        }
    }

    //completion calc
    for(int i=0; i<numberOfProcess; i++){
        if(flag && i==0){
            sort_burst(procNo, arival, burst, numberOfProcess, i);
            completion[0] = burst[0];
        }
        else{ 
            if(i == 0){
                completion[0] = burst[0];
            }
            else{    
                if(completion[i-1] < arival[i]){
                    completion[i] = arival[i] + burst[i];
                }
                if(burst[i-1] > arival[numberOfProcess-1]){
                    sort_burst(procNo, arival, burst, numberOfProcess, i);
                }
                completion[i] = completion[i-1] + burst[i];
            }
        }
    }

    //waiting and turnaround calc
    for(int i=0; i<numberOfProcess; i++){
        waiting[i] = completion[i] - arival[i] - burst[i];
        turnaround[i] = completion[i] - arival[i];
    }
    for(int i=0; i<numberOfProcess; i++){
        sumwt = sumwt+waiting[i];
        sumtt = sumtt+turnaround[i];
    }
    avgwt = sumwt/numberOfProcess; avgtt = sumtt/numberOfProcess;

    //printing values
    print_values(procNo, arival, burst, completion, waiting, turnaround, numberOfProcess);
    printf("AverageWaitingTime = %0.1f, and AverageTurnaroundTime = %0.1f\n", avgwt, avgtt);
    return 0;
}