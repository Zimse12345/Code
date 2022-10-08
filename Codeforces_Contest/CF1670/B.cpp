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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,tg[256];
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i='a';i<='z';i++)tg[i]=0;
		int cnt=read();
		while(cnt--){
			char c=getchar();
			while(c<'a'||c>'z')c=getchar();
			tg[c]=1;
		}
		int ans=0;
		for(int i=1,pr=1;i<=n;i++){
			if(tg[s[i]])ans=max(ans,i-pr),pr=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

