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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
set<int> from,to;

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=0;i<n;i++)a[i]=read();
		from.clear(),to.clear();
		for(int i=0;i<n;i++){
			for(set<int>::iterator it=from.begin();it!=from.end();it++){
				to.insert((*it)+a[i]);
				to.insert((*it)-a[i]);
				to.insert(*it);
			}
			to.insert(a[i]),to.insert(-a[i]);
			from=to;
		}
		for(set<int>::iterator it=from.begin();it!=from.end();it++)if((*it)==0)ans=1;
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

