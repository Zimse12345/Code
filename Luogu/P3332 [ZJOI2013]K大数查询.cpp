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
#define Lid Ch[id][0]
#define Rid Ch[id][1]
#define lid ch[id][0]
#define rid ch[id][1]

using namespace std;

ll read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=12000000+7,Mod=998244353,INF=1e9+7;
int n,m,cnt=1,siz,Rt[N/2];
int Ch[N/2][2],tag[N*2],ch[N*2][2];
ll sum[N*2];

struct segmenttree{
	void pushdown(int id,int L,int R){
		if(tag[id]){
			sum[id]+=1ll*tag[id]*(R-L+1);
			if(L!=R){
				if(!lid)lid=++siz;
				if(!rid)rid=++siz;
				tag[lid]+=tag[id],tag[rid]+=tag[id];
			}
			tag[id]=0;
		}
		return;
	}
	
	void update(int L,int R,int id,int l,int r){
		pushdown(id,L,R);
		if(l<=L&&r>=R)tag[id]++,pushdown(id,L,R);
		else{
			int M=(L+R)>>1;
			if(l<=M){
				if(!lid)lid=++siz;
				update(L,M,lid,l,r);
			}
			else if(lid&&tag[lid])pushdown(lid,L,M);
			if(r>M){
				if(!rid)rid=++siz;
				update(M+1,R,rid,l,r);
			}
			else if(rid&&tag[rid])pushdown(rid,M+1,R);
			sum[id]=sum[lid]+sum[rid];
		}
		return;
	}
	
	ll query(int L,int R,int id,int l,int r){
		pushdown(id,L,R);
		if(l<=L&&r>=R)return sum[id];
		else{
			int M=(L+R)>>1;ll res=0;
			if(l<=M)res+=query(L,M,lid,l,r);
			if(r>M)res+=query(M+1,R,rid,l,r);
			return res;
		}
	}
}node[N];

void update(int L,int R,int id,int l,int r,int c){
	if(c<L||c>R)return;
	if(!Rt[id])Rt[id]=++siz;
	node[id].update(1,n,Rt[id],l,r);
	if(L!=R){
		int M=(L+R)>>1;
		if(!Lid)Lid=++cnt;
		if(!Rid)Rid=++cnt;
		if(c<=M)update(L,M,Lid,l,r,c);
		else update(M+1,R,Rid,l,r,c);
	}
	return;
}

ll query(int L,int R,int id,int l,int r,int c){
	if(c<=L){
		if(Rt[id])return node[id].query(1,n,Rt[id],l,r);
		return 0;
	}
	if(c>R)return 0;
	int M=(L+R)>>1;
	if(!Lid)Lid=++cnt;
	if(!Rid)Rid=++cnt;
	return query(L,M,Lid,l,r,c)+query(M+1,R,Rid,l,r,c);
}

int main(){
//	freopen("t.in","r",stdin);
	n=read(),m=read();
	ll c,p=0;
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read(),c=read();
		if(op==1)update(-n,n,1,l,r,c),p+=r-l+1;
		else{
			int L=-n,R=n,ans=-n;
			while(L<=R){
				int M=(L+R)>>1;
				ll q=query(-n,n,1,l,r,M);
				if(q>=c)ans=M,L=M+1;
				else R=M-1;
			}
			printf("%d\n",ans);
		}
//		printf("%d %d %d\n",i,cnt,siz);
	}
	return 0;
}
