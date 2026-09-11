// Q筆詢問p的第K層祖先
// Q<=100000    N<=100000
// 輸入：
//  N Q
//  son parent (*N-1)
//  p k (*Q)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin>>N>>Q;
    const int LOG=20;
    int up[N][LOG]={0};
    for(int i=0;i<N-1;i++){
        int son,parent;
        cin>>son>>parent;
        up[son][0]=parent;
    }
    for(int j=1;j<LOG;j++){
        for(int i=0;i<N;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    for(int nothing=0;nothing<Q;nothing++){
        int p,k;
        cin>>p>>k;
        for(int j=0;j<LOG;j++){
            if(k & (1<<j)){
                p=up[p][j];
            }
        }
        cout<<p;
    }
}