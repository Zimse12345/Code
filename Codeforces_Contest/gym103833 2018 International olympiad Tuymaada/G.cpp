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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],b[N],ca[N],cb[N],ans;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{if(x==_.x)return y<_.y;return x<_.x;}
};
node p[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),++ca[a[i]];
	for(int i=1;i<=n;i++)b[i]=read(),++cb[b[i]],p[i]=node(a[i],b[i]);
	for(int i=1;i<=m;i++)ans-=ca[i]*(ca[i]-1)/2+cb[i]*(cb[i]-1)/2;
	ans+=n*(n-1)/2;
	sort(p+1,p+n+1);
	for(int l=1,r;l<=n;){
		r=l;
		while(r<n&&p[r+1].x==p[r].x&&p[r+1].y==p[r].y)++r;
		int len=r-l+1;
		ans+=len*(len-1);
		l=r+1;
	}
	printf("%lld\n",ans);
	return 0;
}

