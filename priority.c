#include<stdio.h>
int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESS TO ENTER\n");
    scanf("%d",&n);
    int arr[100];
    printf("Enter the burst time of each process\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the priority sequence of elements\n");
    int a[100];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
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
    float avg=totalw/n;
  float avg2=turn/n;
   printf("avg waiting time %f \n",avg);
      printf("avg turn around time %f \n",avg2);

}