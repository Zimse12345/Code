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
inline void yes(){printf("YES\n");return;}
inline void no(){printf("NO\n");return;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,a;

signed main(){
	T=read();
	while(T--){
		a=read();
		if(a%7==0){
			printf("%d\n",a);
			continue;
		}
		int t=a/10*10;
		for(int i=t;i<t+10;i++)if(i%7==0){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

