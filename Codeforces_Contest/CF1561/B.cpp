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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,a,b,f[N];

int main(){
	T=read();
	while(T--){
		a=read(),b=read();
		int n=a+b;
		for(int i=0;i<=a;i++){
			if(i>(n+1)/2)break;
			int bb=n/2-a+i;
			if(bb<=b&&bb>=0&&bb+i>=0)f[bb+i]=1;
		}
		if(n%2==1)for(int i=0;i<=a;i++){
			if(i>n/2)break;
			int bb=(n+1)/2-a+i;
			if(bb<=b&&bb>=0&&bb+i>=0)f[bb+i]=1;
		}
		
		int cnt=0;
		for(int i=0;i<=a+b;i++)cnt+=f[i];
		printf("%d\n",cnt);
		for(int i=0;i<=a+b;i++)if(f[i])printf("%d ",i),f[i]=0;
		printf("\n");
	}
	return 0;
}
