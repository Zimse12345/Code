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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
struct opt{int a,b,c,d;opt(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){};};
vector<opt> ans;
int T,n,m;
char s[N][N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),ans.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=m;j>1;j--)if(s[i][j]=='1'){
				ans.push_back(opt(i,j-1,i,j));
			}
		}
		for(int i=n;i>1;i--)if(s[i][1]=='1'){
			ans.push_back(opt(i-1,1,i,1));
		}
		if(s[1][1]=='1'){
			printf("-1\n");
			continue;
		}
		else{
			printf("%d\n",signed(ans.size()));
			for(unsigned i=0;i<ans.size();i++)printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
		}
	}
	return 0;
}

