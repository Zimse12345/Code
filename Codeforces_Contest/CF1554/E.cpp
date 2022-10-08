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

#define int long long
#define ull unsigned long long

using namespace std;

int gcd(int x,int y){if(x==0)return y;return y==0?x:gcd(y,x%y);}
int read(){int __x=0,__y=1;char __c=getchar();
while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],vis[N],fa[N],tag,ans,k,b[N];
vector<int> g[N],ch[N];

void init_t(int u,int f){
	fa[u]=f,vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v])ch[u].push_back(v),init_t(v,u);
	}
	return;
}

int dfs(int u){
	int c=0;
	for(int i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		c+=dfs(v);
	}
	if(c%k==0){
		ans=gcd(ans,c);
		return 1;
	}
	if((c+1)%k==0&&u!=1){
		ans=gcd(ans,c+1);
		return 0;
	}
	tag=0;
	return 0;
}

signed main(){
	T=read();
	b[0]=1;
	for(int i=1;i<N;i++)b[i]=(b[i-1]*2)%Mod;
	
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)vis[i]=0,a[i]=0,g[i].clear(),ch[i].clear();
		for(int i=1,u,v;i<n;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
		init_t(1,1);
		
		int m=n-1;
		for(int i=2;i*i<=m;i++){
			tag=1,ans=0,k=i,dfs(1);
			if(tag==1)a[ans]=1;
			while(m%i==0)m/=i;
		}
		if(m>0){
			tag=1,ans=0,k=m,dfs(1);
			if(tag==1)a[ans]=1;
		}
		
		a[1]=b[n-1]+Mod;
		for(int i=2;i<=n;i++)a[1]-=a[i];
		a[1]%=Mod;
		
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
