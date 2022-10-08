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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,p[N][30],a[N],mx,indeg[N],bc,t[N],tag[N];
set<int> val;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)p[i][0]=read(),val.insert(i),++indeg[p[i][0]];
	for(int i=1;i<=n;i++){
		a[i]=read(),mx=max(mx,a[i]),t[i]=i;
		if(!indeg[i])++bc;
		if(a[i]<=n)val.erase(a[i]);
	}
	m=(mx-n)/bc;
	for(int i=1;i<=29;i++)for(int j=1;j<=n;j++)p[j][i]=p[p[j][i-1]][i-1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=29;j++)if(m&(1<<j))t[i]=p[t[i]][j];
	}
	for(int i=1;i<=n;i++){
		if(!tag[t[i]])printf("%d ",a[t[i]]),tag[t[i]]=1;
		else printf("%d ",*val.upper_bound(a[t[i]])),val.erase(val.upper_bound(a[t[i]]));
	}
	printf("\n");
	return 0;
}

