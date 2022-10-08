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
#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,rt[1100];
int sum[N*64];
signed ch[N*144][2],tot,sz[N*64];
struct node{int v,x;node(int v=0,int x=0):v(v),x(x){}
bool operator < (const node& A)const{return v>A.v;}}p[510000];

int qu(int i,int j,int k,int ty){
	int id=((i*(m+1))+j)*1005+k;
	if(ty)id+=(n+1)*(m+1)*1005;
	if(id<N*64)return sum[id];
	id-=N*64;
	if(id<N*64)return sz[id];
	id-=N*64;
	if(id<N*144)return ch[id][0];
	id-=N*144;
	return ch[id][1];
}

void chg(int i,int j,int k,int ty,int x){
	int id=((i*(m+1))+j)*1005+k;
	if(ty)id+=(n+1)*(m+1)*1005;
	if(id<N*64){sum[id]=x;return;}
	id-=N*64;
	if(id<N*64){sz[id]=x;return;}
	id-=N*64;
	if(id<N*144){ch[id][0]=x;return;}
	id-=N*144,ch[id][1]=x;
	return;
}

int ins(int L,int R,int id,int k,int v){
	int _id=++tot;
	if(L==R)sum[_id]=sum[id]+v,sz[_id]=sz[id]+1;
	else{
		if(k<=M)ch[_id][0]=ins(L,M,Lid,k,v),ch[_id][1]=Rid;
		else ch[_id][1]=ins(M+1,R,Rid,k,v),ch[_id][0]=Lid;
		sum[_id]=sum[ch[_id][0]]+sum[ch[_id][1]],sz[_id]=sz[ch[_id][0]]+sz[ch[_id][1]];
	}
	return _id;
}

int query(int L,int R,int id,int l,int r){
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R)return sum[id];
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

int _query(int L,int R,int id,int l,int r){
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R)return sz[id];
	return _query(L,M,Lid,l,r)+_query(M+1,R,Rid,l,r);
}

signed main(){
	n=read(),m=read(),q=read();
	if(n==1){
		for(int i=1;i<=m;i++)p[i]=node(read(),i);
		sort(p+1,p+m+1);
		for(int val=1000,t=1;val>=1;val--){
			rt[val]=rt[val+1];
			while(p[t].v==val)rt[val]=ins(1,m,rt[val],p[t].x,val),++t;
		}
		while(q--){
			int b1,b2,H;
			read(),b1=read(),read(),b2=read(),H=read();
			int L=1,R=1000,ans=-1,h=0;
			while(L<=R){
				int sum=query(1,m,rt[M],b1,b2);
				if(sum>=H)ans=M,L=M+1,h=sum;
				else R=M-1;
			}
			if(ans==-1)printf("Poor QLW\n");
			else printf("%lld\n",_query(1,m,rt[ans],b1,b2)-(h-H)/ans);
		}
	}
	else{
		for(int i=1,x;i<=n;i++)for(int j=1;j<=m;j++){
			x=read();
			for(int k=1;k<=x;k++){
				chg(i,j,k,0,qu(i-1,j,k,0)+qu(i,j-1,k,0)-qu(i-1,j-1,k,0)+x);
				chg(i,j,k,1,qu(i-1,j,k,1)+qu(i,j-1,k,1)-qu(i-1,j-1,k,1)+1);
			}
			for(int k=x+1;k<=1000;k++){
				chg(i,j,k,0,qu(i-1,j,k,0)+qu(i,j-1,k,0)-qu(i-1,j-1,k,0));
				chg(i,j,k,1,qu(i-1,j,k,1)+qu(i,j-1,k,1)-qu(i-1,j-1,k,1));
			}
		}
		while(q--){
			int a1=read(),b1=read(),a2=read(),b2=read(),H=read();
			int L=1,R=1000,ans=-1,h=0;
			while(L<=R){
				int sum=qu(a2,b2,M,0)-qu(a2,b1-1,M,0)-qu(a1-1,b2,M,0)+qu(a1-1,b1-1,M,0);
				if(sum>=H)ans=M,L=M+1,h=sum;
				else R=M-1;
			}
			if(ans==-1)printf("Poor QLW\n");
			else printf("%lld\n",qu(a2,b2,ans,1)-qu(a2,b1-1,ans,1)-qu(a1-1,b2,ans,1)+qu(a1-1,b1-1,ans,1)-(h-H)/ans);
		}
	}
	return 0;
}

