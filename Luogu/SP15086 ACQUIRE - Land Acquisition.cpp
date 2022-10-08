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

const int N=2e5+7,Mod=998244353;
const int INF=1e12;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}a[N];
struct Line{double k,b;Line(double k=0,double b=0):k(k),b(b){}}s[N];
inline double f(int id,double x){return s[id].k*x+s[id].b;}
int n,_n,dp[N],lc;
int rt,ch[N][2],p[N],tot;

void upt(int L,int R,int& id,int x){
	if(!id)id=++tot,u=x;
	else if(f(x,L)<f(u,L)&&f(x,R)<f(u,R))u=x;
	else if(L==R||(f(x,L)>f(u,L)&&f(x,R)>f(u,R)))return;
	else{
		if(f(x,M)<f(u,M))swap(x,u);
		if(f(u,L)<f(x,L))upt(M+1,R,Rid,x);
		else upt(L,M,Lid,x);
	}
	return;
}

double query(int L,int R,int id,int x){
	return id?min(f(u,x),x<=M?query(L,M,Lid,x):query(M+1,R,Rid,x)):INF;
}

void addline(double k,double b){
	s[++lc]=Line(k,b),upt(0ll,INF,rt,lc);
	return;
}

signed main(){
	s[0].b=INF;
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),a[i]=node(x,y);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(_n&&a[_n].y<=a[i].y)--_n;
		a[++_n]=a[i];
	}
	n=_n;
	for(int i=1;i<=n;i++){
		addline(a[i].y,dp[i-1]);
		dp[i]=query(0ll,INF,rt,a[i].x);
	}
	printf("%lld\n",dp[n]);
	return 0;
}

