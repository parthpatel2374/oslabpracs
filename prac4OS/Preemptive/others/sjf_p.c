#include <stdio.h>
int main() 
{
  //BT -- Burst Time
  //WT -- Waiting Time
  //TAT -- Turn around time
  //AWT -- average waiting time
  //ATAT -- average turn around time
  int AT[10], BT[10], temp[10];
  int i, smallest, count = 0, time, n;
  double WT = 0, TAT = 0, end;
  float AWT, ATAT;
  printf("\nEnter the Total Number of Processes : ");
  scanf("%d", &n); 
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
  BT[9] = 9999;  
  for(time = 0; count != n; time++)
  {
    smallest = 9;
    for(i = 0; i < n; i++)
    {
      if(AT[i] <= time && BT[i] < BT[smallest] && BT[i] > 0)
      {
        smallest = i;
      }
    }
    BT[smallest]--;
    if(BT[smallest] == 0)
    {
      count++;
      end = time + 1;
      WT = WT + end - AT[smallest] - temp[smallest];
      TAT = TAT + end - AT[smallest];
    }
  }
  AWT = WT / n; 
  ATAT = TAT / n;
  printf("\n\nAverage Waiting Time:\t%.2lf\n", AWT);
  printf("Average Turnaround Time:\t%.2lf\n", ATAT);
  return 0;
}