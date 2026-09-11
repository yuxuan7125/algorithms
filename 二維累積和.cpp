// 二維累積和
// X*Y的方格裡有Q個矩形
// X,Y<=1000
// Q<=100,000

#include<bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,Q;
    cin>>X>>Y>>Q;
    int p[X+1][Y+1]={0};
    for(int i=0;i<Q;i++){
        int x0,x1,y0,y1;
        cin>>x0>>x1>>y0>>y1;
        p[x0][y0]++;
        p[x0][y1+1]--;
        p[x1+1][y0]--;
        p[x1+1][y1+1]++;
    }
    for(int i=1;i<=X;i++){
        for(int j=1;j<=Y;j++){
            p[i][j]+=p[i][j-1];
        }
    }
    for(int i=1;i<=X;i++){
        for(int j=1;j<=Y;j++){
            p[i][j]+=p[i-1][j];
        }
    }
}