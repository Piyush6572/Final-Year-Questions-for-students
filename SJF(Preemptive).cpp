//SJF scheduling algorithm (Preemptive version)
//SJF Scheduling algorithm (non preemptive version)
#include<bits/stdc++.h>
int number;
struct pcb{
   int pid,arr,burst;
   int status;
};
typedef struct pcb pcb;

void print(pcb process[],int number,int waiting[],int tot[],int completion[]){
    int i=0;
    printf("\nProcess ID   Arrival   Burst   Waiting   Turn Around   Completion\n");
    for(i=0;i<number;i++){
    	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].arr,process[i].burst,waiting[i],tot[i],completion[i]);
    }printf("\n");
    double avgwait=0,avgtot=0;
   for(i=0;i<number;i++){
      avgwait+=waiting[i];
      avgtot+=tot[i];
   }
   avgwait = (double)avgwait/number;
   avgtot = (double)avgtot/number;
   printf("average waiting time : %lf \n average turn around time : %lf",avgwait,avgtot);
}


void burst_sort(pcb process[],int remaining[],int ready[],int upto){
    int i=0,j=0;
    int temp;
    for(j=1;j<upto;j++){
        if(remaining[ready[0]] >remaining[ready[j]]){
             temp = ready[0];
             ready[0] =ready[j];
             ready[j] =temp;
        }
        else if(remaining[ready[0]] == remaining[ready[j]]   &&   process[ready[0]].arr > process[ready[j]].arr){
             temp = ready[0];
             ready[0] =ready[j];
             ready[j] =temp;
        }
    }
}

void srtf_scheduling(pcb process[]){
   int i=0,j=0,time=0,task=0;
   int waiting[number]={0},completion[number]={0},tot[number]={0};
   int ready[number],move=0;
   int remaining[number];
   for(i=0;i<number;i++){
      remaining[i] = process[i].burst;
   }
   while(task<number){
      move=0;
      for(j=0;j<number;j++){
          if(time >= process[j].arr &&  remaining[j]!=0)
          {ready[move]=j;move++;}
      }
      if(move>0 ){
         burst_sort(process,remaining,ready,move);
         time++;
         process[ready[0]].status =1;
         remaining[ready[0]]--;
         if(remaining[ready[0]]==0){
             completion[ready[0]]=time;
             waiting[ready[0]]=time - process[ready[0]].burst-process[ready[0]].arr;
             tot[ready[0]]=time-process[ready[0]].arr;
             task++;
         }
      }
      else
      time++;
   }
   print(process,number,waiting,tot,completion);
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
   printf("Enter number of processes : ");
   scanf("%d",&number);
   int i=0;
   pcb process[number];
   for(i=0;i<number;i++){
      printf("Enter arrival time and process time of process %d :",i);
      process[i].pid = i;
      process[i].status =0;
      scanf("%d",&process[i].arr);
      scanf("%d",&process[i].burst);
   }
   srtf_scheduling(process);
   return 0;
}
