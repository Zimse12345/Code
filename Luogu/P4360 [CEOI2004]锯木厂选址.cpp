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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,w[N],d[N],sd[N],sw[N],sc[N],f[N];
int X[N],Y[N],L,R;
int ans=INF;
inline int cost(int l,int r){return sc[l]-sc[r+1]-(sw[l]-sw[r+1])*sd[r];}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)w[i]=read(),d[i]=read();
	for(int i=n;i>=1;i--){
		sd[i]=sd[i+1]+d[i];
		sw[i]=sw[i+1]+w[i];
		sc[i]=sc[i+1]+sd[i]*w[i];
	}
	for(int i=1;i<=n;i++)f[i]=sc[1]-sc[i+1]-(sw[1]-sw[i+1])*sd[i];
	
	X[1]=sw[2],Y[1]=f[1]+sc[2],L=R=1;
	for(int i=2;i<=n;i++){
		while(L<R&&double(sd[i])<double(Y[L]-Y[L+1])/double(X[L]-X[L+1]))++L;
		int b=Y[L]-sd[i]*X[L];
		ans=min(ans,b+sw[i+1]*sd[i]);
		int x=sw[i+1],y=f[i]+sc[i+1]; 
		while(L<R&&double(Y[R-1]-Y[R])/double(X[R-1]-X[R])<double(Y[R]-y)/double(X[R]-x))--R;
		X[++R]=x,Y[R]=y;
	}
	printf("%d\n",ans);
	return 0;
}

