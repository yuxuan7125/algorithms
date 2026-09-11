// 優先佇列 Priority Queue
// Q比操作：
// 1：加入
// 2：取出最大值
// Q<=100,000

#include<bits/stdc++.h>
using namespace std;

vector<int> pq;

void UpHeap(int i){
    if(i==0) return;
    int k=(i-1)/2;
    if(pq[i]>pq[k]){
        swap(pq[i],pq[k]);
        UpHeap(k);
    }
}

void DownHeap(int i){
    int k=(i+1)*2;
    int len=pq.size();
    if(k>=len){
        k--;
        if(k>=len) return;
    }
    else if(pq[k]<pq[k-1]) k--;
    if(pq[i]<pq[k]){
        swap(pq[i],pq[k]);
        DownHeap(k);
    }
}

int main(){
    int Q;
    cin>>Q;
    for(int ntg=0;ntg<Q;ntg++){
        int type,num;
        cin>>type;
        if(type==1){
            cin>>num;
            pq.push_back(num);
            UpHeap(pq.size()-1);
        }
        if(type==2){
            cout<<pq[0];
            pq[0]=pq.back();
            pq.pop_back();
            DownHeap(0);
        }
    }
}