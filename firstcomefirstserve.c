#include <stdio.h>
int main(){
	int n,pid[20],bt[20];
	int i;
	printf("Enter number of processes[Max:20]\n");
	scanf("%d",&n);
	printf("Enter process id's\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("Enter brust times:\n");
	for(i=0;i<n;i++){
		printf("p[%d]: ",pid[i]);
		scanf("%d",&bt[i]);
	}
	int wt[n];
	wt[0]=0;
	int tat[n];
	float twt = 0.0;
	float ttat = 0.0;

	//wating times
	for(i=1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];
		twt+=wt[i];
	}
	//trunaround time
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		ttat +=tat[i];
	}
	printf("\n\t FIRST COME FIRST SERVE\n");
	printf("\nPID \t Brust Time \t Wating Time \t Trunaround Time\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t %d\t\t %d\t\t %d",pid[i],bt[i],wt[i],tat[i]);
	}
	printf("\nThe Average Wating time:%g\n",twt/2);
	printf("The Average Turnaround time:%g\n",ttat/2);
	
}
