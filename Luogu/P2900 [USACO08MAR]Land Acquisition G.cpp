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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,_n,que[N],l=1,r=0;
double dp[N];
struct node{double x,y;node(double x=0,double y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}p[N];
inline double X(int i){return -p[i].y;}
inline double Y(int i){return dp[i-1];}

signed main(){
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=node(x,y);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		while(_n&&p[_n].y<=p[i].y)--_n;
		p[++_n]=p[i];
	}
	n=_n;
	for(int i=1;i<=n;i++){
		while(l<r&&(Y(i)-Y(que[r]))/(X(i)-X(que[r]))<=(Y(que[r])-Y(que[r-1]))/(X(que[r])-X(que[r-1])))--r;
		que[++r]=i;
		while(l<r&&p[i].x>=(Y(que[l+1])-Y(que[l]))/(X(que[l+1])-X(que[l])))++l;
		dp[i]=dp[que[l]-1]+p[i].x*p[que[l]].y;
	}
	printf("%.0lf\n",dp[n]);
	return 0;
}

