#include<iostream>
using namespace std;
bool isSafe(int** arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinMaze(int** arr,int x,int y,int n,int** sArray){
    if(x==n-1 && y==n-1 ){
      sArray[x][y]==1;
      return true;
    }
    if(isSafe(arr,x,y,n)){
        sArray[x][y]=1;
        if (ratinMaze(arr,x+1,y,n,sArray)){
            return true;
        }
        if (ratinMaze(arr,x,y+1,n,sArray)){
            return true;
        }
        sArray[x][y]=0; //bactracking
        return false;

    }
    return false;
}

int main(){
    int n,i,j;
    cin>>n;
    int** arr=new int *[n];
    for (i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for ( i=0;i<n;i++){
        for ( j=0;j<n;j++){
           cin>>arr[i][j];
           }
    }
    int** sArray=new int *[n];
    for (i=0;i<n;i++){
        sArray[i]=new int[n];
        for(j=0;j<n;j++){
            sArray[i][j]=0;

        }
    }
   if( ratinMaze(arr,0,0,n,sArray)){
        for (i=0;i<n;i++){
        for (j=0;j<n;j++){
           cout<<sArray[i][j]<<" ";}
           cout<<endl;
    }
    }
}
