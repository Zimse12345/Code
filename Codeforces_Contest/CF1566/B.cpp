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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int i=1;
		int p=1;
		for(int i=1;i<=n;i++)if(s[i]=='0')p=0;
		if(p){
			printf("0\n");
			continue;
		}
		while(i<=n&&s[i]=='1')++i;
		while(i<=n&&s[i]=='0')++i;
		int y=1;
		for(int j=i;j<=n;j++)if(s[j]=='0'){
			y=0;
			printf("2\n");
			break;
		}
		if(y)printf("1\n");
	}
	return 0;
}
