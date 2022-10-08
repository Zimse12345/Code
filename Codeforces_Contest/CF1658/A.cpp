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
int T,n,pos[N],t,ans;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read(),t=ans=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)if(s[i]=='0')pos[++t]=i;
		for(int i=1;i<t;i++){
			int dis=pos[i+1]-pos[i];
			if(dis==1)ans+=2;
			if(dis==2)ans+=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

