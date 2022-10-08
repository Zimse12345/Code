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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,fa[N],cnt[N],q,s[N],t;

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	for(int i=1,p=0,u,v;i<=m;i++){
		u=read(),v=read();
		int A=F(u),B=F(v);
		if(A!=B)fa[A]=B,cnt[B]+=cnt[A],cnt[A]=0,++p;
		
		t=0;
		for(int j=1;j<=n;j++)if(cnt[j])s[++t]=cnt[j];
		sort(s+1,s+t+1);
		int rm=i-p,ans=0;
		for(int j=t;j>=max(1,t-rm);j--)ans+=s[j];
		printf("%d\n",ans-1);
	}
	return 0;
}

