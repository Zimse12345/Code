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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,k,L,R,a[N],s[N],mt[N][21],_2[N];
ll ans;

inline int RMQ(int l,int r){
	int len=r-l+1,p=_2[len],t1=mt[r][p],t2=mt[l+(1<<p)-1][p];
	return s[t1]>s[t2]?t1:t2;
}

struct node{
	int p,l,r,t;
	node(int p=0,int l=1,int r=1):p(p),l(l),r(r),t(RMQ(l,r)){};
	bool operator < (const node& A)const{return s[t]-s[p-1]<s[A.t]-s[A.p-1];}
}; 
priority_queue<node> q;

signed main(){
	n=read(),k=read(),L=read(),R=read();
	for(int i=1;i<=n;i++)a[i]=read();
	_2[0]=-1;
	for(int i=1;i<=n;i++)_2[i]=_2[i>>1]+1,s[i]=s[i-1]+a[i],mt[i][0]=i;
	for(int i=1;i<=19;i++){
		for(int j=(1<<i);j<=n;j++){
			int t1=mt[j-(1<<(i-1))][i-1],t2=mt[j][i-1];
			mt[j][i]=s[t1]>s[t2]?t1:t2;
		}
	}
	for(int i=1;i+L-1<=n;i++)q.push(node(i,i+L-1,min(i+R-1,n)));
	while(k--){
		node p=q.top();
		q.pop();
		ans+=s[p.t]-s[p.p-1];
		if(p.l!=p.t)q.push(node(p.p,p.l,p.t-1));
		if(p.r!=p.t)q.push(node(p.p,p.t+1,p.r));
	}
	printf("%lld\n",ans);
	return 0;
}

