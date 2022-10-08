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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,d,ans[N];

inline void write(int x)
{
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9) 
		write(x/10);
    putchar(x%10+'0');
}

int main(){
	n=read(),d=read();
	int t=(n+1)/2;
	if(n*2-t<=d){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=t;i++)ans[i]=ans[n*2-t+i]=i*2-1;
	int l=t+1;
	t=n/2;
	for(int i=1;i<=t;i++){
		ans[l]=ans[l+1]=i*2;
		l+=2;
	}
	
	for(int i=1;i<=n*2;i++)write(ans[i]),putchar(' ');
	printf("\n");
	return 0;
}
