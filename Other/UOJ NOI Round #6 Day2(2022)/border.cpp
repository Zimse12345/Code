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
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,SZ=26,INF=1e9+7;
int n,q,tot,pre,ans,f[N],edid[N];
int rt[N],ch[N*32][2],cnt,val[N],fa[N][21];
char s[N];

struct node{
	int to[SZ],len,link;
}t[N];
vector<int> g[N];

void ins(int& id,int L,int R,int x){
	if(!id)id=++cnt;
	if(L!=R){
		if(x<=M)ins(Lid,L,M,x);
		else ins(Rid,M+1,R,x);
	}
	return;
}

int merge(int id1,int id2){
	if(!id1||!id2)return id1+id2;
	int id=++cnt;
	Lid=merge(ch[id1][0],ch[id2][0]),Rid=merge(ch[id1][1],ch[id2][1]);
	return id;
}

int findpos(int id,int L,int R,int x){
	if(!id)return 0;
	if(L==R)return 1;
	if(x<=M)return findpos(Lid,L,M,x);
	return findpos(Rid,M+1,R,x);
}

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1,val[id]=1,edid[t[id].len]=id;
	ins(rt[id],1,n,t[id].len);
	while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
	if(p==-1)t[id].link=0;
	else{
		int q=t[p].to[c];
		if(t[q].len==t[p].len+1)t[id].link=q;
		else{
			int cp=++tot;
			t[cp]=t[q],t[cp].len=t[p].len+1;
			while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
			t[q].link=t[id].link=cp;
		}
	}
	pre=id;
	return;
}

void dfs(int u){
	for(unsigned i=0;i<g[u].size();i++)if(g[u][i]){
		dfs(g[u][i]),val[u]+=val[g[u][i]];
		rt[u]=merge(rt[u],rt[g[u][i]]);
	}
	return;
}

signed main(){
//	freopen("ex_border2.in","r",stdin);
//	freopen("border.out","w",stdout);
	
	t[0].link=-1;
	n=read(),q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)f[i]=read();
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)g[t[i].link].push_back(i),fa[i][0]=t[i].link;
	for(int i=1;i<=20;i++)for(int j=1;j<=tot;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs(0);
	while(q--){
		int l=read(),r=read(),pos=0;
		if(n>5000){
			ll ans=0;
			int p=edid[r];
			for(int i=20;i>=0;i--)if(fa[p][i]){
				if(t[fa[p][i]].len>=r-l+1)p=fa[p][i];
			}
			ans+=f[val[p]];
			for(int i=l;i<r&&i<l+32;i++){
				pos=t[pos].to[s[i]-'a'];
				if(findpos(rt[pos],1,n,r))ans+=f[val[pos]];
			}
			printf("%lld\n",ans);
			continue;
		}
		ll ans=0;
		for(int i=l;i<=r;i++){
			pos=t[pos].to[s[i]-'a'];
			if(findpos(rt[pos],1,n,r))ans+=f[val[pos]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

