#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=1000000007;
int T,a,b,k;

inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int n,int m){
    int res=1;
    for(int i=1;i<=m;i++)res=res*(n-i+1)%Mod*fpow(i)%Mod;
    res=(res+Mod)%Mod;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>k;
        int n=((a-1)*k+1)%Mod,m=(k*(b-1)%Mod*C(n,a)+1)%Mod;
        printf("%lld %lld\n",n,m);
    }
    return 0;
}


