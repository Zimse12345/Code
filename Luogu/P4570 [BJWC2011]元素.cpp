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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,ans,d[N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y>A.y;}
}p[N];

bool check(int x){
	for(int i=62;i>=0;i--){
		if(x&(1ll<<i)){
			if(!d[i]){
				d[i]=x;
				return true;
			}
			x^=d[i];
		}
	}
	return false;
}

signed main(){
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=node(x,y);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)if(check(p[i].x))ans+=p[i].y;
	printf("%lld\n",ans);
	return 0;
}

