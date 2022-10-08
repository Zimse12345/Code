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

const int N=4e5+7,Mod=998244353,INF=100000000000000000ll;
int n,a[N],x,ans;
struct line{
	int l,r,id;
	line(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const line& A)const{return l<A.l;}
}p[N*30];
int m,pre[N];
priority_queue<int,vector<int>,greater<int> > q1,q2; 

signed main(){
	int mi=INF,mx=-INF;
	n=read(),x=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		mi=min(mi,a[i]),mx=max(mx,a[i]);
		int A=1;
		while(a[i]<=1000000000000000000ll){
			p[++m]=line(a[i],a[i]+(A-1)*x,i);
			a[i]*=2,A*=2;
			A=min(A,1000000000000000000ll/x+1);
		}
	}
	ans=mx-mi;
	sort(p+1,p+m+1);
	for(int i=1;i<=n;i++)pre[i]=-INF,q1.push(pre[i]);
	for(int i=1;i<=m;i++){
		int t=p[i].l;
		q2.push(pre[p[i].id]);
		pre[p[i].id]=p[i].r;
		q1.push(pre[p[i].id]);
		while(!q2.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();
		ans=min(ans,max(t-q1.top(),0ll));
	}
	printf("%lld\n",ans);
	return 0;
}

