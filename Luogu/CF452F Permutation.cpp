#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,H=41,Mod=998244353,INF=1e9+7;
int n,a[N],pow1[N];
int t[2][N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int id,int x,int y){for(;x<N;ub(x))t[id][x]=(t[id][x]+y+Mod)%Mod;return;}
inline int sum(int id,int x){int res=1;for(;x;db(x))res=(res+t[id][x])%Mod;return res;}

inline int fpow(int x,int k){
    int res=1;
    while(k){
        if(k&1ll)res=res*x%Mod;
        x=x*x%Mod,k/=2;
    }
    return res;
}

inline int inv(int x){
    return fpow(x,Mod-2);
}

inline int lh(int L,int R){
    return (sum(0,R)-sum(0,L-1)+Mod)*inv(pow1[L])%Mod;
}

inline int rh(int L,int R){
    return (sum(1,R)-sum(1,L-1)+Mod)*inv(pow1[n-R+1])%Mod;
}

signed main(){
	n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    pow1[0]=1;
    for(int i=1;i<=n;i++)pow1[i]=pow1[i-1]*H%Mod;
    for(int i=1;i<=n;i++){
        if((a[i]*2-1<=n&&lh(1,a[i])!=rh(a[i],a[i]*2-1))||(a[i]*2-1>n&&lh(a[i]*2-n,a[i])!=rh(a[i],n))){
            printf("Yes\n");
            return 0;
        }
        add(0,a[i],pow1[a[i]]%Mod);
        add(1,a[i],pow1[n-a[i]+1]%Mod);
    }
    printf("No\n");
	return 0;
}
 
