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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int A[4][16],B[4][16],F[7][8][7][8][7][8][7][8];
char s[8];

int dfs(int p,int a,int b,int c,int d,int e,int f,int g,int h){
	//1 win
	//2 draw
	//3 lose
//	printf("(%d %d %d %d %d %d %d %d)\n",a,b,c,d,e,f,g,h);
	if(F[a][b][c][d][e][f][g][h])return F[a][b][c][d][e][f][g][h];
	if(a+b+c+d+e+f+g+h==52)return 2;
	int to[4]={0,0,0,0};
	if(p){
		if(b&&A[0][6-a])to[dfs(p^1,a+1,b,c,d,e,f,g,h)]=1;
		if(A[0][7+b])to[dfs(p^1,a,b+1,c,d,e,f,g,h)]=1;
		if(d&&A[1][6-c])to[dfs(p^1,a,b,c+1,d,e,f,g,h)]=1;
		if(A[1][7+d])to[dfs(p^1,a,b,c,d+1,e,f,g,h)]=1;
		if(f&&A[2][6-e])to[dfs(p^1,a,b,c,d,e+1,f,g,h)]=1;
		if(A[2][7+f])to[dfs(p^1,a,b,c,d,e,f+1,g,h)]=1;
		if(h&&A[3][6-g])to[dfs(p^1,a,b,c,d,e,f,g+1,h)]=1;
		if(A[3][7+h])to[dfs(p^1,a,b,c,d,e,f,g,h+1)]=1;
	}
	else{
		if(b&&B[0][6-a])to[dfs(p^1,a+1,b,c,d,e,f,g,h)]=1;
		if(B[0][7+b])to[dfs(p^1,a,b+1,c,d,e,f,g,h)]=1;
		if(d&&B[1][6-c])to[dfs(p^1,a,b,c+1,d,e,f,g,h)]=1;
		if(B[1][7+d])to[dfs(p^1,a,b,c,d+1,e,f,g,h)]=1;
		if(f&&B[2][6-e])to[dfs(p^1,a,b,c,d,e+1,f,g,h)]=1;
		if(B[2][7+f])to[dfs(p^1,a,b,c,d,e,f+1,g,h)]=1;
		if(h&&B[3][6-g])to[dfs(p^1,a,b,c,d,e,f,g+1,h)]=1;
		if(B[3][7+h])to[dfs(p^1,a,b,c,d,e,f,g,h+1)]=1;
	}
	if(to[3]){
		F[a][b][c][d][e][f][g][h]=1;
	}
	else if(to[2]){
		F[a][b][c][d][e][f][g][h]=2;
	}
	else F[a][b][c][d][e][f][g][h]=3;
	return F[a][b][c][d][e][f][g][h];
}

signed main(){
	for(int i=1;i<=26;i++){
		scanf("%s",s+1);
		int ty=0;
		if(s[1]=='H')ty=1;
		if(s[1]=='C')ty=2;
		if(s[1]=='D')ty=3;
		int num=s[2]-'0';
		if(strlen(s+1)>2)num=num*10+s[3]-'0';
		A[ty][num]=1;
	}
	for(int i=0;i<4;i++)for(int j=1;j<=13;j++)B[i][j]=!A[i][j];
	//Alice 1
	//Bob 0
	if(A[0][7]){
		dfs(0,0,1,0,0,0,0,0,0);
		if(F[0][1][0][0][0][0][0][0]==1)printf("Bob\n");
		else if(F[0][1][0][0][0][0][0][0]==2)printf("Draw\n");
		else printf("Alice\n");
	}
	else{
		dfs(1,0,1,0,0,0,0,0,0);
		if(F[0][1][0][0][0][0][0][0]==1)printf("Alice\n");
		else if(F[0][1][0][0][0][0][0][0]==2)printf("Draw\n");
		else printf("Bob\n");
	}
	return 0;
}

