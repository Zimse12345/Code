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
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,L,R,sx,sy,Len,so,q[N],vis[N][N],nx,ny;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
int lt=0;
node line[N];
vector<node> ans;
inline void aa(int x,int y){nx=x,ny=y,ans.push_back(node(x,y));return;}

void Go(int& x,int& y){
	if(y<=L)while(y<=R)aa(x,y),++y;
	else while(y>=L)aa(x,y),vis[x][y]=1,--y;
	return;
}

bool print_ans(){
	printf("YES\n%llu\n",ans.size());
	for(unsigned i=0;i<ans.size();i++)printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}


void Rto(int x_1,int y_1,int x_2,int y_2){
	while(y_1<=y_2)aa(x_1,y_1++);
	return;
}

void Lto(int x_1,int y_1,int x_2,int y_2){
	while(y_1>=y_2)aa(x_1,y_1--);
	return;
}

void Dto(int x_1,int y_1,int x_2,int y_2){
	while(x_1>=x_2)aa(x_1--,y_1);
	return;
}

void Uto(int x_1,int y_1,int x_2,int y_2){
	while(x_1<=x_2)aa(x_1++,y_1);
	return;
}

signed main(){
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	n=read(),m=read(),L=read(),R=read(),sx=read(),sy=read(),Len=read(),so=read();
	for(int i=1;i<=Len;i++)q[i]=read();
	q[0]=sx;
	int S=sx,T=sx;
	for(int i=0;i<Len;i++){
		if(q[i+1]>q[i]){
			for(int j=q[i];j<=q[i+1];j++){
				if(t)Rto(j,L,j,R);
				else Lto(j,R,j,L);
				t^=1;
			}
		}
		else{
			for(int j=q[i];j>=q[i+1];j--){
				if(t)Rto(j,L,j,R);
				else Lto(j,R,j,L);
				t^=1;
			}
		}
		S=min(S,q[i+1]),T=max(S,q[i+1]);
	}
	return print_ans();
}

