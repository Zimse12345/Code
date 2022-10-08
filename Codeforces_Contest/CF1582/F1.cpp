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
int n,a[1000000],f[N][2],ans;

int main(){
	n=read();
	int p=0;
	for(int j=0;j<N;j++)f[j][0]=INF;
	f[0][0]=-1;
	for(int i=1;i<=n;i++){
		p^=1;
		for(int j=0;j<N;j++)f[j][p]=f[j][p^1];
		a[i]=read();
		for(int j=0;j<N;j++)if(f[j][p^1]<a[i])f[j^a[i]][p]=min(f[j^a[i]][p],a[i]);
	}
	for(int j=0;j<N;j++)if(f[j][p]<INF)++ans;
	printf("%d\n",ans);
	for(int j=0;j<N;j++)if(f[j][p]<INF)printf("%d ",j);
	printf("\n");
	return 0;
}

