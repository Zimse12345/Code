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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,x,w[N],k,sw[N],vis[N],to[N],cnt[N],nxt[N][50];

int sum(int p,int x){
	if(p+x-1<n)return sw[p+x-1]-(p?sw[p-1]:0ll);
	x-=n-p;
	int res=sw[n-1]-(p?sw[p-1]:0ll);
	res+=sw[n-1]*(x/n),x%=n;
	return res+(x?sw[x-1]:0ll); 
}

void sol(int L){
	if(vis[L]++)return;
	int l=1,r=1000000000,p=0;
	while(l<=r){
		int mid=(l+r)/2;
		int s=sum(L,mid);
		if(s<x)p=mid,l=mid+1;
		else r=mid-1;
	}
	cnt[L]=p+1,to[L]=(L+p)%n;
	sol((to[L]+1)%n);
	return;
}

signed main(){
	n=read(),q=read(),x=read();
	for(int i=0;i<n;i++){
		w[i]=read();
		sw[i]=i?(sw[i-1]+w[i]):w[i];
	}
	sol(0);
	for(int i=0;i<n;i++)nxt[i][0]=to[i];
	for(int j=1;j<50;j++){
		for(int i=0;i<n;i++)nxt[i][j]=nxt[(nxt[i][j-1]+1)%n][j-1];
	}
	
	while(q--){
		int k=read(),p=0;
		for(int i=49;i>=0;i--)if(k>(1ll<<i))p=(nxt[p][i]+1)%n,k-=(1ll<<i);
		printf("%lld\n",cnt[p]);
	}
	return 0;
}

