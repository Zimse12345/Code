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
int T,x,y,ans;

int sol(int x,int y){
	x=abs(x),y=abs(y);
	if(x>y)swap(x,y);
	if(x==y){
		if(x==0)ans=0;
		else if(x==1)ans=2;
		else if(x==2)ans=4;
		else if(x==3)ans=2;
		else ans=(x-1)/3*2+2;
	}
	else if(y>=2*x+2){
		int k=y-2*x-2;
		ans=2*(k/4)+2+(k&1)+x;
	}
	else{
		if(y==1)ans=3;
		else{
			int k=x-y/2;
			if(y&1)ans=1-((k+1)/3)*2+x;
			else ans=-(k/3)*2+x;
		}
	}
	return ans;
}

signed main(){
	T=read();
	while(T--)printf("%lld\n",sol(read(),read()));
	return 0;
}

