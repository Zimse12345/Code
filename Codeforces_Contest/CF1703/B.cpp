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
int T,vis[N];
char s[N];

signed main(){
	T=read();
	while(T--){
		int n=read();
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++){
			if(!vis[s[i]])++ans,vis[s[i]]=1;
		}
		for(int i=0;i<=200;i++)vis[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}

