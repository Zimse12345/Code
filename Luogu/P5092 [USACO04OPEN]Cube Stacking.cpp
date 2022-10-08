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
int n,q,fa[N],w[N],cnt[N];
char op;

int F(int x){
	if(fa[x]!=x){
		int Fa=F(fa[x]);
		w[x]+=w[fa[x]];
		fa[x]=Fa;
	}
	return fa[x];
}

int main(){
	n=30000,q=read();
	int x,y;
	for(int i=1;i<=n;i++)fa[i]=i,w[i]=0,cnt[i]=1;
	while(q--){
		cin>>op;
		if(op=='M'){
			x=read(),y=read();
			int A=F(x),B=F(y);
			if(A==B)continue;
			fa[A]=B,w[A]=cnt[B],cnt[B]+=cnt[A];
		}
		else{
			x=read(),F(x);
			printf("%d\n",w[x]);
		}
	}
	return 0;
}

