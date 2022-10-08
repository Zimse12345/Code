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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
multiset<int> L,R;

signed main(){
	int q=read();
	while(q--){
		int op=read();
		if(op==1){
			int x=read();
			L.insert(x),R.insert(-x);
		}
		if(op==2){
			int x=read(),y=read();
			while(y--){
				if(L.find(x)!=L.end())L.erase(L.find(x)),R.erase(R.find(-x));
				else break;
			}
		}
		if(op==3){
			printf("%lld\n",-(*L.begin())-(*R.begin()));
		}
	}
	return 0;
}

