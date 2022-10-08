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
int n,k,a,m,t[N];
set<int> s;

int main(){
	n=read(),k=read(),a=read(),m=read();
	t[0]=t[n+1]=1,s.insert(0),s.insert(n+1);
	int p=(n+1)/(a+1);
	for(int i=1,x;i<=m;i++){
		x=read();
		if(t[x]++)continue;
		set<int>::iterator it=s.upper_bound(x);
		int R=*it;--it;int L=*it;
		p-=(R-L)/(a+1),p+=(R-x)/(a+1)+(x-L)/(a+1);
		s.insert(x);
		if(p<k){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
