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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,ans;
struct s{
	int a,b;
	s(int a=0,int b=0):a(a),b(b){}
	bool operator < (const s& A)const{return b>A.b;}
}c[N],g[N];
multiset<int> se;

signed main(){
	n=read(),m=read();
	for(int i=1,a,b;i<=n;i++)a=read(),b=read(),c[i]=s(a,b);
	for(int i=1,a,b;i<=m;i++)a=read(),b=read(),g[i]=s(a,b);
	sort(c+1,c+n+1),sort(g+1,g+m+1);
	int L=1;
	for(int i=1;i<=n;i++){
		while(L<=m&&c[i].b<=g[L].b)se.insert(g[L].a),++L;
		if(se.empty()){
			printf("-1\n");
			return 0;
		}
		ans+=*se.lower_bound(c[i].a);
		se.erase(se.find(*se.lower_bound(c[i].a)));
	}
	printf("%lld\n",ans);
	return 0;
}
