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
int n,m,ans1,ans2;

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		int x=(n-i+1)*(m-j+1);
		if(i==j)ans1+=x;
		else ans2+=x;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
