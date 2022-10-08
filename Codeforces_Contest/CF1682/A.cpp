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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int L=(n+1)/2,R=(n+1)/2;
		while(L>1&&s[L-1]==s[L])--L;
		while(R<n&&s[R+1]==s[R])++R;
		printf("%d\n",R-L+1);
	}
	return 0;
}

