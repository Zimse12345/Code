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

#define Lid ch[x][0]
#define Rid ch[x][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e9;
int n,q;

class LCT{
public:
int fa[N],ch[N][2],val[N],s[N],rev[N],treePath[N];
inline bool isRoot(int x){return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
inline bool sonType(int x){return ch[fa[x]][1]==x;}
inline void pushup(int x){s[x]=s[Lid]^s[Rid]^val[x];return;}
inline void pushdown(int x){if(rev[x])swap(Lid,Rid),rev[Lid]^=1,rev[Rid]^=1,rev[x]=0;return;}

inline void rotate(int x){
	int y=fa[x],z=fa[y],p=sonType(x),k=ch[x][!p];
	if(!isRoot(y))ch[z][sonType(y)]=x;ch[x][!p]=y,ch[y][p]=k;
	if(k)fa[k]=y;fa[y]=x,fa[x]=z;pushup(y);return;
}

inline void splay(int x){
	int y=x,z=1;treePath[1]=y;
	while(!isRoot(y))treePath[++z]=y=fa[y];
	while(z)pushdown(treePath[z--]);
	while(!isRoot(x)){
		y=fa[x],z=fa[y];
		if(!isRoot(y))rotate((sonType(x)^sonType(y))?x:y);
		rotate(x);
	}
	pushup(x);
	return;
}

inline void access(int x){
	for(int y=0;x;x=fa[y=x])splay(x),Rid=y,pushup(x);
	return;
}

inline void makeRoot(int x){
	access(x),splay(x),rev[x]^=1;
	return;
}

inline int findRoot(int x){
	access(x),splay(x);
	while(1){pushdown(x);if(Lid)x=Lid;else break;}
	splay(x);
	return x;
}

inline void split(int x,int y){
	makeRoot(x),access(y),splay(x);
	return;
}

inline void link(int x,int y){
	makeRoot(x);
	if(findRoot(y)!=x)fa[x]=y;
	return;
}

inline void cut(int x,int y){
	makeRoot(x);
	if(findRoot(y)==x&&fa[y]==x&&!ch[y][0])fa[y]=Rid=0,pushup(x);
	return;
}
}lct;

signed main(){
	int n=read(),q=read();
	for(int i=1;i<=n;i++)lct.val[i]=read();
	while(q--){
		int op=read(),x=read(),y=read();
		switch(op){
			case 0:{lct.split(x,y),printf("%d\n",lct.s[x]);break;}
			case 1:{lct.link(x,y);break;}
			case 2:{lct.cut(x,y);break;}
			case 3:{lct.splay(x),lct.val[x]=y,lct.pushup(x);break;}
		}
	}
	return 0;
}

