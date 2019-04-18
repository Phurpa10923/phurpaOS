#include<stdio.h>
#include<stdlib.h>




int main(){

int n,m,i,j=0,p=0;
int min=0,min_index;
printf("Enter no of process :");
scanf("%d",&n);
m=n;

struct process{
	
	int pro[n];
	int burst[n];
	int arrival[n];
	int wait_t;
	int turn_t;
} pp;

for(i=0;i<n;i++){



printf("\nEnter Arrival time for process %d :",i);
scanf("%d",&pp.arrival[i]);
if(pp.arrival[i]==0){
	printf("****Wrong arrival time8*******\n");
	printf("\nEnter again : ");
	scanf("%d",&pp.arrival[i]);
}

printf("\nEnter burst time for process %d :",i);
scanf("%d",&pp.burst[i]);
printf("\n\n");

pp.pro[i]=i+1;

}


for(i=0;i<n;i++){
	int temp=0,temp1=0,temp2=0;
	for(j=i+1;j<n;j++){
		if(pp.burst[i]>pp.burst[j]){
		
			temp=pp.burst[i];
			temp1=pp.arrival[i];
			pp.burst[i]=pp.burst[j];
			pp.arrival[i]=pp.arrival[j];
			pp.burst[j]=temp;
			pp.arrival[j]=temp1;
			
			
		}
	}
}



pp.turn_t=0;
pp.wait_t=0;


do{
printf("\n\n");	
printf("\n\t========================================================================================================\n");
printf("\n\t========================================================================================================\n");

printf("\n\n\t\t\t********************The Processes Are************************ \n\n");
printf("\n\t\t\tProcess \tArrival time \t Burst time  \n");

for(i=0;i<n;i++){
	
	printf("\t\t\tP%d\t\t %d \t\t\t %d\n",pp.pro[i],pp.arrival[i],pp.burst[i]);\
	
}

printf("\n\n\t\t\t************************************");
printf("\n\n\t\t\tProcess p%d  is done!!!!\n\n",pp.pro[0]);
printf("\t\t\t************************************\n");

if(p==0){
	pp.turn_t=pp.burst[0];
	pp.wait_t=0;
}
else{
pp.wait_t=pp.turn_t-pp.arrival[0];
pp.turn_t=pp.turn_t+pp.burst[0];

}
for(j=0;j<n;j++){
pp.pro[j]=pp.pro[j+1];
pp.burst[j]=pp.burst[j+1];
pp.arrival[j]=pp.arrival[j+1];

}
printf("\t\t\tTurn Around time : %d",pp.turn_t);
printf("\t\t\t\tWaiting time : %d\n",pp.wait_t);	


sleep(2);





n=n-1;
p++;
}while(n!=0);
printf("\n\n\n\n");
printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Final Result ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("\t===========================================================================================");
float avg=pp.wait_t/m;
printf("\n\n\t\tAverage Waiting time : %f",avg);
float avg1=pp.turn_t/m;
printf("\t\t\tAverage Turnaround time : %f",avg1);





if(n==0){
	printf("\n\n\nThank you :):):)");
}


return 0;
}
