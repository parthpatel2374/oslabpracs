#include<stdio.h>
void sortarr(float arr[][6], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            int index = i;
            if(arr[j][2] > arr[i][2]){
                index = j;
            }
            int temp = arr[index][0];
            arr[index][0] = arr[i][0];
            arr[i][0] = temp;
            
            temp = arr[index][1];
            arr[index][1] = arr[i][1];
            arr[i][1] = temp;
            
            temp = arr[index][2];
            arr[index][2] = arr[i][2];
            arr[i][2] = temp;
        }
    }
}
void printarr(float arr[][6], int n){
    printf("num\tbt\tat\tct\twt\ttt\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            printf("%.2f\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    float proc[10][6], sumw=0, sumt=0, avgw, avgt;
    printf("Enter the bursttime;\n");
    for(int i=0; i<n; i++){
        scanf("%f", &proc[i][1]);
        proc[i][0] = i+1;
    }
    printf("Enter the arrivaltime;\n");
    for(int i=0; i<n; i++){
        scanf("%f", &proc[i][2]);
    }
    sortarr(proc, n);

    proc[0][3] = proc[0][1];
    for(int i=1; i<n; i++){
        proc[i][3] = proc[i-1][3] + proc[i][1];
    }
    //waiting and turnaround time;
    for(int i=0; i<n; i++){
        proc[i][4] = proc[i][3] - proc[i][2] - proc[i][1];
        proc[i][5] = proc[i][3] - proc[i][2];
        sumw = sumw + proc[i][4];
        sumt = sumt + proc[i][5];
    }
    avgw = sumw/n;
    avgt = sumt/n;

    printarr(proc, n);
    printf("avg(w = %f, t = %f)\n", avgw, avgt);
}