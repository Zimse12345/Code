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
#define M ((L+R)>>1)
 
using namespace std;
 
inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}
 
const int N=5e5+7,INF=1e9+7;
int n,m,k,q,eu[N],ev[N],e[N],c[N],ans[N];
int po[N],fa[51][N<<1],dep[51][N<<1],pr[N],p[N]; 
vector<int> op[N*4];
struct node{int x,y,a,b;node(int x=0,int y=0,int a=0,int b=0):x(x),y(y),a(a),b(b){}};
node re[N][4];
int F(int x,int k){return fa[k][x]==x?x:F(fa[k][x],k);}
 
void update(int L,int R,int id,int l,int r,int x){
	if(l<=L&&r>=R){
		op[id].push_back(x);
		return;
	}
	if(l<=M)update(L,M,Lid,l,r,x);
	if(r>M)update(M+1,R,Rid,l,r,x);
	return;
}
 
void sol(int L,int R,int id){
	if(L==R)op[id].push_back(L);
	for(unsigned i=0,x;i<op[id].size();i++){
		x=op[id][i];
		if(!e[x])continue;
		int u=eu[e[x]],v=ev[e[x]],cl=c[x];
		int A=F(u,cl),B=F(v,cl),C=F(u+n,cl),D=F(v+n,cl);
		if(dep[cl][A]<dep[cl][D])swap(A,D);
		if(dep[cl][B]<dep[cl][C])swap(B,C);
		re[x][0]=node(cl,A,fa[cl][A],dep[cl][A]);
		re[x][1]=node(cl,B,fa[cl][B],dep[cl][B]);
		re[x][2]=node(cl,C,fa[cl][C],dep[cl][C]);
		re[x][3]=node(cl,D,fa[cl][D],dep[cl][D]);
		if(D^A)fa[cl][D]=A,dep[cl][A]=max(dep[cl][A],dep[cl][D]+1);
		if(C^B)fa[cl][C]=B,dep[cl][B]=max(dep[cl][B],dep[cl][C]+1);
	}
	if(L^R)sol(L,M,Lid),sol(M+1,R,Rid);
	else{
		int u=eu[e[L]];
		if(F(u,c[L])==F(u+n,c[L]))ans[L]=1,c[L]=p[e[L]];
		else p[e[L]]=c[L];
	}
	for(unsigned i=0,x;i<op[id].size();i++){
		x=op[id][i];
		if(!e[x])continue;
		for(int j=0;j<4;j++)fa[re[x][j].x][re[x][j].y]=re[x][j].a,dep[re[x][j].x][re[x][j].y]=re[x][j].b;
	}
	if(L==R)op[id].resize(op[id].size()-1);
	return;
}
 
int main(){
	n=read(),m=read(),k=read(),q=read();
	for(int i=1;i<=m;i++)eu[i]=read(),ev[i]=read();
	for(int i=1;i<=q;i++)e[i]=read(),c[i]=read();
	for(int i=1;i<=k;i++)for(int j=1;j<=n*2;j++)fa[i][j]=j,dep[i][j]=1;
	
	for(int i=1;i<=q;i++){
		if(pr[e[i]]&&pr[e[i]]+1<=i-1)update(1,q,1,pr[e[i]]+1,i-1,pr[e[i]]);
		pr[e[i]]=i;
	}
	for(int i=1;i<=m;i++)if(pr[i]&&pr[i]+1<=q)update(1,q,1,pr[i]+1,q,pr[i]);
	sol(1,q,1);
	for(int i=1;i<=q;i++){
		if(ans[i])printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

