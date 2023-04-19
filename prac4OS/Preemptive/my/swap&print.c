#define size 10

int process[size], priority[size];
float arival[size], burst[size], completion[size], waiting[size], turnaround[size];

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
void print_values(int numberOfProcess){
    printf("ProcNum\tArivalTime\tBurstTime\tCompletionTime\tWaitingTime\tTurnaroundTime\n");
    for(int i=0; i<numberOfProcess; i++){
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