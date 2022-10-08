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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=128,Mod=998244353,INF=1e9+7;
int n,m,k,to[N][N][32],ans[N][N];
char s[N][N];

int getid(int x,int y){
	return (x-1)*m+y;
}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};

node getpos(int id){
	int x=(id-1)/m+1,y=id-(x-1)*m;
	return node(x,y);
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='U')to[i][j][0]=getid(i-1,j);
			if(s[i][j]=='D')to[i][j][0]=getid(i+1,j);
			if(s[i][j]=='L')to[i][j][0]=getid(i,j-1);
			if(s[i][j]=='R')to[i][j][0]=getid(i,j+1);
		}
	}
	for(int t=1;t<32;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				node p=getpos(to[i][j][t-1]);
				to[i][j][t]=to[p.x][p.y][t-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int id=getid(i,j);
			for(int t=30;t>=0;t--)if(k&(1<<t)){
				node p=getpos(id);
				id=to[p.x][p.y][t];
			}
			node p=getpos(id);
			ans[p.x][p.y]=getid(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

