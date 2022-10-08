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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e5+7,INF=1e9+7;
struct opt{int x,y;opt(int x=0,int y=0):x(x),y(y){}};
struct node{int x,y,z;node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}};
int n,m,k,ans[N],fa[N*2],dep[N];
vector<opt> op[N*4];
inline int F(int x){return fa[x]==x?x:F(fa[x]);}

void add(int L,int R,int id,int l,int r,int x,int y){
	if(l>R||r<L)return;
	if(l<=L&&r>=R)op[id].push_back(opt(x,y));
	else{
		int M=(L+R)>>1;
		add(L,M,Lid,l,r,x,y),add(M+1,R,Rid,l,r,x,y);
	}
	return;
}

void re(vector<node>& r){
	for(int i=signed(r.size())-1,x;i>=0;i--){
		x=r[i].x;
		fa[x]=r[i].y,dep[x]=r[i].z;
	}
	r.resize(0);
	return;
}

void sol(int L,int R,int id){
	if(L>R)return;
	vector<node> r;
	r.resize(0);
	
	for(int i=0,x,y;i<signed(op[id].size());i++){
		x=op[id][i].x,y=op[id][i].y;
//		printf("[%d %d %d %d]\n",L,R,x,y);
		int A=F(x),B=F(y),C=F(x+n),D=F(y+n);
//		printf("(%d %d %d %d)\n",A,B,C,D);
		if(dep[A]<dep[D])swap(A,D);
		if(dep[B]<dep[C])swap(B,C);
		r.push_back(node(A,fa[A],dep[A]));
		r.push_back(node(B,fa[B],dep[B]));
		r.push_back(node(C,fa[C],dep[C]));
		r.push_back(node(D,fa[D],dep[D]));
		fa[D]=A,dep[A]=max(dep[A],dep[D]+1);
		fa[C]=B,dep[B]=max(dep[B],dep[C]+1);
		if(F(x)==F(x+n)){
			for(int i=L;i<=R;i++)printf("No\n");
			re(r);
			return;
		}
	}
	if(L==R)printf("Yes\n");
	else{
		int M=(L+R)>>1;
		sol(L,M,Lid),sol(M+1,R,Rid);
	}
	re(r);
	return;
}

int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n*2;i++)fa[i]=i,dep[i]=1; 
	for(int i=1,x,y,l,r;i<=m;i++){
		x=read(),y=read(),l=read()+1,r=read();
		add(1,k,1,l,r,x,y);
	}
	sol(1,n,1);
	return 0;
}

