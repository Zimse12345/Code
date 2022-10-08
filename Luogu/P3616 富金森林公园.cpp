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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],op[N],x[N],y[N],rk;
set<int> val;
map<int,int> V;
int tr[2][N];

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x,int t,int k){if(!x)return;for(;x<N;ub(x))tr[k][x]+=t;return;}
inline int sum(int x,int k){int res=0;for(;x;db(x))res+=tr[k][x];return res;}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),val.insert(a[i]);
	for(int i=1;i<=m;i++){
		op[i]=read(),x[i]=read();
		if(op[i]==2)y[i]=read(),val.insert(y[i]);
		else val.insert(x[i]);
	}
	for(set<int>::iterator it=val.begin();it!=val.end();it++)V[*it]=++rk;
	V[0]=0;
	for(int i=1;i<=n+1;i++){
		a[i]=V[a[i]];
		add(max(a[i],a[i-1]),1,0);
		add(min(a[i],a[i-1]),1,1);
	}
	for(int i=1;i<=m;i++){
		if(op[i]==1){
			x[i]=V[x[i]];
			int ans=(sum(N-1,0)-sum(x[i]-1,0)-sum(N-1,1)+sum(x[i]-1,1))/2;
			printf("%d\n",ans);
		}
		else{
			y[i]=V[y[i]];
			add(max(a[x[i]],a[x[i]-1]),-1,0),add(min(a[x[i]],a[x[i]-1]),-1,1);
			add(max(a[x[i]],a[x[i]+1]),-1,0),add(min(a[x[i]],a[x[i]+1]),-1,1);
			a[x[i]]=y[i];
			add(max(a[x[i]],a[x[i]-1]),1,0),add(min(a[x[i]],a[x[i]-1]),1,1);
			add(max(a[x[i]],a[x[i]+1]),1,0),add(min(a[x[i]],a[x[i]+1]),1,1);
		}
	}
	return 0;
}

