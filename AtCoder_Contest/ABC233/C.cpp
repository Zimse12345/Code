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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,x,sz[N],t[N],ans;
vector<int> a[N];

int check(){
	int rm=x;
	for(int i=1,y;i<=n;i++){
		y=a[i][t[i]];
		if(rm%y!=0)return 0;
		rm/=y;
	}
	if(rm!=1)return 0;
	return 1;
}

void dfs(int p){
	if(p==n)ans+=check();
	else for(int i=0;i<sz[p+1];i++)t[p+1]=i,dfs(p+1);
	return;
}

signed main(){
	n=read(),x=read();
	for(int i=1;i<=n;i++){
		sz[i]=read();
		for(int j=1;j<=sz[i];j++)a[i].push_back(read());
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}

