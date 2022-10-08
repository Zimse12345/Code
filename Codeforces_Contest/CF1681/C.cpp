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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,s[N],a[N],b[N];
int ax[N],ay[N],cnt;
struct node{
	int x,y,pos;
	node(int x=0,int y=0,int pos=0):x(x),y(y),pos(pos){};
	bool operator < (const node& A)const{
		return x==A.x?y<A.y:x<A.x;
	}
}p[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)p[i].x=read(),a[i]=p[i].x;
		for(int i=1;i<=n;i++)p[i].y=read(),p[i].pos=i,s[i]=i,b[i]=p[i].y;
		sort(p+1,p+n+1);
		int tag=1;
		for(int i=2;i<=n;i++)if(p[i].y<p[i-1].y)tag=0;
		if(!tag){
			printf("-1\n");
			continue;
		}
		cnt=0;
		for(int i=1;i<=n;i++)if(a[i]!=p[i].x||b[i]!=p[i].y){
			int t=0;
			for(int j=i+1;j<=n;j++)if(a[j]==p[i].x&&b[j]==p[i].y){t=j;break;}
			++cnt,ax[cnt]=t,ay[cnt]=i;
			swap(a[t],a[i]),swap(b[t],b[i]);
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d %d\n",ax[i],ay[i]);
	}
	return 0;
}

