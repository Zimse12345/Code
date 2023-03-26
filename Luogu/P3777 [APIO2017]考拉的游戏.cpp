// #include "koala.h"
void playRound(int*,int*);
#include <bits/stdc++.h>

int minValue(int N, int W) {
    // TODO: Implement Subtask 1 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    int B[128],R[128];
    memset(B,0,sizeof (int)*128);
    B[0]=1;
    playRound(B,R);
    for(int i=0;i<N;i++)if(R[i]<=B[i])return i;
    return 0;
}

int maxValue(int N, int W) {
    // TODO: Implement Subtask 2 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    int B[128],R[128],a[128],tot=0,val[4]={1,2,4,11};
    for(int i=0;i<N;i++)a[++tot]=i;
    for(int I=0;I<4;I++){
        memset(B,0,sizeof (int)*128);
        for(int i=1;i<=tot;i++)B[a[i]]=val[I];
        playRound(B,R),tot=0;
        for(int i=0;i<N;i++)if(B[i]==val[I]&&B[i]<R[i])a[++tot]=i;
    }
    return a[1];
}

int greaterValue(int N, int W) {
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    int B[128],R[128];
    memset(B,0,sizeof (int)*128);
    int l=1,r=8;
    while(l<=r){
        int mid=(l+r)/2;
        B[0]=B[1]=mid;
        playRound(B,R);
        if(B[0]<R[0]&&B[1]>=R[1])return 0;
        if(B[0]>=R[0]&&B[1]<R[1])return 1;
        if(B[0]<R[0]&&B[1]<R[1])l=std::min(r,mid+2);
        else r=mid-1;
    }
    return 0;
}

void allValues(int N, int W, int *P) {
    memset(P,0,sizeof (int)*N);
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
        int B[128],R[128],a[128];
        memset(B,0,sizeof (int)*128);
        a[1]=minValue(N,100),B[a[1]]=1,P[a[1]]=1;
        for(int i=2;i<=50;i++){
            int rm=i;
            for(int j=0;j<N;j++)if(!P[j]){
                B[j]=1,--rm;
                if(!rm)break;
            }
            playRound(B,R);
            for(int j=0;j<N;j++)if(!P[j]&&R[j]<=B[j]){
                a[i]=j,P[j]=i,B[j]=1;
                break;
            }
            for(int j=0;j<N;j++)if(B[j]<R[j])B[j]=0;
        }
        for(int i=0;i<N;i++)B[i]=1;
        for(int i=51,cur=50;i<=67;i++){
            B[a[cur--]]=0;
            if(i==51)B[a[cur--]]=0;
            else B[a[i-1]]=0;
            playRound(B,R);
            for(int j=0;j<N;j++)if(!P[j]&&R[j]<=B[j]){
                a[i]=j,P[j]=i;
                break;
            }
        }
    }
}
