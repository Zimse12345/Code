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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,ans;
set<int> s1,s2;

int main(){
	n=read();
	for(int i=1,len;i<=n;i++){
		len=read();
		int h1=len,h2=-len;
		for(int j=1,v;j<=len;j++){
			v=read();
			h1=h1*Mod+v*7;
			h2=h2*INF+v*11;
		}
		if(s1.count(h1)&&s2.count(h2))continue;
		++ans,s1.insert(h1),s2.insert(h2);
	}
	printf("%d\n",ans);
	return 0;
}
