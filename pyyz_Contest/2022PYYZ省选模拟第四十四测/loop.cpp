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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,ans[N];
char s[N];

signed main(){
	while(cin>>(s+1)){
		n=strlen(s+1);
		for(int i=n;i>0;i--)ans[i]=0;
		for(int i=1;i<=n;i++)s[i+n]=s[i];
		for(int i=1;i<=n*2;i++){
			for(int j=i;j<=n*2;j++){
				if(j-i+1>n)break;
				if(i==j||s[i]!=s[j])ans[j-i+1]=1;
				if(s[j]==s[j+1])break;
			}
		}
		ans[1]=0;
		for(int i=n;i>0;i--)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}

