#include<stdio.h>
#include<windows.h>
int i,wt[20],tat[20],totalwait,totalturn;
int nop=1;
int avgwt,avgtat;
int pr[20],arrival[20],burst[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	printf("\t\t\tShortest Job First\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
	scanf("%d",&nop); 	//total no of processes
	
	for(i=0;i<nop;i++)		//input for processes
	{
		pr[i]=i;
	}
	
	for(i=0;i<nop;i++) 				//input for arrival time
	{
		printf("\nEnter arrival time for Process-ID %d:",i+1);
		scanf("%d",&arrival[i]);
	}
	
	for(i=0;i<nop;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i+1);
		scanf("%d",&burst[i]);
	}
//.............implementing operational logic................................
	for(i=0;i<nop;i++)
	{
		if(arrival[i]==0)
		{
			printf("Error!!");	
			break;
		}
		if(burst[i]<burst[i+1])
		{
			printf("\n\nProcess %d running\n",i+1);
		}
		else if(burst[i+1]<burst[i])
		{
			printf("\n\nProcess %d running\n",i+1);
		}
		sleep(2);
	}
//....................calculating avg. waiting time and avg. turnaround time............
	//turnaroundtime= completiontime-arrivaltime
	//waitingtime= turnaroundtime-bursttime
	for (i=0;i<nop;i++)  
        wt[i] =  burst[i-1] + wt[i-1] ;  //waiting time
	
	for (i=0;i<nop;i++)  
    	tat[i] = burst[i] + wt[i];  
    for(i=0;i<nop;i++)
    {
		totalwait = totalwait + wt[i];  
	    totalturn = totalturn + tat[i];  
	}
	avgwt=(float)totalwait / (float)nop; 
    avgtat=(float)totalturn / (float)nop; 
    printf("\nTotal waiting time = %d",totalwait); 
    printf("\nTotal turnaround time = %d",totalturn); 
	printf("\nAverage waiting time = %d",avgwt); 
    printf("\n"); 
    printf("\nAverage turn around time = %d ",avgtat); 
       

	return 0;
}

