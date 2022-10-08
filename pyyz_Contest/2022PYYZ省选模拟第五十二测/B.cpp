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
#include <cctype>

#define Lid ch[x][0]
#define Rid ch[x][1]

using namespace std;

const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){
		if(p==q){
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x){
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c){
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x){
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;

inline int read(){
	int v;
	IO.read_int(v);
	return v;
}

inline void write(int x){
	IO.write_int(x);
	IO.write_char('\n');
	return;
}

const int N=1e6+7,INF=1e9;
int n,q,pr[N],siz[N],X[N],Y[N],Dis[N];

int F(int x){
	if(pr[x]^x)pr[x]=F(pr[x]);
	return pr[x];
}

class LCT{
public:
int fa[N],ch[N][2],s[N],rev[N],p[N];
inline void pushup(int x){s[x]=s[Lid]+s[Rid]+1;return;}
inline void pushdown(int x){if(rev[x])swap(Lid,Rid),rev[Lid]^=1,rev[Rid]^=1,rev[x]=0;return;}
inline bool isR(int x){return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
inline bool sonT(int x){return ch[fa[x]][1]==x;}

inline void rot(int x){
	int y=fa[x],z=fa[y],p=sonT(x),k=ch[x][!p];
	if(!isR(y))ch[z][sonT(y)]=x;ch[x][!p]=y,ch[y][p]=k;
	if(k)fa[k]=y;fa[y]=x,fa[x]=z;pushup(y);return; 
}

inline void splay(int x){
	int y=x,z=1;p[1]=y;
	while(!isR(y))p[++z]=y=fa[y];
	while(z)pushdown(p[z--]);
	while(!isR(x)){
		y=fa[x],z=fa[y];
		if(!isR(y))rot((sonT(x)^sonT(y))?x:y);
		rot(x);
	}
	pushup(x);
	return;
}

inline void acc(int x){
	for(int y=0;x;x=fa[y=x])splay(x),Rid=y,pushup(x);
	return;
}

inline void makeR(int x){
	acc(x),splay(x);
	rev[x]^=1;
	return;
}

inline int findR(int x){
	acc(x),splay(x);
	while(1){pushdown(x);if(Lid)x=Lid;else break;}
	splay(x);
	return x;
}

inline void split(int x,int y){
	makeR(x),acc(y),splay(x);
	return;
}

inline void link(int x,int y){
	makeR(x);
	fa[x]=y;
	return;
}
}lct;

int dis(int x,int y){
	lct.split(x,y);
	return lct.s[x]-1;
}

signed main(){
//	freopen("hike2.in","r",stdin);
//	freopen("hike.out","w",stdout); 
	int type=read();
	int n=read(),q=read();
	for(int i=1;i<=n;i++)pr[i]=i,siz[i]=1,X[i]=Y[i]=i;
	int lans=0;
	while(q--){
		int op=read();
		if(op==1){
			int x=read(),y=read();
			if(type)x^=lans,y^=lans;
			lct.link(x,y);
			int fa=F(x),fb=F(y);
			if(siz[fa]<siz[fb])swap(fa,fb);
			pr[fb]=fa,siz[fa]+=siz[fb];
			int A=X[fa],B=Y[fa],C=X[fb],D=Y[fb];
			int ddis[6]={Dis[fa],Dis[fb],dis(A,C),dis(A,D),dis(B,C),dis(B,D)};
			int aa[6]={A,C,A,A,B,B},bb[6]={B,D,C,D,C,D};
			int mx=-1,pos=-1;
			for(int i=0;i<6;i++)if(ddis[i]>mx)mx=ddis[i],pos=i;
			X[fa]=aa[pos],Y[fa]=bb[pos],Dis[fa]=mx;
		}
		else{
			int x=read();
			if(type)x^=lans;
			int fa=F(x);
			lans=max(dis(X[fa],x),dis(Y[fa],x));
			write(lans);//putchar('\n');
//			printf("%d\n",lans);
		}
	}
	return 0;
}

