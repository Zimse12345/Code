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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,a[N],L=1,R;
priority_queue<int> Q;

int main(){
	T=read();
	while(T--){
		int ty=read();
		if(ty==1)a[++R]=read();
		if(ty==2){
			if(!Q.empty())printf("%d\n",-Q.top()),Q.pop();
			else printf("%d\n",a[L]),++L;
		}
		if(ty==3){
			for(int i=L;i<=R;i++)Q.push(-a[i]);
			L=R+1;
		}
	}
	return 0;
}
