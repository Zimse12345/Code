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

const int N=2e5+7,Mod=1e9+7;
struct opt{int ty,x,y;opt(int ty=0,int x=0,int y=0):ty(ty),x(x),y(y){}}op[N];
int K,n,q,a[N],b[N],val[N],valtot,t[N],rval[N];
map<int,int> V;
int qt,ct,ans1,ans2,sum1,sum2,cnt[N],Ans[N];
struct query{
	int x,y,z,ty;
	query(int x=0,int y=0,int z=0,int ty=0):x(x),y(y),z(z),ty(ty){}
	bool operator < (const query& A){if(x/K==A.x/K){if(y/K==A.y/K)return z<A.z;return y<A.y;}return x<A.x;}
}Q[N];
struct chg{int x,from,to,z;chg(int x=0,int from=0,int to=0,int z=0):x(x),from(from),to(to),z(z){}}C[N];

void add(int x){
	++cnt[x];
	if(cnt[x]==1){
		++ans1,x=rval[x];
		ans2=(ans2+x*sum2)%Mod,sum2=(sum2+x*sum1)%Mod,sum1=(sum1+x)%Mod;
	}
	return;
}

void del(int x){
	--cnt[x];
	if(cnt[x]==0){
		--ans1,x=rval[x];
		sum1=(sum1-x)%Mod,sum2=(sum2-x*sum1)%Mod,ans2=(ans2-x*sum2)%Mod;
	}
	return;
}

signed main(){
	n=read(),q=read(),K=max(1.0,pow(double(n),0.67));
	for(int i=1;i<=n;i++)a[i]=read(),val[++valtot]=a[i];
	for(int i=1,ty,x,y=0;i<=q;i++){
		ty=read(),x=read();
		if(ty^3)y=read();
		op[i]=opt(ty,x,y);
		if(ty==2||ty==4)val[++valtot]=y;
	}
	sort(val+1,val+valtot+1);
	for(int i=1,j=0;i<=valtot;i++)if(val[i]!=val[i-1])V[val[i]]=++j,rval[j]=val[i];
	for(int i=1;i<=n;i++)a[i]=b[i]=V[a[i]];
	for(int i=1;i<=q;i++)if(op[i].ty==2||op[i].ty==4)op[i].y=V[op[i].y];
	
	if(n*q<=1e7){
		for(int i=1,ty,x,y;i<=q;i++){
			ty=op[i].ty,x=op[i].x,y=op[i].y;
			if(ty==1){
				int sum=0,s1=0,s2=0;
				for(int i=x;i<=y;i++)if(!t[a[i]])sum=(sum+s2*rval[a[i]])%Mod,s2=(s2+s1*rval[a[i]])%Mod,s1=(s1+rval[a[i]])%Mod,t[a[i]]=1;
				for(int i=x;i<=y;i++)t[a[i]]=0;
				printf("%lld\n",sum);
			}
			if(ty==2)a[x]=y;
			if(ty==3){
				for(int i=x;i<n;i++)a[i]=a[i+1];
				--n;
			}
			if(ty==4){
				++x,++n;
				for(int i=n;i>=x+1;i--)a[i]=a[i-1];
				a[x]=y;
			}
			if(ty==5){
				int sum=0;
				for(int i=x;i<=y;i++)if(!t[a[i]])++sum,t[a[i]]=1;
				for(int i=x;i<=y;i++)t[a[i]]=0;
				printf("%lld\n",sum);
			}
		}
	}
	else{
		for(int i=1;i<=q;i++){
			if(op[i].ty==1||op[i].ty==5)Q[++qt]=query(op[i].x,op[i].y,i,op[i].ty);
			else C[++ct]=chg(op[i].x,b[op[i].x],op[i].y,i),b[op[i].x]=op[i].y;
		}
		sort(Q+1,Q+qt+1);
		for(int i=1,x=1,y=0,z=0,u,v,t;i<=qt;i++){
			u=Q[i].x,v=Q[i].y,t=Q[i].z;
			while(y<v)add(a[++y]);
			while(x>u)add(a[--x]);
			while(y>v)del(a[y--]);
			while(x<u)del(a[x++]);
			while(z&&C[z].z>t){
				if(u<=C[z].x&&C[z].x<=v)del(C[z].to),add(C[z].from);
				a[C[z].x]=C[z].from,--z;
			}
			while(z<ct&&C[z+1].z<=t){
				++z,a[C[z].x]=C[z].to;
				if(u<=C[z].x&&C[z].x<=v)del(C[z].from),add(C[z].to);
			}
			if(Q[i].ty==5)Ans[Q[i].z]=ans1;
			else Ans[Q[i].z]=(ans2+Mod)%Mod;
		}
		for(int i=1;i<=q;i++)if(op[i].ty==1||op[i].ty==5)printf("%lld\n",Ans[i]);
	}
	return 0;
}

