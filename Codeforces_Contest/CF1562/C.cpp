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
int T,n;
char s[N];

int main(){
	T=read();
	while(T--){
		n=read();int y=0;
		scanf("%s",s+1);
		for(int i=n/2+1;i<=n;i++)if(s[i]=='0'){
			printf("%d %d %d %d\n",1,i,1,i-1),y=1;
			break;
		}
		if(!y){
			int l=n/2;
			if(s[l]=='0')printf("%d %d %d %d\n",l,n,l+1,n);
			else printf("%d %d %d %d\n",l,n-1,l+1,n);
		}
	}
	return 0;
}

