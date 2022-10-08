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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,fa[N],x[N],y[N],a[N],ans[N],vis[N],s;
vector<int> g[N];

int F(int x){
	if(x!=fa[x])fa[x]=F(fa[x]);
	return fa[x];
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)x[i]=read()+1,y[i]=read()+1,g[x[i]].push_back(y[i]),g[y[i]].push_back(x[i]);
	k=read();
	for(int i=1;i<=k;i++)a[i]=read()+1,vis[a[i]]=1;
	
	for(int i=1;i<=n;i++)if(vis[i]==0){
		++s,vis[i]=2;
		for(int j=0;j<int(g[i].size());j++){
			int to=g[i][j];
			if(vis[to]==2){
				int A=F(i),B=F(to);
				if(A!=B){
					--s;
					fa[A]=B;
				}
			}
		}
	}
	
	for(int i=k;i>=1;i--){
		ans[i]=s,vis[a[i]]=2,++s;
		for(int j=0;j<int(g[a[i]].size());j++){
			int to=g[a[i]][j];
			if(vis[to]==2){
				int A=F(a[i]),B=F(to);
				if(A!=B){
					--s;
					fa[A]=B;
				}
			}
		}
	}
	ans[0]=s;
	
	for(int i=0;i<=k;i++)printf("%d\n",ans[i]);
	return 0;
}
