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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

int main(){
	T=read();
	while(T--){
		n=read();
		if(n<=26){
			for(int i=1;i<=n;i++)printf("%c",'a'+i-1);
			printf("\n");
			continue;
		}
		int v=n/2;--v,--v;
		for(int i=1;i<=v+1;i++)s[i]='a';
		for(int i=n;i>=n-v+1;i--)s[i]='a';
		char c='b';
		for(int i=v+2;i<=n-v;i++)s[i]=c,++c;
		for(int i=1;i<=n;i++)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
