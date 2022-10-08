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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,m,a[N][3],sum[N][3];

int main(){
	T=read();
	while(T--){
		m=read();
		for(int i=1;i<=m;i++)a[i][1]=read();
		for(int i=1;i<=m;i++)a[i][2]=read();
		for(int i=1;i<=m;i++)sum[i][2]=sum[i-1][2]+a[i][2];
		sum[m+1][1]=0;
		for(int i=m;i>=1;i--)sum[i][1]=sum[i+1][1]+a[i][1];
		
		int ans=2e9;
		for(int i=1;i<=m;i++){
			ans=min(ans,max(sum[i-1][2],sum[i+1][1]));
//			printf("[%d %d]\n",i,max(sum[i-1][1],sum[i+1][2]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
