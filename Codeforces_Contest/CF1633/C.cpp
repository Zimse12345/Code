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
inline void yes(){printf("YES\n");return;}
inline void no(){printf("NO\n");return;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T;

bool win(int hc,int dc,int hm,int dm){
	int nc=hm/dc,nm=hc/dm;
	if(hm%dc>0)++nc;
	if(hc%dm>0)++nm;
	if(nc<=nm)return true;
	return false;
}

signed main(){
	T=read();
	while(T--){
		int hc=read(),dc=read();
		int hm=read(),dm=read();
		int k=read(),w=read(),a=read(),tag=0;
		for(int i=0;i<=k;i++)if(win(hc+a*i,dc+w*(k-i),hm,dm)){
			tag=1;
			break;
		}
		if(tag)yes();
		else no();
	}
	return 0;
}

