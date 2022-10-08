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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N],t[N];
deque<int> a,b,c;

bool ck(){
	for(int i=1;i<=n;i++){
		if(t[i]=='a'){
			if(!a.empty()&&(b.empty()||a.front()<b.front())&&(c.empty()||a.front()<c.front()))a.pop_front();
			else return false;
		}
		if(t[i]=='b'){
			if(!b.empty()&&(c.empty()||b.front()<c.front()))b.pop_front();
			else return false;
		}
		if(t[i]=='c'){
			if(!c.empty()&&(a.empty()||c.front()<a.front()))c.pop_front();
			else return false;
		}
	}
	return true;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s %s",s+1,t+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='a')a.push_back(i);
			if(s[i]=='b')b.push_back(i);
			if(s[i]=='c')c.push_back(i);
		}
		if(ck())printf("YES\n");
		else printf("NO\n");
		a.clear(),b.clear(),c.clear();
	}
	return 0;
}

