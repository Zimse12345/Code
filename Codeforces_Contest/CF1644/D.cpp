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

const int N=2e5+7,Mod=998244353,INF=1e9;
int T,n,m,k,q,x[N],y[N];
int visx[N],visy[N],cx,cy,c;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read(),q=read();
		for(int i=1;i<=q;i++)x[i]=read(),y[i]=read();
		for(int i=q;i>=1;i--){
			if((visx[x[i]]||cy==m)&&(visy[y[i]]||cx==n))continue;
			++c;
			if(!visx[x[i]])++cx;
			if(!visy[y[i]])++cy;
			visx[x[i]]=visy[y[i]]=1;
		}
		printf("%lld\n",qp(k,c));
		for(int i=1;i<=q;i++)visx[x[i]]=0,visy[y[i]]=0;
		cx=cy=c=0;
	}
	return 0;
}

