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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int T,n,m,dfn[N],low[N],st[N],ins[N],top,ct,cl[N],col;
vector<int> g[N];
char A[10],B[10];

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++top]=u,ins[u]=1;
	for(unsigned i=0,v;i<g[u].size();i++){
		v=g[u][i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]>=dfn[u]){
		++col;
		while(st[top]!=u)cl[st[top]]=col,ins[st[top]]=0,--top;
		cl[u]=col,ins[u]=0,--top;
	}
	return;
}

int main(){
	T=read();
	while(T--){
		n=read(),m=read(),top=ct=col=0;
		for(int i=1;i<=n*2;i++)g[i].resize(0),dfn[i]=low[i]=ins[i]=cl[i]=0;
		for(int i=1,a,b,fa,fb,la,lb;i<=m;i++){
			scanf("%s %s",A+1,B+1),la=strlen(A+1),lb=strlen(B+1),a=0,b=0;
			for(int j=2;j<=la;j++)a=a*10+A[j]-'0';
			for(int j=2;j<=lb;j++)b=b*10+B[j]-'0';
			fa=a+n,fb=b+n;
			if(A[1]=='h')fa=a,a+=n;
			if(B[1]=='h')fb=b,b+=n;
			g[fa].push_back(b),g[fb].push_back(a);
		}
		for(int i=1;i<=n*2;i++)if(!dfn[i])tarjan(i);
		int tag=1;
		for(int i=1;i<=n;i++)if(cl[i]==cl[i+n]){
			tag=0;
			break;
		}
		if(tag)printf("GOOD\n");
		else printf("BAD\n");
	}
	return 0;
}
