#include<stdio.h>
int main(){
        int n;
    int m;
    printf("Enter the proccess number-");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the memory block-");
    scanf("%d",&m);
     printf("\n");
     printf("Enter the process space\n");
    int memory[100];
    int process[100];
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
     printf("Enter the memory space\n");
      for(int i=0;i<m;i++){
        scanf("%d",&memory[i]);
    }

    int allocation[100];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }

    for(int i=0;i<n;i++){
        int max=0;
        int index=-1;
        for(int j=0;j<m;j++){
            if(max<memory[j]){
                max=memory[j];
                index=j;
            }
        }
        if(max>=process[i]){
            memory[index]-=process[i];
            allocation[i]=index;
        }
    }
     for(int i=0;i<n;i++){
        printf("PROCESS %d -> ",i);
        if(allocation[i]==-1){
            printf("NOT ALLOCATED");
        }
        else{
            printf("Allocated to %d memory block",allocation[i]+1);
        }
        printf("\n");
    }
}