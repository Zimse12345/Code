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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
const int dx[5]={-1,0,1,0,0},dy[5]={0,-1,0,1,0};
int H,W,Q,X[N],Y[N],Min[N*8],cnt[N*8],tag[N*8];
vector< vector<int> > p,vis;
vector<int> emp_line;

inline void pushdown(int id){
	if(tag[id]!=0)Min[id]+=tag[id],tag[Lid]+=tag[id],tag[Rid]+=tag[id],tag[id]=0;
	return;
}

void build(int L,int R,int id){
	cnt[id]=R-L+1;
	if(L^R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void add(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]+=x,pushdown(id);
	else{
		add(L,M,Lid,l,r,x),add(M+1,R,Rid,l,r,x);
		Min[id]=min(Min[Lid],Min[Rid]),cnt[id]=0;
		if(Min[Lid]==Min[id])cnt[id]+=cnt[Lid];
		if(Min[Rid]==Min[id])cnt[id]+=cnt[Rid];
	}
	return;
}

inline void calc1(int id,int t){
	int l=id,r=0,x=X[id],y=Y[id];
	if(!x&&!y)r=H*W-1;
	else if(!x)r=p[x][y-1]-1;
	else if(!y)r=p[x-1][y]-1;
	else r=min(p[x][y-1],p[x-1][y])-1;
	if(l<=r)add(0,H*W-1,1,l,r,t);
	return;
}

inline void calc2(int id,int t){
	int i=X[id],j=Y[id];
	vector<int> vec;vec.clear();
	for(int w=0,x,y;w<4;w++){
		x=i+dx[w],y=j+dy[w];
		if(x<0||x>=H||y<0||y>=W)continue;
		vec.push_back(p[x][y]);
	}
	if(signed(vec.size())<2)return;
	sort(vec.begin(),vec.end());
	int l=vec[1],r=id-1;
	if(l<=r)add(0,H*W-1,1,l,r,t);
	return;
}

inline void calc(int i,int t){
	calc1(i,t),calc2(i,t);
	return;
}

signed main(){
	H=read(),W=read(),Q=read();
	build(0,H*W-1,1);
	for(int i=0;i<W;i++)emp_line.push_back(0);
	for(int i=0;i<H;i++)p.push_back(emp_line),vis.push_back(emp_line);
	for(int i=0;i<H*W;i++){
		X[i]=read(),Y[i]=read();
		p[X[i]][Y[i]]=i;
	}
	for(int i=0;i<H*W;i++)calc(i,1);
	for(int i=0,A,B;i<Q;i++){
		A=read(),B=read();
		for(int w=0,x,y;w<5;w++){
			x=X[A]+dx[w],y=Y[A]+dy[w];
			if(x<0||x>=H||y<0||y>=W)continue;
			vis[x][y]=1;
			calc(p[x][y],-1);
		}
		for(int w=0,x,y;w<5;w++){
			x=X[B]+dx[w],y=Y[B]+dy[w];
			if(x<0||x>=H||y<0||y>=W||vis[x][y])continue;
			vis[x][y]=1;
			calc(p[x][y],-1);
		}
		swap(p[X[A]][Y[A]],p[X[B]][Y[B]]);
		swap(X[A],X[B]),swap(Y[A],Y[B]);
		for(int w=0,x,y;w<5;w++){
			x=X[A]+dx[w],y=Y[A]+dy[w];
			if(x<0||x>=H||y<0||y>=W||!vis[x][y])continue;
			vis[x][y]=0;
			calc(p[x][y],1);
		}
		for(int w=0,x,y;w<5;w++){
			x=X[B]+dx[w],y=Y[B]+dy[w];
			if(x<0||x>=H||y<0||y>=W||!vis[x][y])continue;
			vis[x][y]=0;
			calc(p[x][y],1);
		}
		if(Min[1]==1)printf("%d\n",cnt[1]);
		else printf("0\n");
	}
	return 0;
}

