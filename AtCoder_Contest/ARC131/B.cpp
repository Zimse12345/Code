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
int n,m,t[N];
char s[N][N];

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(s[i][j]=='.'){
			for(int c='1';c<='5';c++)t[c]=0;
			t[1*s[i-1][j]]=1,t[1*s[i+1][j]]=1,t[1*s[i][j-1]]=1,t[1*s[i][j+1]]=1;
			for(int c='1';c<='5';c++)if(!t[c]){
				s[i][j]=c;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}

