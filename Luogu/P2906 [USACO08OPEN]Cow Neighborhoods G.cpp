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

const int N=2e5+7,Mod=998244353,INF=5e12+7;
int n,c,g,fa[N],cnt[N],ans=1;
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}
struct node{int x,y,id;node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
bool operator < (const node& A)const{if(x==A.x)return y<A.y;return x<A.x;}}p[N];
set<node> s;

inline void link(int x,int y){
	x=F(x),y=F(y);
	if(x==y)return;
	if(cnt[x]<cnt[y])swap(x,y);
	fa[y]=x,cnt[x]+=cnt[y],ans=max(ans,cnt[x]),--g;
	return;
}

signed main(){
	n=g=read(),c=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=node(x+y,x-y,i),fa[i]=i,cnt[i]=1;
	sort(p+1,p+n+1);
	s.insert(node(-INF,0,0)),s.insert(node(INF,0,0));
	for(int i=1,j=1;i<=n;i++){
		if(i==1){
			s.insert(node(p[i].y,p[i].id,0));
			continue;
		}
		while(p[i].x-p[j].x>c)s.erase(node(p[j].y,p[j].id,0)),++j;
		set<node>::iterator it=s.lower_bound(node(p[i].y,0,0));
		if(abs(it->x-p[i].y)<=c)link(it->y,p[i].id);
		--it;
		if(abs(it->x-p[i].y)<=c)link(it->y,p[i].id);
		s.insert(node(p[i].y,p[i].id,0));
	}
	printf("%lld %lld\n",g,ans);
	return 0;
}

