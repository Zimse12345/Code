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
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],c[N],ec,x[N],ch[N*10][2],tot=1,ans;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}

void dfs(int u,int k,int from){
	x[u]=k;
	for(int i=hd[u];i;i=nxt[i])if(to[i]!=from)dfs(to[i],k^c[i],u);
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs(1,0,0);
	int _id=1;
	for(int j=30;j>=0;j--)ch[_id][0]=++tot,_id=tot;
	for(int i=1,res,id;i<=n;i++){
		res=0,id=1;
		for(int j=30;j>=0;j--){
			if(x[i]&(1<<j)){
				if(Lid)id=Lid,res|=(1<<j);
				else id=Rid;
			}
			else{
				if(Rid)id=Rid,res|=(1<<j);
				else id=Lid;
			}
		}
		ans=max(ans,res);
		id=1;
		for(int j=30;j>=0;j--){
			if(x[i]&(1<<j)){
				if(!Rid)Rid=++tot;
				id=Rid;
			}
			else{
				if(!Lid)Lid=++tot;
				id=Lid;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

