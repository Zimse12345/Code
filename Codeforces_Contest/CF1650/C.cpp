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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,t;
struct node{int x,y,id;node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
bool operator < (const node& A)const{if(t)return x<A.x;return y<A.y;}}p[N];

signed main(){
	T=read();
	while(T--){
		m=read(),n=read();
		for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=node(x,y,i);
		t=0,sort(p+1,p+n+1);
		int w=0;
		for(int i=1;i<=m*2;i++)w+=p[i].y;
		t=1,sort(p+1,p+m*2+1);
		printf("%d\n",w);
		for(int i=1;i<=m;i++)printf("%d %d\n",p[i].id,p[m*2-i+1].id);
	}
	return 0;
}

