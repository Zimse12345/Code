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

const int N=3e5+7,Mod=1e9+9,INF=1e9+7;
int n,m,a[N],fib[N],sf[N],fa[N],fb[N];
int sum[N<<2],tag1[N<<2],tag2[N<<2],LL[N<<2],RR[N<<2];

int build(int L,int R,int id){
	LL[id]=L,RR[id]=R;
	return sum[id]=(L==R)?a[L]:(build(L,(L+R)/2,id<<1)+build((L+R)/2+1,R,(id<<1)|1))%Mod;
}

void pushdown(int id){
	if(tag1[id]){
		int len=RR[id]-LL[id]+1,L=tag1[id],R=tag2[id],Lid=id<<1,Rid=(id<<1)|1;
		sum[id]=(sum[id]+L+sf[max(0ll,len-2)]*L)%Mod;
		sum[id]=(sum[id]+sf[max(0ll,len-1)]*R)%Mod;
		if(len>1){
			tag1[Lid]+=L,tag2[Lid]+=R,tag1[Lid]%=Mod,tag2[Lid]%=Mod;
			int p=(LL[id]+RR[id])/2+2-LL[id];
			tag1[Rid]+=fa[p]*L+fb[p]*R,tag1[Rid]%=Mod;
			tag2[Rid]+=fa[p+1]*L+fb[p+1]*R,tag2[Rid]%=Mod;
		}
		tag1[id]=tag2[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag1[id]=fib[x],tag2[id]=fib[x+1],pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		else pushdown(id<<1);
		if(l>M)update(M+1,R,(id<<1)|1,l,r,x);
		else if(l<=M&&r>M)update(M+1,R,(id<<1)|1,l,r,x+(M-max(L,l)+1));
		else pushdown((id<<1)|1);
		sum[id]=(sum[id<<1]+sum[(id<<1)|1])%Mod;
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res%Mod;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	fib[1]=fib[2]=1,sf[1]=1,sf[2]=2;
	for(int i=3;i<N;i++)fib[i]=(fib[i-2]+fib[i-1])%Mod,sf[i]=(sf[i-1]+fib[i])%Mod;
	for(int i=3;i<N;i++)fa[i]=fib[i-2],fb[i]=fib[i-1];
	fa[1]=1,fb[2]=1;
	build(1,n,1);
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==1)update(1,n,1,l,r,1);
		else printf("%lld\n",query(1,n,1,l,r));
	}
	return 0;
}
