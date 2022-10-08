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
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		
		int sum=0;
		for(int i=1;i<n;i++)sum+=a[i];
		double ans=double(sum)/double(n-1)+double(a[n]);
		printf("%.7f\n",ans);
	}
	return 0;
}

