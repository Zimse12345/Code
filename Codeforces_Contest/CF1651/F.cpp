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
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,sz[N],re[N],ans;
int ch[N*72][2],a[N*72],b[N*72],rt[N],tot,top;
struct node{int l,r,t,rm;node(int l=0,int r=0,int t=0,int rm=0):l(l),r(r),t(t),rm(rm){}}st[N];

inline void update1(int L,int R,int& id,int _id,int x,int y){
	if(!id)id=++tot,a[id]=a[_id],b[id]=b[_id];
	if(R<=y)a[id]+=x,Lid=ch[_id][0],Rid=ch[_id][1];
	else if(y<=M)update1(L,M,Lid,ch[_id][0],x,y),Rid=ch[_id][1];
	else update1(L,M,Lid,ch[_id][0],x,y),update1(M+1,R,Rid,ch[_id][1],x,y);
	return;
}

inline void update2(int L,int R,int& id,int _id,int x,int y){
	if(!id)id=++tot,a[id]=a[_id],b[id]=b[_id];
	if(L^R){
		if(x<=M){
			if(Lid==ch[_id][0])Lid=0;
			update2(L,M,Lid,ch[_id][0],x,y);
			if(!Rid)Rid=ch[_id][1];
		}
		else{
			if(Rid==ch[_id][1])Rid=0;
			update2(M+1,R,Rid,ch[_id][1],x,y);
			if(!Lid)Lid=ch[_id][0];
		}
		b[id]=b[Lid]+b[Rid];
	}
	else b[id]+=y;
	return;
}

inline int qsum(int L,int R,int id,int x){
	if(x<L)return 0;
	if(R<=x)return a[id]*x*((x==R)?1:0)+b[id];
	return qsum(L,M,Lid,x)+qsum(M+1,R,Rid,x)+a[id]*x;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		sz[i]=read(),re[i]=read();
		update1(0,1e9,rt[i],rt[i-1],re[i],sz[i]/re[i]);
		update2(0,1e9,rt[i],rt[i-1],sz[i]/re[i]+1,sz[i]);
	}
	q=read();
	st[++top]=node(1,n,-1e9);
	for(int i=1,t,h;i<=q;i++){
		t=read(),h=read();
		while(1){
			int _t=st[top].t,x=st[top].l,y=st[top].r,rm=st[top].rm;--top;
			int ct=min(t-_t,1000000000ll);
			int atk=qsum(0,1e9,rt[y-1],ct)-qsum(0,1e9,rt[x-1],ct)+min(sz[y],rm+re[y]*ct);
			if(atk<=h){
				h-=atk;
				if(!h)st[++top]=node(1,y,t,0);
			}
			else{
				int L=x,R=y-1;
				while(L<=R){
					atk=qsum(0,1e9,rt[M],ct)-qsum(0,1e9,rt[L-1],ct);
					if(atk<=h)h-=atk,L=M+1;
					else R=M-1;
				}
				if(L==y)st[++top]=node(1,y,t,min(sz[L],rm+re[L]*ct)-h);
				else st[++top]=node(L+1,y,_t,rm),st[++top]=node(1,L,t,min(sz[L],ct*re[L])-h);
				h=0;
			}
			if(!top||!h)break;
		}
		if(!top){
			ans+=h;
			st[++top]=node(1,n,t,0);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

