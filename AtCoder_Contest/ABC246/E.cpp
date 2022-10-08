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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
const int dx[4]={-1,-1,1,1,},dy[4]={-1,1,-1,1};
int n,sx,sy,tx,ty,a[N][N][4],vis[N][N][4];
char s[N][N];
struct node{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};
deque<node> Q;

signed main(){
	n=read();
	sx=read(),sy=read(),tx=read(),ty=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int w=0;w<4;w++)if(!(i==sx&&j==sy))a[i][j][w]=INF;
	for(int i=0;i<4;i++)Q.push_back(node(sx,sy,i));
	while(!Q.empty()){
		node U=Q.front();
		Q.pop_front();
		int x=U.x,y=U.y,z=U.z;
		if(vis[x][y][z]++)continue;
		for(int w=0;w<4;w++){
			int tx=x+dx[w],ty=y+dy[w];
			if(tx<1||tx>n||ty<1||ty>n||s[tx][ty]=='#')continue;
			int dis=a[x][y][z]+((z==w&&(!(sx==x&&sy==y)))?0:1);
			if(dis<a[tx][ty][w]){
				a[tx][ty][w]=dis;
				if(z==w&&(!(sx==x&&sy==y)))Q.push_front(node(tx,ty,w));
				else Q.push_back(node(tx,ty,w));
			}
		}
	}
	int ans=INF;
	for(int i=0;i<4;i++)ans=min(ans,a[tx][ty][i]);
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}

