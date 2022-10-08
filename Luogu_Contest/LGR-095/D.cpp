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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,a,b,c,d,sx,sy,ex,ey,dis[N][N],vis[N][N];
char s[N][N];
struct node{
	int x,y,d;
	node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
priority_queue<node> Q;

void to(int ux,int uy,int vx,int vy){
	return;
}

int main(){
	n=read(),m=read(),a=read(),b=read(),c=read(),d=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			vis[i][j]=0,dis[i][j]=INF;
			if(s[i][j]=='S')sx=i,ey=j;
			if(s[i][j]=='E')ex=i,ey=j;
		}
	}
	Q.push(node(sx,sy,0)),dis[sx][sy]=0;
	while(!Q.empty()){
		int ux=Q.top().x,uy=Q.top().y;
		if(vis[ux][uy]++)continue;
		if(s[ux][uy]=='#')continue;
		if(s[ux][uy]=='|')to(ux,uy,ux+1,uy),to(ux,uy,ux-1,uy);
		if(s[ux][uy]=='-')to(ux,uy,ux,uy+1),to(ux,uy,ux,uy-1);
		if(s[ux][uy]=='/')to(ux,uy,ux-1,uy),to(ux,uy,ux,uy+1);
		if(s[ux][uy]=='\\')to(ux,uy,ux+1,uy),to(ux,uy,ux,uy-1);
		if(s[ux][uy]=='.')to(ux,uy,ux+1,uy),to(ux,uy,ux-1,uy),to(ux,uy,ux,uy+1),to(ux,uy,ux,uy-1);
		if(s[ux][uy]=='<')to(ux,uy,ux,uy-2);
		if(s[ux][uy]=='>')to(ux,uy,ux,uy+2);
		if(s[ux][uy]=='^')to(ux,uy,ux-2,uy);
		if(s[ux][uy]=='v')to(ux,uy,ux+2,uy);
	}
	return 0;
}
