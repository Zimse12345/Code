#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int L,R,dig[N],w;

inline int p(int x,int y){
    int z=1;
    while(y>0){
        --y;
        z*=x;
    }
    return z;
}

inline int c(int n){
    w=0;
    while(n)dig[++w]=n%10,n/=10;
    int res=0;
    for(int i=w-1;i>=1;i--){
        for(int j=dig[i]-1;j>=0;j--){
            if(j>=dig[w])continue;
            res+=p(dig[w],i-1);
        }
        if(dig[i]>=dig[w])break;
    }
    for(int i=dig[w]-1;i>0;i--)res+=p(i,w-1);
    for(int i=9;i>0;i--){
        for(int j=w-2;j>=0;j--)res+=p(i,j);
    }
    int tag=1;
    for(int i=1;i<w;i++)if(dig[i]>=dig[w])tag=0;
    return res+tag;
}

signed main(){
    cin>>L>>R;
    printf("%lld\n",c(R)-c(L-1));
    return 0;
}


