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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],p[N],ans[N];
double f[N]; 

int main(){
	n=read();
	f[0]=1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)if(a[i+1]<a[i]){
		ans[i+1]^=1;
		ans[i]^=1;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n"); 
	return 0;
}
