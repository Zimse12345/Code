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
#include <cctype>

#define int unsigned
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

const int MB=1<<21;
struct FastIO{
	char buf[MB+100],*p,*e;
	int getChar(){
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x){
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int N=2e7+7,Mod=998244353,INF=1e9+7;
int n,k,a[N];
int ch[N][2],sz[N],rt[N],tot;
long long ans;

struct node{
	int x,y,t;
	node(int x=0,int y=0,int t=0):x(x),y(y),t(t){};
	inline bool operator < (const node& A)const{return t<A.t;}
};
priority_queue<node> q;

inline void init(){
	rt[0]=++tot,sz[tot]=1;
	int id=tot;
	for(int i=31ull;i<=32ull;i--)Lid=++tot,id=tot,sz[id]=1;
	return;
}

inline int sol(int x,int id,int k){
	int res=0;
	for(int j=31ull;j<=32ull;j--){
		int t=((1ull<<j)&x)?1:0,v=sz[ch[id][t^1]];
		if(v>=k)id=ch[id][t^1],res|=(1ull<<j);
		else k-=v,id=ch[id][t];
	}
	return res;
}

signed main(){
	IO>>n>>k;
	init();
	for(int i=1,x;i<=n;i++){
		IO>>x;
		x=a[i]=a[i-1]^x;
		rt[i]=++tot,sz[tot]=sz[rt[i-1]]+1;
		int id=tot,pid=rt[i-1];
		for(int j=31ull;j<=32ull;j--){
			if((1ull<<j)&x){
				Rid=++tot,sz[Rid]=sz[ch[pid][1]]+1;
				Lid=ch[pid][0],id=Rid,pid=ch[pid][1];
			}
			else{
				Lid=++tot,sz[Lid]=sz[ch[pid][0]]+1;
				Rid=ch[pid][1],id=Lid,pid=ch[pid][0];
			}
		}
		q.push(node(i,1,sol(a[i],rt[i-1],1)));
	}
	
	while(k--){
		node p=q.top();
		q.pop(),ans+=p.t;
		if(p.t==p.x)continue;
		else q.push(node(p.x,p.y+1,sol(a[p.x],rt[p.x-1],p.y+1)));
	}
	printf("%lld\n",ans);
	return 0;
}

