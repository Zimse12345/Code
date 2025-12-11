#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int Q,v[N],c[N],l=1,r=0;

signed main(){
    cin>>Q;
    while(Q--){
        int ty,x=0,y=0;
        cin>>ty>>x;
        if(ty==1){
            cin>>y;
            ++r;
            c[r]=x;
            v[r]=y;
        }
        else{
            int sum=0;
            while(c[l]<x)x-=c[l],sum+=c[l]*v[l],++l;
            sum+=x*v[l],c[l]-=x;
            printf("%lld\n",sum);
        }
    }
    return 0;
}


