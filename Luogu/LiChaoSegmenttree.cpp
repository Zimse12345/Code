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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,Rg=39989;
const double INF=1e18;
inline int calc(int x,int y,int mod){return (x+y-1)%mod+1;}
struct Line{int l,r;double k,b;Line(int l=0,int r=0,double k=0,double b=0):l(l),r(r),k(k),b(b){}};
struct LiChaoSegmenttree{
	int LineTot,cnt,rt,p[N*8],ch[N*8][2];Line s[N];
	double f(int id,double x){return s[id].k*x+s[id].b;}

	void ins(int L,int R,int& id,int x){
		if(s[x].r<L||R<s[x].l)return;
		if(!id)id=++cnt;
		if(s[x].l<=L&&s[x].r>=R){
			if(!p[id])p[id]=x;
			else if((L==R&&f(p[id],L)<f(x,L))||(s[p[id]].k==s[x].k&&s[p[id]].b<s[x].b))p[id]=x;
			else{
				double X=(s[x].b-s[p[id]].b)/(s[p[id]].k-s[x].k);
				if((X<=double(L)&&s[x].k>s[p[id]].k)||(X>=double(R)&&s[x].k<s[p[id]].k))p[id]=x;
				else{
					if(!(X>double(M)&&s[p[id]].k<s[x].k))ins(L,M,Lid,x);
					if(!(X<double(M)&&s[p[id]].k>s[x].k))ins(M+1,R,Rid,x);
				}
			}
		}
		else ins(L,M,Lid,x),ins(M+1,R,Rid,x);
		return;
	}

	int query(int L,int R,int id,int x){
		if(!id||L==R)return p[id];
		int _p=(x<=M?query(L,M,Lid,x):query(M+1,R,Rid,x));
		return (f(_p,x)<f(p[id],x)||(f(_p,x)==f(p[id],x)&&p[id]<_p))?p[id]:_p;
	}
}tree;

signed main(){
	int n(read()),a,b,c,d,ans=0,op;
	tree.s[0]=Line(0,Rg,0,-INF);
	while(n--){
		op=read();
		if(op){
			a=calc(read(),ans,Rg),b=calc(read(),ans,1e9),c=calc(read(),ans,Rg),d=calc(read(),ans,1e9);
			if(a>c)swap(a,c),swap(b,d);
			if(a==c)tree.s[++tree.LineTot]=Line(a,c,0,max(b,d));
			else{
				double k=double(d-b)/(c-a);
				tree.s[++tree.LineTot]=Line(a,c,k,b-a*k);
			}
			tree.ins(0,Rg,tree.rt,tree.LineTot);
		}
		else{
			a=calc(read(),ans,Rg);
			ans=tree.query(0,Rg,tree.rt,a);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

