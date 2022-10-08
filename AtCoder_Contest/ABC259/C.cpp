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
char s[N],t[N];
int n,m;

signed main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	int p=1,q=1;
	while(p<=n&&q<=m){
		if(s[p]!=t[q]){
			printf("No\n");
			return 0;
		}
		int l=1,r=1;
		while(s[p+1]==s[p])++p,++l;
		while(t[q+1]==t[q])++q,++r;
		++p,++q;
		if(l<r){
			if(l<2){
				printf("No\n");
				return 0;
			}
		}
		if(l>r){
			printf("No\n");
			return 0;
		}
	}
	if(p<=n||q<=m){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}

