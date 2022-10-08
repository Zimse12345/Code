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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a,f[31],ans;

int main(){
	n=read()-1,a=read();
	for(int i=0;i<=30;i++)if(a&(1<<i))f[i]=1;
	while(n--){
		a=read();
		int mx=0;
		for(int i=0;i<=30;i++)if(a&(1<<i))mx=max(mx,f[i]);
		++mx;
		for(int i=0;i<=30;i++)if(a&(1<<i))f[i]=max(f[i],mx);
	}
	for(int i=0;i<=30;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
