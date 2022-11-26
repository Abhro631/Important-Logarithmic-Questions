#include<iostream>
using namespace std;
bool isSafe(int** arr,int x,int y,int n){
    for(int rows=0;rows<x;rows++){
        if (arr[rows][y]==1){
            return false;
        }
    }
    int rows=x;
    int col=y;
    while(rows>=0 && col>=0){
        if(arr[rows][col]==1){
            return false;
        }
        rows--;
        col--;
    }
    rows=x;
    col=y;
    while(rows>=0 && col<n){
        if(arr[rows][col]==1){
            return false;
        }
        rows--;
        col++;
    }
    return true;
}
bool nQueen(int** arr,int x,int n){
   if(x>=n){
       return true;
   }
   for(int col=0;col<n;col++){
       if(isSafe(arr,x,col,n)){
       arr[x][col]=1;
   if(nQueen(arr,x+1,n)){
       return true;
   }
   arr[x][col]=0;
}
   }
   return false;
}
int main(){
    int n,i,j;
    cin>>n;
    int** arr=new int *[n];
    for (i=0;i<n;i++){
        arr[i]=new int[n];
        for ( j=0;j<n;j++){
           arr[i][j]=0;
           }
    }
    if (nQueen(arr,0,n)){
        for (i=0;i<n;i++){
        for ( j=0;j<n;j++){
           cout<<arr[i][j]<<" ";
           }cout<<endl;
    }

    }
}
