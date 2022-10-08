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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],f[N];
struct slp{
	int x,y;
	slp(int x=0,int y=0):x(x),y(y){};
	bool operator < (const slp A)const{return y*A.x<x*A.y;}
	bool operator <= (const slp A)const{return y*A.x<=x*A.y;}
}k[N];
struct line{
	slp l,r;
	line(slp l=slp(0,0),slp r=slp(0,0)):l(l),r(r){}
	bool operator < (const line& A)const{return r<A.r;}
}s[N];

signed main(){
	n=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read();
		s[i]=line(slp(x,y-1),slp(x-1,y));
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		int L=1,R=i-1,p=0;
		while(L<=R){
			int M=(L+R)>>1;
			if(s[M].r<=s[i].l)L=M+1,p=M;
			else R=M-1;
		}
		f[i]=max(f[p]+1,f[i-1]);
		k[i]=s[i].r;
	}
	printf("%lld\n",f[n]);
	return 0;
}
