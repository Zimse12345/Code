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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],ans;
map<int,int> p;

void add(int x){
	if(p.count(x)){
		ans+=p[x];
		++p[x];
	}
	else p[x]=1;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		add(i+a[i]),add(i-a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
