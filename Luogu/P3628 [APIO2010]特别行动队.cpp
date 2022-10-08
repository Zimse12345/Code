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
#define M ((L+R)>>1)
#define Lid ch[id][0] 
#define Rid ch[id][1]
#define u p[id]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353;
const int INF=1e15;
struct Line{double k,b;Line(double k=0,double b=0):k(k),b(b){}}s[N];
inline double f(int id,double x){return s[id].k*x+s[id].b;}
int n,_n,dp[N],lc,a[N],sum[N];
int rt,ch[N][2],p[N],tot;

void upt(int L,int R,int& id,int x){
	if(!id)id=++tot,u=x;
	else if(f(x,L)>f(u,L)&&f(x,R)>f(u,R))u=x;
	else if(L==R||(f(x,L)<f(u,L)&&f(x,R)<f(u,R)))return;
	else{
		if(f(x,M)>f(u,M))swap(x,u);
		if(f(u,L)>f(x,L))upt(M+1,R,Rid,x);
		else upt(L,M,Lid,x);
	}
	return;
}

double query(int L,int R,int id,int x){
	return id?max(f(u,x),x<=M?query(L,M,Lid,x):query(M+1,R,Rid,x)):-INF;
}

void addline(double k,double b){
	s[++lc]=Line(k,b),upt(0ll,INF,rt,lc);
	return;
}

signed main(){
	s[0].b=INF;
	n=read();
	int A=read(),B=read(),C=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		addline(-2*A*sum[i-1],dp[i-1]+A*sum[i-1]*sum[i-1]-B*sum[i-1]);
		dp[i]=query(0ll,INF,rt,sum[i]);
		dp[i]+=A*sum[i]*sum[i]+B*sum[i]+C;
	}
	printf("%lld\n",dp[n]);
	return 0;
}

