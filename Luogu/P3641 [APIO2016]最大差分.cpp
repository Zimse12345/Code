/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
// #include "gap.h"
// #include "./interactive_lib.cpp"

const long long INF=1000000000000000000;

extern "C" void MinMax(long long,long long,long long*,long long*);
extern "C" long long findGap(int,int);

long long findGap(int T,int n){
    if(T==1){
        long long L,R,ans=0;
        MinMax(0ll,INF,&L,&R),n-=2;
        while(L+1<R&&n>=0){
            if(n==0){
                ans=std::max(ans,R-L);
                break;
            }
            long long _l,_r;
            MinMax(L+1,R-1,&_l,&_r),n-=2;
            if(_l==-1){
                ans=std::max(ans,R-L);
                break;
            }
            ans=std::max(ans,std::max(_l-L,R-_r));
            L=_l,R=_r;
        }
        return ans;
    }
    long long L,R;
    MinMax(0ll,INF,&L,&R);
    long long ans=(R-L+1-n)/(n-1)+1;
    long long pre=L;
    for(long long l=L,r=L-1;l<=R;l=r+1){
        r=std::min(R,l+ans);
        long long _l,_r;
        MinMax(l,r,&_l,&_r);
        if(_l!=-1){
            ans=std::max(ans,_l-pre);
            pre=_r;
        }
        else ans=std::max(ans,r-pre);
    }
    return ans;
}