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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,sx,sy,tx,ty,dis[N][N],vis[N][N];
char s[N][N];
struct node{
	int x,y,d;
	node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
priority_queue<node> Q;

void update(int ux,int uy,int vx,int vy){
	if(dis[ux][uy]+1<dis[vx][vy]){
		dis[vx][vy]=dis[ux][uy]+1;
		Q.push(node(vx,vy,dis[vx][vy]));
	}
	return;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
			dis[i][j]=INF;
			if(s[i][j]=='A')sx=i,sy=j;
			if(s[i][j]=='B')tx=i,ty=j;
		}
	}
	dis[sx][sy]=0;
	Q.push(node(sx,sy,0));
	while(!Q.empty()){
		int ux=Q.top().x,uy=Q.top().y;
		Q.pop();
		if(vis[ux][uy]++)continue;
		for(int i=ux+1,vx,vy;i<=n;i++){
			vx=i,vy=uy;
			if(s[vx][vy]=='x')break;
			update(ux,uy,vx,vy);
		}
		for(int i=ux-1,vx,vy;i>=1;i--){
			vx=i,vy=uy;
			if(s[vx][vy]=='x')break;
			update(ux,uy,vx,vy);
		}
		for(int i=uy+1,vx,vy;i<=n;i++){
			vx=ux,vy=i;
			if(s[vx][vy]=='x')break;
			update(ux,uy,vx,vy);
		}
		for(int i=uy-1,vx,vy;i>=1;i--){
			vx=ux,vy=i;
			if(s[vx][vy]=='x')break;
			update(ux,uy,vx,vy);
		}
	}
	if(dis[tx][ty]>=INF)dis[tx][ty]=0;
	printf("%d\n",dis[tx][ty]-1);
	return 0;
}
