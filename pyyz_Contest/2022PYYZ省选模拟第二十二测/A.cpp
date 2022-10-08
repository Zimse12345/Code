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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],c,cc;

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i&1)c^=a[i];
		else{
			a[i]%=(i+1);
			if(a[i]<i)c^=a[i];
			else{
				cc^=1;
				continue;
			}
		}
	}
	c&=1;
	c|=cc;
	if(c)printf("tomato fish+1s\n");
	else printf("rainy day+1s\n");
	return 0;
}

