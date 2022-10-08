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

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=2e5+7,Mod=998244353,INF=2e9+7;
int n,a[N],fa[N];
ll ans;
vector<int> ch[N];
priority_queue<int> q[N];

void dfs(int u){
	priority_queue<int> p;
	for(int i=0,v;i<signed(ch[u].size());i++){
		v=ch[u][i];
		dfs(v);
		if(q[v].size()>q[u].size())swap(q[u],q[v]);
		while(!q[v].empty()){
			p.push(max(q[u].top(),q[v].top()));
			q[u].pop(),q[v].pop();
		}
		while(!p.empty())q[u].push(p.top()),p.pop();
	}
	q[u].push(a[u]);
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)fa[i]=read(),ch[fa[i]].push_back(i);
	dfs(1);
	while(!q[1].empty())ans+=q[1].top(),q[1].pop();
	printf("%lld\n",ans);
	return 0;
}

