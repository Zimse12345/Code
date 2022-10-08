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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,d[N],c;
char s[N];

signed main(){
	n=read(),m=read();
	for(int i=1,x;i<=m;i++){
		scanf("%s",s),x=0;
		for(int j=0;j<n;j++)if(s[j]=='O')x|=(1ll<<j);
		for(int j=n;j>=0;j--){
			if(x&(1ll<<j)){
				if(!d[j]){
					d[j]=x,++c;
					break;
				}
				x^=d[j];
			}
		}
	}
	printf("%lld\n",(1ll<<c)%2008);
	return 0;
}

