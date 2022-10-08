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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
const double ESP=1e-2;
int n,a[N],Lmx[N],Rmx[N],st[N],_l,_r,ans[N];
double calc(int t,int x){return sqrt(double(x)-double(t))+double(a[t]);}

double find(int a,int b){
	double L=a,R=n,res=n+1;
	while(R-L>ESP){
		double M=(L+R)/2;
		if(calc(a,M)<calc(b,M))R=M,res=M;
		else L=M;
	}
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	st[1]=1,_l=_r=1;
	for(int i=2;i<=n;i++){
		while(_l<_r&&calc(st[_l],i)<calc(st[_l+1],i))++_l;
		Lmx[i]=a[st[_l]]+signed(ceil(sqrt(double(i)-double(st[_l]))));
		if(calc(i,n)<calc(st[_r],n))continue;
		while(_l<_r&&find(st[_r-1],i)<find(st[_r-1],st[_r]))--_r;
		st[++_r]=i;
	}
	reverse(a+1,a+n+1);
	st[1]=1,_l=_r=1;
	for(int i=2;i<=n;i++){
		while(_l<_r&&calc(st[_l],i)<calc(st[_l+1],i))++_l;
		Rmx[n-i+1]=a[st[_l]]+ceil(sqrt(double(i)-double(st[_l])));
		if(calc(i,n)<calc(st[_r],n))continue;
		while(_l<_r&&find(st[_r-1],i)<find(st[_r-1],st[_r]))--_r;
		st[++_r]=i;
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans[i]=max(0ll,max(Lmx[i],Rmx[i])-a[i]),printf("%lld\n",ans[i]);
	return 0;
}
