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

#define diss (dis[s.x1][s.y1][s.x2][s.y2])
#define dist (dis[t.x1][t.y1][t.x2][t.y2])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=35,Mod=998244353,INF=1e9+7;
int n,m,s1x,s1y,s2x,s2y,tx,ty;
int dis[N][N][N][N],vis[N][N][N][N];
char S[N][N];
struct node{
	int x1,y1,x2,y2,dis;
	node(int x1=0,int y1=0,int x2=0,int y2=0,int dis=0):x1(x1),y1(y1),x2(x2),y2(y2),dis(dis){}
	bool operator < (const node& A)const{return dis>A.dis;}
};
priority_queue<node> Q;

node U(node s){
	node t=node(s.x1,s.y1,s.x2,s.y2,1);
	if(s.x1==1||s.x2==1)t.dis=0;
	else if(S[s.x1-1][s.y1]=='X'||S[s.x2-1][s.y2]=='X')t.dis=0;
	else{
		if(S[s.x1-1][s.y1]!='#')--t.x1;
		if(S[s.x2-1][s.y2]!='#')--t.x2;
	}
	return t;
}

node D(node s){
	node t=node(s.x1,s.y1,s.x2,s.y2,1);
	if(s.x1==n||s.x2==n)t.dis=0;
	else if(S[s.x1+1][s.y1]=='X'||S[s.x2+1][s.y2]=='X')t.dis=0;
	else{
		if(S[s.x1+1][s.y1]!='#')++t.x1;
		if(S[s.x2+1][s.y2]!='#')++t.x2;
	}
	return t;
}

node L(node s){
	node t=node(s.x1,s.y1,s.x2,s.y2,1);
	if(s.y1==1||s.y2==m)t.dis=0;
	else if(S[s.x1][s.y1-1]=='X'||S[s.x2][s.y2+1]=='X')t.dis=0;
	else{
		if(S[s.x1][s.y1-1]!='#')--t.y1;
		if(S[s.x2][s.y2+1]!='#')++t.y2;
	}
	return t;
}

node R(node s){
	node t=node(s.x1,s.y1,s.x2,s.y2,1);
	if(s.y1==m||s.y2==1)t.dis=0;
	else if(S[s.x1][s.y1+1]=='X'||S[s.x2][s.y2-1]=='X')t.dis=0;
	else{
		if(S[s.x1][s.y1+1]!='#')++t.y1;
		if(S[s.x2][s.y2-1]!='#')--t.y2;
	}
	return t;
}

void update(node s,node t){
	if(diss+1<dist){
		t.dis=dist=diss+1;
		Q.push(t);
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",S[i]+1);
		for(int j=1;j<=m;j++){
			if(S[i][j]=='M')s1x=i,s1y=j;
			if(S[i][j]=='G')s2x=i,s2y=j;
			if(S[i][j]=='T')tx=i,ty=j;
		}
	}
	for(int i1=1;i1<=n;i1++)for(int i2=1;i2<=n;i2++){
		for(int j1=1;j1<=m;j1++)for(int j2=1;j2<=m;j2++)dis[i1][j1][i2][j2]=INF;
	}
	dis[s1x][s1y][s2x][s2y]=0,Q.push(node(s1x,s1y,s2x,s2y,0));
	while(!Q.empty()){
		node s=Q.top(),t;Q.pop();
		if(vis[s.x1][s.y1][s.x2][s.y2]++)continue;
		t=U(s);
		if(t.dis>0)update(s,t);
		t=D(s);
		if(t.dis>0)update(s,t);
		t=L(s);
		if(t.dis>0)update(s,t);
		t=R(s);
		if(t.dis>0)update(s,t);
	}
	if(dis[tx][ty][tx][ty]>=INF)printf("no\n");
	else printf("%d\n",dis[tx][ty][tx][ty]);
	return 0;
}
