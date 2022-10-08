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

const int N=2e5+7,H1=998244353,H2=19260817,INF=1e9+7;
int typ,n,q,hd[N],nxt[N],to[N],ec;
int f[N],g[N],c[N],ans,cnt;
char s[N];
set<int> S1,S2;
multiset<int> s1,s2;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y<A.y;}}p[N];

int qp(int x,int k,int H){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%H;
		x=(x*x)%H,k/=2;
	}
	return res;
}

void dfs2(int u,int from){
	f[u]=f[from]+1,p[u]=node(u,f[u]);
	for(int i=hd[u];i;i=nxt[i])if(to[i]!=from)dfs2(to[i],u);
	return; 
}

void sol(){
	S1.clear(),S2.clear();
	for(int i=1;i<=n;i++)if(c[i]){
		dfs2(i,0);
		sort(p+1,p+n+1);
		int h1=0,h2=0;
		for(int d=1,j=1;d<=n;d++)if(p[j].y==d){
			while(p[j].y==d)h1=h1+qp(H1,p[j].x,1e9+7),h2=h2+qp(H2,p[j].x,1e9+7),++j;
			S1.insert(h1),S2.insert(h2);
		}
	}
	printf("%llu\n",max(S1.size(),S2.size()));
	return;
}

signed main(){
//	freopen("brain.in","r",stdin);
//	freopen("my.out","w",stdout);
	typ=read();
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)c[i]=s[i]-'0';
	q=read();
	if(typ==4){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)if(c[i]){
			ans+=min(i-1,n-i);
			++cnt;
			s1.insert(-n+i*2-1);
			s2.insert(-n+(n-i+1)*2-1);
		}
		int Ans=ans+(cnt?1:0);
		if(!s1.empty()&&-(*s1.begin())>0)Ans-=(*s1.begin());
		if(!s2.empty()&&-(*s2.begin())>0)Ans-=(*s2.begin());
		printf("%d\n",Ans);
		while(q--){
			int x=read();
			if(c[x])ans-=min(x-1,n-x),--cnt,s1.erase(s1.find(-n+x*2-1)),s2.erase(s2.find(-n+(n-x+1)*2-1));
			else ans+=min(x-1,n-x),++cnt,s1.insert(-n+x*2-1),s2.insert(-n+(n-x+1)*2-1);
			c[x]^=1;
			Ans=ans+(cnt?1:0);
			if(!s1.empty()&&-(*s1.begin())>0)Ans-=(*s1.begin());
			if(!s2.empty()&&-(*s2.begin())>0)Ans-=(*s2.begin());
			printf("%d\n",Ans);
		}
		return 0;
	} 
	if(typ==5){
		int ans=0,tag=0;
		for(int i=2;i<=n;i++)if(c[i])++ans,++tag;
		tag+=c[1];
		printf("%d\n",ans+(tag?1:0)+tag);
		while(q--){
			int x=read();
			if(x!=1){
				if(c[x])--ans,--tag;
				else ++ans,++tag;
			}
			else{
				if(c[x])--tag;
				else ++tag;
			}
			c[x]^=1;
			printf("%d\n",ans+(tag?1:0)+tag);
		}
		return 0;
	}
	sol();
	while(q--){
		c[read()]^=1;
		sol();
	}
	return 0;
}

