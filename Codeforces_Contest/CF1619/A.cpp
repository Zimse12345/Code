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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N]; 

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		if(n&1){
			printf("NO\n");
			continue;
		}
		int tag=1;
		for(int i=1;i<=n/2;i++)if(s[i]!=s[i+n/2])tag=0;
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

