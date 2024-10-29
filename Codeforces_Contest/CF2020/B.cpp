#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T;
long long n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long v=(long long)(floor(sqrt(n)));
        while(v*v>n)--v;
        while((v+1)*(v+1)<=n)++v;
        long long x=n+v;
        while(1){
            while((v+1)*(v+1)<=x)++v;
            if(x-v>=n)break;
            ++x;
        }
        printf("%lld\n",x);
    }
    return 0;
}


