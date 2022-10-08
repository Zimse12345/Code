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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int a[N][N],b[N][N],n=1,T,_2[10240],Ans[500000],c1[10000],c2[10000];
int s1[100000],s2[100000];

struct query{
	int sz,x_1,y_1,x_2,y_2,id;
	query(int sz=0,int x_1=0,int y_1=0,int x_2=0,int y_2=0,int id=0):sz(sz),x_1(x_1),y_1(y_1),x_2(x_2),y_2(y_2),id(id){}
	bool operator < (const query& A)const{return sz<A.sz;}
}q[200000];

void build_nxt(){
	for(int x=0;x<(1<<n);x++){
		for(int y=0;y<(1ll<<n);y++){
			b[x][y+(1ll<<n)]=a[x][y]+(1ll<<(n*2));
			b[x+(1ll<<n)][y+(1ll<<n)]=a[x][y]+(1ll<<(n*2))*2;
			b[y][(1ll<<n)-x-1]=(1ll<<(n*2))-1-a[x][y];
			b[(1ll<<(n+1))-1-y][(1ll<<n)-x-1]=a[x][y]+(1ll<<(n*2))*3;
		}
	}
	++n;
	for(int x=0;x<(1<<n);x++){
		for(int y=0;y<(1<<n);y++){
			a[x][y]=b[x][y];
		}
	}
	for(int x=1;x<(1<<n);x++){
		(b[x][0]+=b[x-1][0])%=Mod;
		(b[0][x]+=b[0][x-1])%=Mod;
	}
	for(int x=1;x<(1<<n);x++){
		for(int y=1;y<(1<<n);y++){
			b[x][y]=(a[x][y]+b[x-1][y]+b[x][y-1]-b[x-1][y-1])%Mod;
		}
	}
	return;
}

int find(int sz,int x,int y){
	if(sz==0)return 0;
	int mid=(1ll<<(sz-1));
	if(x<mid&&y<mid)return find(sz-1,y,x);
	if(x<mid&&y>=mid)return find(sz-1,x,y-mid)+_2[(sz-1)*2];
	if(x>=mid&&y>=mid)return find(sz-1,x-mid,y-mid)+_2[(sz-1)*2]*2;
	if(x>=mid&&y<mid)return find(sz-1,(1ll<<(sz-1))-1-y,(1ll<<sz)-1-x)+_2[(sz-1)*2]*3;
	return 0;
}

void subtest1(){
	for(int i=1;i<=T;i++){
		int ans=find(q[i].sz,q[i].x_1,q[i].y_1);
		ans=(ans%Mod+Mod)%Mod;
		printf("%lld\n",ans);
	}
	return;
}

void subtest2(){
	for(int i=1;i<=T;i++){
		int ans=c2[q[i].sz];
		printf("%lld\n",ans);
	}
	return;
}

void subtest3(){
	for(int i=1;i<=T;i++){
		int ans=c2[q[i].sz]*((q[i].y_2+1)%Mod)%Mod;
		printf("%lld\n",ans);
	}
	return;
}

void subtest4(){
	for(int i=1;i<=T;i++){
		int ans=s2[q[i].sz];
		for(int j=0;j<=q[i].sz;j++){
			if(q[i].x_1&(1ll<<j))(ans+=_2[j*3+2])%=Mod;
		}
		printf("%lld\n",ans);
	}
	return;
}

void subtest5(){
	for(int i=1;i<=T;i++){
		int ans=s2[q[i].sz]*((q[i].x_2+1)%Mod)%Mod;
		for(int j=0;j<=q[i].sz;j++){
			int ct=(q[i].x_2&(1ll<<j))?q[i].x_2%(1ll<<j)+1:0;
			ct+=q[i].x_2/(1ll<<(j+1))*(1ll<<j);
			ct%=Mod;
			(ans+=_2[j*3+2]*ct)%=Mod;
		}
		printf("%lld\n",ans);
	}
	return;
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	_2[0]=1;
	for(int i=1;i<1024;i++)_2[i]=(_2[i-1]*2)%Mod;
	a[0][0]=0,a[0][1]=1,a[1][1]=2,a[1][0]=3;
	b[0][0]=0,b[0][1]=1,b[1][1]=6,b[1][0]=3;
	c1[1]=3;
	for(int i=2;i<1000;i++)c1[i]=(c1[i-1]*2)%Mod;
	c2[1]=3;
	s1[1]=1;
	for(int i=2;i<1000;i++)s1[i]=(s1[i-1]*2+2)%Mod;
	s2[1]=1;
	for(int i=2;i<1000;i++){
		int p2=1;
		for(int j=i;j>=1;j--){
			s2[i]=(s2[i]+s1[j]*p2)%Mod;
			p2=(p2*8)%Mod;
		}
	}
	for(int i=2;i<1000;i++){
		int p2=1;
		for(int j=i;j>=1;j--){
			c2[i]=(c2[i]+c1[j]*p2)%Mod;
			p2=(p2*8)%Mod;
		}
	}
	T=read();
	int tag1=1,tag2=1,tag3=1,tag4=1,tag5=1;
	for(int i=1,sz,x_1,y_1,x_2,y_2;i<=T;i++){
		sz=read(),x_1=read(),y_1=read(),x_2=read(),y_2=read();
		q[i]=query(sz,x_1,y_1,x_2,y_2,i);
		if(!(x_1==x_2&&y_1==y_2))tag1=0;
		if(!(y_1==y_2&&x_1==0&&x_2==(1ll<<sz)-1))tag2=0;
		if(!(y_1==0&&x_1==0&&x_2==(1ll<<sz)-1))tag3=0;
		if(!(x_1==x_2&&y_1==0&&y_2==(1ll<<sz)-1))tag4=0;
		if(!(x_1==0&&y_1==0&&y_2==(1ll<<sz)-1))tag5=0;
	}
	if(tag1){
		subtest1();
		return 0;
	}
	if(tag2){
		subtest2();
		return 0;
	}
	if(tag3){
		subtest3();
		return 0;
	}
	if(tag4){
		subtest4();
		return 0;
	}
	if(tag5){
		subtest5();
		return 0;
	}
	sort(q+1,q+T+1);
	for(int i=1,x_1,y_1,x_2,y_2;i<=T;i++){
		while(n<q[i].sz)build_nxt();
		x_1=q[i].x_1,y_1=q[i].y_1,x_2=q[i].x_2,y_2=q[i].y_2;
		int ans=b[x_2][y_2];
		if(x_1)ans-=b[x_1-1][y_2];
		if(y_1)ans-=b[x_2][y_1-1];
		if(x_1&&y_1)ans+=b[x_1-1][y_1-1];
		ans=(ans%Mod+Mod)%Mod;
		Ans[q[i].id]=ans;
	}
	for(int i=1;i<=T;i++)printf("%lld\n",Ans[i]);
	return 0;
}

