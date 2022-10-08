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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2*n;i++){
			if(i%2)s[i]='(';
			else s[i]=')';
		}s[n*2+1]='\0';
		printf("%s\n",s+1);
		for(int i=1;i<n;i++){
			int a=i*2,b=i*2+1;
			s[a]='(',s[b]=')';
			printf("%s\n",s+1);
			s[a]=')',s[b]='(';
		}
	}
	return 0;
}

