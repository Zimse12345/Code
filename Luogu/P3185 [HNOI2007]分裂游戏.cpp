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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],sg[N],vis[N];

void sol(int SG){
	int I=0,J=0,K=0,tot=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j;k<=n;k++){
		if(!(SG^sg[n-i+1]^sg[n-j+1]^sg[n-k+1])){
			if(!tot)I=i-1,J=j-1,K=k-1;
			++tot;
		}
	}
	printf("%d %d %d\n%d\n",I,J,K,tot);
	return;
}

signed main(){
	T=read();
	for(int i=2;i<=22;i++){
		for(int a=1;a<i;a++)for(int b=a;b<i;b++)vis[sg[a]^sg[b]]=i;
		while(vis[sg[i]]==i)++sg[i];
	}
	while(T--){
		n=read();
		int SG=0;
		for(int i=n;i>=1;i--){
			a[i]=read();
			if(a[i]&1)SG^=sg[i];
		}
		if(!SG)printf("-1 -1 -1\n0\n");
		else sol(SG);
	}
	return 0;
}

