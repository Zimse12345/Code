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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n;
string a[N],b[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		int taga=0,tagb=0;
		for(int j=1;j<=n;j++)if(i^j){
			if((a[i]==a[j])||(a[i]==b[j]))taga=1;
			if((b[i]==a[j])||(b[i]==b[j]))tagb=1;
		}
		if(taga&&tagb){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}

