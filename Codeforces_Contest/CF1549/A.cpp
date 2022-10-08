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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<=1000;i++)a[i]=0;
		for(int i=2;i<=n;i++){
			int p=n%i;
			if(a[p]){
				printf("%d %d\n",a[p],i);
				break;
			}
			a[p]=i;
		}
	}
	return 0;
}

