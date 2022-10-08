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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void cf(int x){if(x)printf("YES\n");else printf("NO\n");return;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],sum;
map<int,int> v;
multiset<int> V;

bool sol(int x){
	if(!V.empty()&&x<(*V.begin()))return 0;
	if(x<=0)return 0;
	if(v[x]>0){
		--v[x];
		V.erase(V.find(x));
		return 1;
	}
	if(x==1)return 0;
	int a=x/2,b=x-a;
//	printf("(%lld %lld)\n",a,b);
	return sol(a)&&sol(b);
}

signed main(){
	T=read();
	while(T--){
		n=read();
		sum=0;
		v.clear(),V.clear();
		for(int i=1;i<=n;i++){
			a[i]=read();
			++v[a[i]];
			sum+=a[i];
			V.insert(a[i]);
		}
		sol(sum);
		int tag=1;
		for(int i=1;i<=n;i++)if(v[a[i]]>0)tag=0;
		cf(tag);
	}
	return 0;
}

