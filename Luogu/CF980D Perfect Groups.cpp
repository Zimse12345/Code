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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],fa[N],ans[N],t[N],c;
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)if(a[i]*a[j]>0){
			int x=sqrt(a[i]*a[j]);
			if((x-1)*(x-1)==a[i]*a[j]||x*x==a[i]*a[j]||(x+1)*(x+1)==a[i]*a[j]){
				int A=F(i),B=F(j);
				if(A==B)continue;
				fa[A]=B;
			}
		}
	}
	for(int i=1;i<=n;i++)F(i);
	for(int i=1;i<=n;i++){
		c=0;
		for(int j=i;j<=n;j++){
			if((!t[fa[j]])&&a[j])++c;
			if(a[j]==0&&c==0)++ans[1];
			else ++t[fa[j]],++ans[c];
		}
		for(int j=i;j<=n;j++)--t[fa[j]];
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}

