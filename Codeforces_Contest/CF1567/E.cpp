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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],sum[N<<2],lm[N<<2],rm[N<<2];

void pushup(int id,int L,int R){
	if(L==R)return;
	int Lid=id<<1,Rid=(id<<1)|1,M=(L+R)>>1,len=R-L+1,llen=M-L+1,rlen=len-llen;
	sum[id]=sum[Lid]+sum[Rid];
	lm[id]=(lm[Lid]==llen&&a[M]<=a[M+1])?lm[Lid]+lm[Rid]:lm[Lid];
	rm[id]=(rm[Rid]==rlen&&a[M]<=a[M+1])?rm[Rid]+rm[Lid]:rm[Rid];
	if(a[M]<=a[M+1])sum[id]+=(rm[Lid]*lm[Rid]);
	return;
}

void build(int L,int R,int id){
	if(L==R)sum[id]=lm[id]=rm[id]=1;
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id,L,R);
	}
//	printf("[%lld %lld %lld]\n",L,R,sum[id]);
	return;
}

int query(int L,int R,int id,int l,int r){
	if(L>=l&&R<=r){
		//printf("[%lld %lld %lld]\n",L,R,sum[id]);
		return sum[id];
	}
	int res=0,M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);//printf("(%lld)",res);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);//printf("(%lld)",res);
	if(l<=M&&r>M){
		int LL=max(l,M-rm[id<<1]+1),RR=min(r,M+lm[(id<<1)|1]);
		LL=M-LL+1,RR=RR-M;
		if(a[M]<=a[M+1])res+=LL*RR;
	}
	
	//printf("[%lld %lld %lld]\n",L,R,res);
	return res; 
}

void chg(int L,int R,int id,int x,int y){
	if(L==R)a[x]=y;
	else{
		int M=(L+R)>>1;
		if(x<=M)chg(L,M,id<<1,x,y);
		else chg(M+1,R,(id<<1)|1,x,y);
		pushup(id,L,R);
	}
	return;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	while(q--){
		int ty=read(),x=read(),y=read();
		if(ty==1)chg(1,n,1,x,y);
		if(ty==2)printf("%lld\n",query(1,n,1,x,y));
	}
	return 0;
}