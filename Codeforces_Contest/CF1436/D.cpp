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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],tag,rm[N],M;
vector<int> ch[N];

void dfs(int u){
	if(ch[u].size()==0){
		rm[u]=M-a[u];
		if(rm[u]<0)tag=0;
		return;
	}
	rm[u]=0;
	for(unsigned i=0;i<ch[u].size();i++){
		dfs(ch[u][i]);
		rm[u]+=rm[ch[u][i]];
	}
	rm[u]-=a[u];
	if(rm[u]<0)tag=0;
	return;
}

signed main(){
	n=read();
	for(int i=2,f;i<=n;i++)f=read(),ch[f].push_back(i);
	int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(ch[i].size()==0)++cnt;
	}
	int L=0,R=2e18/cnt,ans=0;
	while(L<=R){
		M=(L+R)/2;
		tag=1;
		dfs(1);
		if(tag)ans=M,R=M-1;
		else L=M+1;
	}
	printf("%lld\n",ans);
	return 0;
}

