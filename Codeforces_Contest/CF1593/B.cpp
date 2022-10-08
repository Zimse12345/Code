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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		int ans=INF,ans2=0;
		n=strlen(s+1);
		while(n>=1&&s[n]!='0')--n,++ans2;
		--n;
		if(n>=1)while(n>=1&&(s[n]!='0')&&(s[n]!='5'))--n,++ans2;
		if(n>=1)ans=ans2;
		ans2=0,n=strlen(s+1);
		while(n>=1&&s[n]!='5')--n,++ans2;
		--n;
		if(n>=1)while(n>=1&&(s[n]!='2')&&(s[n]!='7'))--n,++ans2;
		if(n>=1)ans=min(ans,ans2);
		printf("%d\n",ans);
	}
	return 0;
}
