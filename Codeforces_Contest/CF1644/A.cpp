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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,t[N],tag;
char s[N];

signed main(){
	T=read();
	while(T--){
		tag=1;
		scanf("%s",s+1);
		for(int i=1;i<=6;i++){
			t[s[i]]=T;
			if(s[i]>='A'&&s[i]<='Z')if(T!=t[s[i]-'A'+'a'])tag=0;
		}
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

