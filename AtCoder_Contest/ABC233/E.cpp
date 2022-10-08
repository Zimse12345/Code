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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N];
char s[N];

signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)a[i]=s[n-i+1]-'0';
	for(int i=n;i>=1;i--)a[i]+=a[i+1];
	int p=0;
	for(int i=1;i<=n;i++)a[i]+=p,p=a[i]/10,a[i]%=10;
	while(p)a[++n]=p%10,p/=10;
	for(int i=n;i>=1;i--)printf("%lld",a[i]);
	printf("\n");
	return 0;
}

