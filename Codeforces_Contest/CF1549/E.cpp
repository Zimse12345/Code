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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
int n,q;

int C(int a,int b){
	int res=1;
	for(int i=a-b+1;i<=a;i++)res*=i;
	for(int i=1;i<=b;i++)res/=i;
	return res;
}

int main(){
	n=read(),q=read();
	while(q--){
		int x=read(),ans=0;
		for(int i=1;i<=n;i++)if(i*3>=x)ans=(ans+C(i*3,x))%Mod;
		printf("%d\n",ans);
	}
	return 0;
}

