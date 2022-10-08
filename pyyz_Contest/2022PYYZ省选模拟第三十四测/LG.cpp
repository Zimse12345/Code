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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],ans=1;
int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);
}

void dfs(int pos){
	if(pos==n+1){
		int g=a[1],l=a[1];
		for(int i=2;i<=n;i++)g=gcd(g,a[i]),l=lcm(l,a[i]);
		ans=(ans*qp(l,g))%Mod;
	}
	else{
		for(int i=1;i<=m;i++)a[pos]=i,dfs(pos+1);
	}
	return;
}

signed main(){
	n=read(),m=read();
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

