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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,n1,n2,n3,s,ans,vis[N],aa[N],bb[N],cc[N];
struct node{
	int x,y,id;
	node(int x=0,int y=0,int id=0):x(x),y(y),id(id){} 
}a[N];
struct nd{
	int v,id;
	nd(int v=0,int id=0):v(v),id(id){}
	bool operator < (const nd& A)const{return v<A.v;}
};
bool cmp_x(const node& A,const node& B){return A.x>B.x;}
bool cmp_y(const node& A,const node& B){return A.y>B.y;}
priority_queue<nd> q1,q2,q3;

signed main(){
	n1=read(),n2=read(),n3=read(),n=n1+n2+n3;
	for(int i=1;i<=n;i++){
		aa[i]=read(),bb[i]=read(),cc[i]=read();
		aa[i]-=cc[i],bb[i]-=cc[i],ans+=cc[i];
		a[i]=node(aa[i],bb[i],i);
	}
	sort(a+1,a+n+1,cmp_x);
	for(int i=1;i<=n;i++){
		if(i<=n1)q1.push(nd(a[i].y-a[i].x,a[i].id)),ans+=a[i].x,vis[a[i].id]=1;
		else q2.push(nd(a[i].y,a[i].id)),q3.push(nd(a[i].x,a[i].id));
	}
	for(int i=1;i<=n2;i++){
		while(q3.size()&&vis[q3.top().id])q3.pop();
		while(q2.size()&&vis[q2.top().id])q2.pop();
		if(q2.empty()||(q1.size()&&q3.size()&&q1.top().v+q3.top().v>q2.top().v)){
			int b1=q1.top().id,b2=q3.top().id;
			vis[b1]=2,vis[b2]=1;
			ans+=q1.top().v+q3.top().v,q1.pop(),q3.pop(),q1.push(nd(bb[b2]-aa[b2],b2));
		}
		else vis[q2.top().id]=2,ans+=q2.top().v,q2.pop();
	}
	printf("%lld\n",ans);
	return 0;
}

