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
int T,n,t[N],d[N];
char s[N],ss[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int k=read();
		for(int i=1;i<=n;i++)ss[i]=s[i]-'a'+1,k-=ss[i];
		sort(ss+1,ss+n+1);
		int p=n;
		while(p&&k<0)k+=ss[p],++d[ss[p]],--p;
		for(int i=1;i<=n;i++){
			if(d[s[i]-'a'+1])--d[s[i]-'a'+1];
			else printf("%c",s[i]);
		}
		printf("\n");
		for(int i=0;i<=1000;i++)d[i]=0;
	}
	return 0;
}

