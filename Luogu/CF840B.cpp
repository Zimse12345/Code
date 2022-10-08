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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,m,d[N],rt=1,fa[N],cnt[N],ans[N],tot;
vector<int> to[N],k[N];

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

int dfs(int u,int pr){
	int p=0;
	for(int i=0,v;i<int(to[u].size());i++){
		if(k[u][i]==pr)continue;
		v=to[u][i];
		p+=dfs(v,k[u][i]);
	}
	p%=2;
	if((p==1&&d[u]==0)||(p==0&&d[u]==1)){
		ans[++tot]=pr;
		return 1;
	}
	return 0;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		fa[i]=i,cnt[i]=1;
		d[i]=read();
		if(d[i]==-1)rt=i;
	}
	for(int i=1,x,y,A,B;i<=m;i++){
		x=read(),y=read();
		A=F(x),B=F(y);
		if(A!=B){
			if(cnt[A]<cnt[B])fa[A]=B,cnt[B]+=cnt[A];
			else fa[B]=A,cnt[A]+=cnt[B];
			to[x].push_back(y),to[y].push_back(x);
			k[x].push_back(i),k[y].push_back(i);
		}
	}
	if(dfs(rt,0)){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",tot);
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)printf("%d\n",ans[i]);
	return 0;
}
