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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,ans;

signed main(){
	n=read();
	int j=0,p=0;
	for(int i=1;i*i<=n;i++)ans=(i+ans)%Mod,j=max(j,i);
//	int M=j;
//	for(int i=j+1;i<=n;i++){
//		int k=i*i;
//		while(k-L*L>n)++L;
//		if(k-L*L>=1)ans=(ans+i-L)%Mod;
//		
//		else break;
//	}
	
	p=j;
	for(int d=j-1;d>=1;d--){
		int R=(n+d*d)/(2*d);
		ans=(ans+(R-p)*d)%Mod;
		p=R;
	}
	
	if(n==3)++ans;
	printf("%lld\n",ans);
	return 0;
}

