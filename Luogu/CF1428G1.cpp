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

const int N=1000000,Mod=998244353,INF=1e9+7;
int k,p[20],f[N*2],q; 

signed main(){
	k=read(),k=(k-1)*3;
	for(int i=0;i<=5;i++)p[i]=read();
	for(int i=0,x,w;i<N;i++){
		x=i,w=0;
		while(x){
			if((x%10)%3==0)f[i]+=p[w]*((x%10)/3);
			x/=10,++w;
		}
	}
	for(int i=0,r,o=3;i<=5;i++,o*=10){
		r=k;
		for(int j=1,w,v;j<=r;j*=2){
			w=j*o,v=p[i]*j,r-=j;
			for(int t=N-1;t>=w;t--)f[t]=max(f[t],f[t-w]+v);
		}
		int w=o*r,v=p[i]*r;
		for(int t=N-1;t>=w;t--)f[t]=max(f[t],f[t-w]+v);
	}
	q=read();
	for(int i=1;i<=q;i++)printf("%lld\n",f[read()]);
	return 0;
}
