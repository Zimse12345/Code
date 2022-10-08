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
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
int t[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){++x;for(;x<N;ub(x))t[x]+=y;return;}
inline int sum(int x){++x;int res=0;for(;x;db(x))res+=t[x];return res;}

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]<i)ans+=sum(a[i]-1),add(i,1);
		}
		for(int i=1;i<=n;i++)if(a[i]<i)add(i,-1);
		printf("%lld\n",ans);
	}
	return 0;
}

