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
#define u mx[id]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod1=39989,Mod2=1e9,INF=1e18+7;
int n,mx[N<<2],ans,lc=0;
struct line{
	int l,r;
	double k,b;
	line(int l=0,int r=0,double k=0.0,double b=0.0):l(l),r(r),k(k),b(b){}
}s[N];
inline int hs(int x,int m){return (x+ans-1)%m+1;}
inline double fx(int f,double x){return s[f].k*x+s[f].b;}

void update(int L,int R,int id,int c){
//	printf("(%d %d %d %d)\n",L,R,c,id);
	int M=(L+R)>>1;
	if(s[c].l>R||s[c].r<L)return;
	if(L!=R&&s[c].l<=L&&s[c].r>=R){
		if(!u)u=c;
		else if(s[c].k==s[u].k&&s[c].b>s[u].b)u=c;
		else{
			double x=double(s[c].b-s[u].b)/double(s[u].k-s[c].k);
//			printf("[%d %d %.2f]\n",L,R,x);
			if((x<=double(L)&&s[c].k>s[u].k)||(x>=double(R)&&s[c].k<s[u].k))u=c;
			else{
				if(!(x>double(M)&&s[u].k<s[c].k))update(L,M,id<<1,c);
				if(!(x<double(M)&&s[u].k>s[c].k))update(M+1,R,(id<<1)|1,c);
			}
		}
	}
	else if(L!=R)update(L,M,id<<1,c),update(M+1,R,(id<<1)|1,c);
	else if((!u)||fx(u,L)<fx(c,L))u=c;
	return;
}

int query(int L,int R,int id,int x){
//	printf("[%d %d %d]\n",L,R,u);
	int res=0,M=(L+R)>>1,v;
	if(u&&s[u].l<=x&&x<=s[u].r)if(fx(u,x)>fx(res,x))res=u;
	if(L!=R&&x<=M){
		v=query(L,M,id<<1,x);
		if(fx(v,x)>fx(res,x))res=v;
	}
	if(L!=R&&x>M){
		v=query(M+1,R,(id<<1)|1,x);
		if(fx(v,x)>fx(res,x))res=v;
	}
	return res;
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	
	n=read(),s[0]=line(1,Mod1,0.0,-INF);
	for(int i=1,op,X0,Y0,X1,Y1;i<=n;i++){
		op=read();
		if(op==0){
			X0=hs(read(),Mod1);
			ans=query(1,Mod1,1,X0);
			printf("%lld\n",ans);
//			if(ans==86)printf("[%.2f %.2f] %d %d %d %d %d\n",fx(114,X0),fx(86,X0),X0,s[114].l,s[114].r,s[86].l,s[86].r);
		}
		else{
			X0=hs(read(),Mod1),Y0=hs(read(),Mod2);
			X1=hs(read(),Mod1),Y1=hs(read(),Mod2);
			if(X0>X1)swap(X0,X1),swap(Y0,Y1);
			double K=X0==X1?0:double(Y1-Y0)/double(X1-X0);
//			printf("(%d %d %d %d %d %.2f %.2f)\n",lc+1,X0,Y0,X1,Y1,K,double(Y0)-K*double(X0));
			s[++lc]=line(X0,X1,K,double(Y1)-K*double(X1));
			update(1,Mod1,1,lc);
		}
	}
	return 0;
}
