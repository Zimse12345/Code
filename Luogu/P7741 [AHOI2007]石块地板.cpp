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

const int N=500,Mod=998244353,INF=1e9+7;
int n,m,f[N][N],ans,sum;
char s[N][N]; 

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(s[i][j]=='1'?1:-1);
	}
	
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
		sum=0;
		for(int k=1;k<=m;k++){
			sum+=f[j][k]-f[i-1][k]-f[j][k-1]+f[i-1][k-1];
			ans=max(ans,sum),sum=max(sum,0);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
