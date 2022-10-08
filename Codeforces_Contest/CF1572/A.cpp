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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,n,d[N],pre[N];
queue<int> q;
vector<int> g[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)d[i]=0,pre[i]=0,g[i].resize(0);
		for(int i=1;i<=n;i++){
			int c=read();
			pre[i]=c;
			for(int j=1,u;j<=c;j++)u=read(),g[u].push_back(i);
		}
		int cnt=0,ans=-1;
		for(int i=1;i<=n;i++)if(pre[i]==0)q.push(i),d[i]=1;
		while(!q.empty()){
			int u=q.front();q.pop(),++cnt;
			ans=max(ans,d[u]);
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i];
				--pre[v];
				int h=d[u];
				if(u>v)++h;
				d[v]=max(d[v],h); 
				if(pre[v]==0)q.push(v);
//				if(u>v)d[v]=d[u]+1;
//				else d[v]=d[u];
			}
		}
		if(cnt!=n)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

