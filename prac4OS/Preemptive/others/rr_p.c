#include <stdio.h>
int main()
{
    // BT -- Burst Time
    // WT -- Waiting Time
    // TAT -- Turn around time
    // AWT -- average waiting time
    // ATAT -- average turn around time
    // TS -- Time slice
    // AT -- arrival time
    int i, n, sum = 0, count = 0, y, TS, WT = 0, TAT = 0, AT[10], BT[10], temp[10];
    float AWT, ATAT;
    printf("Total number of process in the system : ");
    scanf("%d", &n);
    y = n;

    //input for processes
  printf("Enter the arrivaltime : ");
  for(int i=0; i<n; i++){
    scanf("%d", &AT[i]);
  }
  printf("Enter the bursttime : ");
  for(int i=0; i<n; i++){
    scanf("%d", &BT[i]);
    temp[i] = BT[i];
  }
    // Time slice
    printf("Enter the Time Slice for the process : ");
    scanf("%d", &TS);
    // outcome
    printf("\nProcess No \t\t BT \t\t TAT \t\t WT ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= TS && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - TS;
            sum = sum + TS;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            printf("\nProcess[%d] \t\t %d\t\t %d\t\t%d", i + 1, BT[i], sum - AT[i], sum - AT[i] - BT[i]);
            WT = WT + sum - AT[i] - BT[i];
            TAT = TAT + sum - AT[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (AT[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    // average waiting time and Turn Around time
    AWT = WT * 1.0 / n;
    ATAT = TAT * 1.0 / n;
    printf("\nAverage Turn Around Time: \t%.2f", AWT);
    printf("\nAverage Waiting Time: \t%.2f\n", ATAT);
}