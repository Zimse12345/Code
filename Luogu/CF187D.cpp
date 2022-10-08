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
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e12+7;
int n,m,G,R,d[N],X[N],f[N],Q,rt=1;
signed ch[N*8][2],tot=1,val[N*8];

void pushdown(int id,int len){
	if(val[id]&&len>1){
		if(!Lid)Lid=++tot;
		if(!Rid)Rid=++tot;
		val[Lid]=val[Rid]=val[id],val[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id,R-L+1);
	if(l<=L&&r>=R)val[id]=x,pushdown(id,R-L+1);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,Lid,l,r,x);
		if(r>M)update(M+1,R,Rid,l,r,x);
	}
	return;
}

int query(int L,int R,int id,int x){
	pushdown(id,R-L+1);
	if(L==R)return val[id];
	int M=(L+R)>>1;
	if(x<=M)return query(L,M,Lid,x);
	else return query(M+1,R,Rid,x);
}

int Query(int t){
	int p=query(0,m-1,rt,t%m);
	int ans=t+X[p]+f[p];
	if(p<=n)ans+=m-(X[p]+t)%m;
	return ans;
}

signed main(){
	n=read(),G=read(),R=read(),m=G+R;
	for(int i=1;i<=n+1;i++)d[i]=read(),X[i]=X[i-1]+d[i];
	update(0,m-1,rt,0,m-1,n+1);
	for(int i=n,p=0;i>=1;i--){
		p=m-X[i]%m,f[i]=Query(p)-X[i]-p,p=X[i]%m;
		if(p<=G)update(0,m-1,rt,G-p,m-1-p,i);
		else update(0,m-1,rt,0,m-1-p,i),update(0,m-1,rt,m-p+G,m-1,i);
	}
	Q=read();
	for(int i=1;i<=Q;i++)printf("%lld\n",Query(read()));
	return 0;
}
