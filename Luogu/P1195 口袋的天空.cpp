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
int n,m,k,fa[N],cnt[N],ans;
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator <(const edge& A)const{return w<A.w;}
}e[N];

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

int main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),e[i]=edge(u,v,w);
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	if(n==k){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int A=F(u),B=F(v);
		if(A!=B){
			if(cnt[A]<cnt[B])fa[A]=B,cnt[B]+=cnt[A];
			else fa[B]=A,cnt[A]+=cnt[B];
			ans+=w,--n;
		}
		if(n==k){
			printf("%d\n",ans);
			return 0;
		}
	}
	printf("No Answer\n");
	return 0;
}
