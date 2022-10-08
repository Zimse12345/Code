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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,sg[N];
char s[N]; 

signed main(){
	T=read();
	for(int i=1;i<200;i++){
		set<int> S;
		for(int j=1;j<i;j++){
			S.insert(sg[j-1]^sg[i-j-1]);
		}
		while(S.find(sg[i])!=S.end())++sg[i];
	}
	while(T--){
		n=read();
		scanf("%s",s+1);
		int R=0,B=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='R')++R;
			else ++B;
		}
		if(R>B)printf("Alice\n");
		else if(R<B)printf("Bob\n");
		else{
			int SG=0,k=0;
			for(int i=1;i<=n;i++){
				if(s[i]!=s[i-1])++k;
				else{
					while(k>=200)k-=34;
					SG^=sg[k],k=1;
				}
			}
			while(k>=200)k-=34;
			SG^=sg[k];
			if(SG)printf("Alice\n");
			else printf("Bob\n");
		}
	}
	return 0;
}

