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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int L,R,n;
char s[N],t[N];

signed main(){
	L=read(),R=read(),scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)t[i]=s[i];
	for(int i=L;i<=R;i++)t[i]=s[R-i+L];
	t[n+1]='\0';
	printf("%s",t+1);
	return 0;
}

