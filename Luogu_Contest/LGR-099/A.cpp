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
int n,len[N],a[N];
vector< vector<char> > s;
vector<char> emp;

signed main(){
	n=read();
	s.push_back(emp);
	for(int i=1;i<=n;i++){
		s.push_back(emp);
		char c=getchar();
		while(c!='0'&&c!='1')c=getchar();
		while(c=='0'||c=='1')s[i].push_back(c),c=getchar(); 
	}
	
	int p=0,ans1=0,ans2=0;
	while(1){
		int tag=1,c=0;
		for(int i=1;i<=n;i++){
			while(a[i]<signed(s[i].size())&&s[i][a[i]]=='0'+p)++a[i],++c;
			if(a[i]<signed(s[i].size()))tag=0;
		}
		ans1+=c-1;
		if(tag)break;
		p^=1;
	}
	p=1;
	for(int i=1;i<=n;i++)a[i]=0;
	while(1){
		int tag=1,c=0;
		for(int i=1;i<=n;i++){
			while(a[i]<signed(s[i].size())&&s[i][a[i]]=='0'+p)++a[i],++c;
			if(a[i]<signed(s[i].size()))tag=0;
		}
		ans2+=c-1;
		if(tag)break;
		p^=1;
	}
	printf("%d\n",max(ans1,ans2));
	return 0;
}

