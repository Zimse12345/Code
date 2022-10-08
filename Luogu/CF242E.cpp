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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],len[N<<2];
struct seg{
	int sum[N<<2],tag[N<<2];
	int s;
	
	void pushdown(int id){
		if(tag[id]){
			sum[id]=len[id]-sum[id];
			if(len[id]>1)tag[id<<1]^=1,tag[(id<<1)|1]^=1;
			tag[id]=0;
		}
		return;
	}
	
	void build(int L,int R,int id){
		len[id]=R-L+1;
		if(L==R)sum[id]=(a[L]&s)?1:0;
		else{
			int M=(L+R)>>1;
			build(L,M,id<<1),build(M+1,R,(id<<1)|1);
			sum[id]=sum[id<<1]+sum[(id<<1)|1];
		}
		return;
	}
	
	void update(int L,int R,int id,int l,int r){
		pushdown(id);
		if(l<=L&&r>=R)tag[id]=1,pushdown(id);
		else{
			int M=(L+R)>>1;
			if(l<=M)update(L,M,id<<1,l,r);
			else pushdown(id<<1);
			if(r>M)update(M+1,R,(id<<1)|1,l,r);
			else pushdown((id<<1)|1);
			sum[id]=sum[id<<1]+sum[(id<<1)|1];
		}
		return;
	}
	
	int query(int L,int R,int id,int l,int r){
		pushdown(id);
		if(l<=L&&r>=R)return sum[id];
		int M=(L+R)>>1,res=0;
		if(l<=M)res+=query(L,M,id<<1,l,r);
		if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
		return res;
	}
}tree[25];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=21;i++)tree[i].s=1ll<<i,tree[i].build(1,n,1);
	
	m=read();
	for(int i=1,op,l,r,x;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==1){
			int ans=0;
			for(int i=0;i<=21;i++)ans+=tree[i].query(1,n,1,l,r)<<i;
			printf("%lld\n",ans);
		}
		if(op==2){
			x=read();
			for(int i=0;i<=21;i++)if(x&(1ll<<i))tree[i].update(1,n,1,l,r);
		}
	}
	return 0;
}
