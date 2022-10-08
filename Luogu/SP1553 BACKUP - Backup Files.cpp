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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,k,a[N],L[N],R[N],ans,vis[N];
struct node{
	int v,id;
	node(int v=0,int id=0):v(v),id(id){}
	bool operator < (const node& A)const{return v>A.v;}
};
priority_queue<node> q;

signed main(){T=read();while(T--){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],L[i]=i-1,R[i]=i+1,q.push(node(a[i],i));
	a[0]=a[n]=INF;
	while(k){
		node x=q.top();q.pop();
		if(vis[x.id])continue;
		ans+=x.v,--k;
		vis[L[x.id]]=1;
		vis[R[x.id]]=1;
		x.v=a[x.id]=a[L[x.id]]+a[R[x.id]]-a[x.id];
		q.push(x);
		L[x.id]=L[L[x.id]],R[x.id]=R[R[x.id]];
		R[L[x.id]]=x.id;
		L[R[x.id]]=x.id;
	}
	printf("%d\n",ans);
	while(!q.empty())q.pop();
	ans=0;
	for(int i=0;i<=n+1;i++)L[i]=R[i]=0,a[i]=0,vis[i]=0;
	}
	return 0;
}

