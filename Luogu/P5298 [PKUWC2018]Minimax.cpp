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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9;
int inv10000;
int n,fa[N],p[N],sz[N],Val[N],Vt,vt;
int rt[N*16],ch[N*16][2],tot,sum[N*16],tag[N*16],ans;
vector<int> G[N];
map<int,int> Num;

inline int fpow(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=res*x%Mod;
		x=x*x%Mod,k/=2;
	}
	return res;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

void pushdown(int id){
	if(tag[id]){
		tag[Lid]=tag[Lid]*tag[id]%Mod,tag[Rid]=tag[Rid]*tag[id]%Mod;
		sum[id]=sum[id]*tag[id]%Mod,tag[id]=1;
	}
	return;
}

void mul(int L,int R,int id,int l,int r,int v){
	pushdown(id);
	if(!id||r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]=v;
	else{
		mul(L,M,Lid,l,r,v),mul(M+1,R,Rid,l,r,v);
		sum[id]=(sum[Lid]+sum[Rid])%Mod;
	}
	return;
}

void ins(int L,int R,int& id,int x,int y){
	pushdown(id);
	if(!id)id=++tot,tag[id]=1;
	sum[id]+=y;
	if(L==R)return;
	if(x<=M)ins(L,M,Lid,x,y);
	else ins(M+1,R,Rid,x,y);
	return;
}

int merge(int L,int R,int id1,int id2,int p1,int q1,int p2,int q2,int P){
	pushdown(id1),pushdown(id2);
	if(!id1){
		tag[id2]=1-(p1*(1-P)+q1*P)%Mod;
		pushdown(id2);
		return id2;
	}
	if(!id2){
		tag[id1]=1-(p2*(1-P)+q2*P)%Mod;
		pushdown(id1);
		return id1;
	}
	if(L==R){
		int A=1-(p1*(1-P)+q1*P)%Mod,B=1-(p2*(1-P)+q2*P)%Mod;
		sum[id1]=(A*sum[id2]+B*sum[id1])%Mod;
		return id1;
	}
	pushdown(ch[id1][0]),pushdown(ch[id1][1]),pushdown(ch[id2][0]),pushdown(ch[id2][1]);
	int s10=sum[ch[id1][0]],s11=sum[ch[id1][1]],s20=sum[ch[id2][0]],s21=sum[ch[id2][1]];
	int lc=merge(L,M,ch[id1][0],ch[id2][0],p1,(q1+s11)%Mod,p2,(q2+s21)%Mod,P);
	int rc=merge(M+1,R,ch[id1][1],ch[id2][1],(p1+s10)%Mod,q1,(p2+s20)%Mod,q2,P);
	ch[id1][0]=lc,ch[id1][1]=rc,sum[id1]=(sum[lc]+sum[rc])%Mod;
	return id1;
}

void solve(int u){
	if(!G[u].size()){
		sz[u]=1;
		ins(1,vt,rt[u],p[u],1);
		return;
	}
	for(unsigned i=0;i<G[u].size();i++){
		int v=G[u][i];
		solve(v);
		if(!i)rt[u]=rt[v];
		else rt[u]=merge(1,vt,rt[u],rt[v],0,0,0,0,p[u]);
		sz[u]+=sz[v];
	}
	return;
}

int rk=0;
void dfs(int L,int R,int id){
	pushdown(id);
	if(!id)return;
	if(L==R){
		++rk;
		ans=(ans+rk*Val[L]%Mod*sum[id]%Mod*sum[id]%Mod)%Mod;
	}
	else dfs(L,M,Lid),dfs(M+1,R,Rid);
	return;
}

signed main(){
	inv10000=inv(10000);
	n=read();
	for(int i=1;i<=n;i++)fa[i]=read(),G[fa[i]].push_back(i);
	for(int i=1;i<=n;i++){
		p[i]=read();
		if(!G[i].size())Val[++Vt]=p[i];
		else p[i]=p[i]*inv10000%Mod;
	}
	sort(Val+1,Val+Vt+1);
	for(int i=1;i<=Vt;i++)if(Val[i]!=Val[i-1])Val[++vt]=Val[i],Num[Val[i]]=vt;
	for(int i=1;i<=n;i++){
		if(!G[i].size())p[i]=Num[p[i]];
	}
	solve(1);
	dfs(1,vt,rt[1]);
	if(ans<0)ans+=Mod;
	printf("%lld\n",ans);
	return 0;
}

