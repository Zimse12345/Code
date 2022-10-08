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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,k,ans;
map<int,int> v;

signed main(){
	n=read(),k=read();
	v[0]=1;
	for(int i=1,a=0,s=0;i<=n;i++){
		a=read(),s+=a;
		if(v.count(s-k))ans+=v[s-k];
		if(!v.count(s))v[s]=0;
		++v[s];
	}
	printf("%lld\n",ans);
	return 0;
}

