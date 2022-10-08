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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,v[N],fa[N],k,x[N],xx[N],xxx[N<<2],d[N],ans;
vector<int> ch[N];

void f(int u){
	int z=xxx[d[u]%k];
	for(int i=0;i<signed(ch[u].size());i++)f(ch[u][i]),xx[u]^=xx[ch[u][i]];
	z^=xxx[d[u]%k];
	int p=v[u]&(k*2-1);
	if(p&k)xx[u]^=k,p-=k;
	xx[u]^=z;
	xxx[(p+d[u])%k]^=k;
//	while(now!=0){
//		if(p==k)xx[now]^=k,p-=k;
//		++p,now=fa[now];
//	}
	x[u]^=xx[u];
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=2;i<=n;i++)fa[i]=read(),ch[fa[i]].push_back(i),d[i]=d[fa[i]]+1;
	for(int i=0;i<=21;i++){
		k=1<<i;
		for(int i=0;i<=n;i++)x[i]=xx[i]=0;
		for(int i=0;i<=k;i++)xxx[i]=0;
		f(1);
		for(int i=1;i<=n;i++)ans+=x[i];
	}
	printf("%lld\n",ans);
	return 0;
}
