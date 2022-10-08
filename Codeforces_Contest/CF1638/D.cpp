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
int n,m,a[N][N],t;
struct ans{int x,y,c;ans(int x=0,int y=0,int c=0):x(x),y(y),c(c){}}s[N*N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
queue<node> q;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	for(int i=1;i<n;i++)for(int j=1;j<m;j++){
		if(a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+1][j+1]){
			s[++t]=ans(i,j,a[i][j]);
			a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=0;
			q.push(node(i,j));
		}
	}
	int cl[5],ct;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y;
		q.pop();
		for(int i=x-1;i<=x+1;i++)for(int j=y-1;j<=y+1;j++)if(i>=1&&i<n&&j>=1&&j<m){
			ct=0;
			cl[ct++]=a[i][j],cl[ct++]=a[i+1][j],cl[ct++]=a[i][j+1],cl[ct++]=a[i+1][j+1];
			sort(cl,cl+4);
			if(cl[3]==0)continue;
			if((cl[1]!=0&&cl[1]!=cl[2])||(cl[2]!=0&&cl[2]!=cl[3]))continue;
			s[++t]=ans(i,j,cl[3]);
			q.push(node(i,j));
			a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=0;
		}
	}
	int tag=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!=0)tag=0;
	if(tag){
		printf("%d\n",t);
		for(int i=t;i>=1;i--)printf("%d %d %d\n",s[i].x,s[i].y,s[i].c);
	}
	else printf("-1\n");
	return 0;
}

