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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,t,m,a[N];

int main(){
	n=read(),t=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1,l,r,ans;i<=m;i++){
		l=read(),r=read(),ans=0;
		for(int x=l;x<=r;x++)for(int y=x+1;y<=r;y++)if((a[x]^a[y])<=t)++ans;
		printf("%d\n",ans);
	}
	return 0;
}
