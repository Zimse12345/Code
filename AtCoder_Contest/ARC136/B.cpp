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

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N];

void f(int t){
	int T=a[t];a[t]=a[t-1],a[t-1]=a[t-2],a[t-2]=T;
	return;
}

signed main(){
	srand(time(0));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i+1<n;i++){
		int t=0;
		for(int j=i;j<=n;j++)if(a[j]==b[i]){t=j;break;}
		if(!t){
			printf("No\n");
			return 0;
		}
		while(t-2>=i)f(t),t-=2;
		if(t!=i)f(t+1),f(t+1);
	}
	if((a[n]==b[n]&&a[n-1]==b[n-1])||(a[n]==a[n-1])||(a[n-1]==a[n-2])){printf("Yes\n");return 0;}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if((j-i)%2==1&&a[i]==a[j]){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

