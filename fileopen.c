#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char*argv[]){
    FILE*fp;
    char c;
    int sc=0;
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        printf("Unable to open file");
    }
    else{
        while( !feof(fp)){
            c=fgetc(fp);
            if(c==' '){
                sc++;
            }
        }
        printf("%d",sc);
    }

}