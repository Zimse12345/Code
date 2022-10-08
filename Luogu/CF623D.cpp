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
int n,a[N];
double ans,f[N],g[N];

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ans=n;
	double s=1.0;
	for(int i=1;i<=n;i++)g[i]=1-double(a[i])/double(100),f[i]=g[i],s*=(1.0-f[i]);
	for(int i=1;i<=3e5;i++){
		int mx=1;
		for(int i=1;i<=n;i++){
			if(s/(1-f[i])*(1-f[i]*g[i])>s/(1-f[mx])*(1-f[mx]*g[mx]))mx=i;
		}
		ans+=1.0-s;
		s=s/(1-f[mx])*(1-f[mx]*g[mx]);
		f[mx]*=g[mx];
	}
	printf("%.7f",ans);
	return 0;
}
