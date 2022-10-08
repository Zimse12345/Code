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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T;
char s[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		if((s[1]=='Y'||s[1]=='y')&&(s[2]=='E'||s[2]=='e')&&(s[3]=='S'||s[3]=='s'))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

