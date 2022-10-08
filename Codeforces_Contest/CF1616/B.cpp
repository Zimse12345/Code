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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int tag=1;
		for(int i=2;i<=n;i++)if(s[i]!=s[i-1])tag=0;
		if(tag||s[1]==s[2]){
			printf("%c%c\n",s[1],s[1]);
			continue;
		}
		tag=1;
		for(int i=2;i<=n;i++){
			if(s[i]<=s[i-1])tag=i;
			else break;
		}
		for(int i=1;i<=tag;i++)printf("%c",s[i]);
		for(int i=tag;i>=1;i--)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}

