#include<stdio.h>
int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESS TO ENTER\n");
    scanf("%d",&n);
    int arr[100];
    printf("Enter the burst time of each process");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int totalw=0;
    int ans[100];
    ans[0]=0;
    int sum=arr[0];
    for(int i=1;i<=n;i++){
        ans[i]=sum;
        sum+=arr[i];

    }
    printf("the waiting time is\n");
    for(int i=0;i<n;i++){
        totalw+=ans[i];
        printf("%d\n",ans[i]);
    }
    int turn=0;
    printf("the turn around time is\n");
    for(int i=1;i<=n;i++){
        turn+=ans[i];
         printf("%d\n",ans[i]);
    }
    double avg=(double)totalw/n;
  double avg2=(double)turn/n;
   printf("avg waiting time %.2f \n",avg);
      printf("avg turn around time %.2f \n",avg2);
}