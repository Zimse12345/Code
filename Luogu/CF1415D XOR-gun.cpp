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

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=2e5+7,Mod=998244353,INF=2e9+7;
int n,a[N],x[N],ans=INF;

signed main(){
	n=read(),a[n+1]=INF;
	if(n>70){
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read(),x[i]=x[i-1]^a[i];
	for(int L=1;L<=n;L++){
		for(int M=L;M<=n;M++){
			for(int R=M+1;R<=n;R++){
				if((x[M]^x[L-1])>(x[R]^x[M]))ans=min(ans,M-L+R-M-1);
			}
		}
	}
	if(ans>=INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}

