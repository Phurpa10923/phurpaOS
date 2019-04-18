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
do{


for(i=0;i<n;i++){
	
	printf("\t\t\tP%d\t\t %d \t\t\t %d\n",pp.pro[i],pp.arrival[i],pp.burst[i]);\
	
}



for(j=0;j<n;j++){
pp.pro[j]=pp.pro[j+1];
pp.burst[j]=pp.burst[j+1];
pp.arrival[j]=pp.arrival[j+1];

}


sleep(2);

n=n-1;
p++;
}while(n!=0);



return 0;
}
