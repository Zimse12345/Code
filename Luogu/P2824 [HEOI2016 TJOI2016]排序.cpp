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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,val[N],a[N],q,op[N],opl[N],opr[N]; 
int sum[N<<2],len[N<<2],tag[N<<2];

int build(int L,int R,int id){
	len[id]=R-L+1,tag[id]=-1;
	return sum[id]=L==R?a[L]:build(L,(L+R)/2,id<<1)+build((L+R)/2+1,R,(id<<1)|1);
}

void pushdown(int id){
	if(tag[id]!=-1){
		if(tag[id]==0)sum[id]=0;
		else sum[id]=len[id];
		if(len[id]>1)tag[id<<1]=tag[(id<<1)|1]=tag[id];
		tag[id]=-1;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){//printf("(%d %d %d %d %d %d)\n",L,R,id,l,r,x);
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		else pushdown((id<<1)|1);
		sum[id]=sum[id<<1]+sum[(id<<1)|1];
	}
	return;
}

int query(int L,int R,int id,int l,int r){//printf("(%d %d %d %d %d)\n",L,R,id,l,r);
	pushdown(id);
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

bool check(int x){
	for(int i=1;i<=n;i++)a[i]=(val[i]>=x)?1:0;
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int s1=query(1,n,1,opl[i],opr[i]),s0=opr[i]-opl[i]+1-s1,x1=1,x0=0;//printf("(%d %d %d)\n",i,s1,s0);
		if(op[i]==0)T=s1,s1=s0,s0=T,x1=0,x0=1;
		if(s1>0)update(1,n,1,opl[i],opl[i]+s1-1,x1);//printf("update([%d,%d]:%d)\n",opl[i],opl[i]+s1-1,x1);
		if(s0>0)update(1,n,1,opl[i]+s1,opr[i],x0);//printf("update([%d,%d]:%d)\n",opl[i]+s1,opr[i],x0);
	}
	return query(1,n,1,q,q);
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<=m;i++)op[i]=read(),opl[i]=read(),opr[i]=read();
	q=read();
	int L=1,R=n,ans=0;
	while(L<=R){
		int M=(L+R)>>1;//printf("[%d %d %d]",L,R,M);
		if(check(M))ans=M,L=M+1;//printf("*");
		else R=M-1;
		//printf("\n");
	}
	printf("%d\n",ans);
	return 0;
}
