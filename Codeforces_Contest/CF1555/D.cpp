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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,f[7][N],u[3];
char s[N],t[7][4];

int main(){
	n=read(),T=read();
	scanf("%s",s+1);
	t[1][1]='a',t[1][2]='b',t[1][3]='c';
	t[2][1]='a',t[2][2]='c',t[2][3]='b';
	t[3][1]='b',t[3][2]='a',t[3][3]='c';
	t[4][1]='b',t[4][2]='c',t[4][3]='a';
	t[5][1]='c',t[5][2]='a',t[5][3]='b';
	t[6][1]='c',t[6][2]='b',t[6][3]='a';
	for(int i=1;i<=6;i++){
		for(int j=1;j<=n;j++){
			if(s[j]!=t[i][j%3+1])f[i][j]=f[i][j-1]+1;
			else f[i][j]=f[i][j-1];
		}
	}

	while(T--){
		int l=read(),r=read();
		int ans=1e9;
		for(int i=1;i<=6;i++){
			ans=min(ans,f[i][r]-f[i][l-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

