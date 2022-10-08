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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m[N];
char s[N];
int S[N];
inline int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
vector<int> emp;

struct val{
	vector<int> num;
	val(vector<int> num=emp):num(num){}
	bool operator < (const val& A)const{
		unsigned p1=0,p2=0,t=0;
		while(num[p1]==A.num[p2]){
			p1=(p1+1)%num.size();
			p2=(p2+1)%A.num.size();
			if(!p1)++t;if(!p2)++t;
			if(t>=2)break;
		}
		return num[p1]>A.num[p2];
	}
};
int Sum,Tot;
vector<val> V[N],VV;

void dfs(int x){
	if(x>n){
		VV.resize(0);
		int o=0;
		for(int i=1;i<=n;i++)VV.push_back(V[i][S[i]]);
		sort(VV.begin(),VV.end());
		for(unsigned i=0;i<n;i++){
			for(unsigned j=0;j<VV[i].num.size();j++)o=(o*10+VV[i].num[j])%Mod;
		}
		Sum=(Sum+o)%Mod,++Tot;
	}
	else{
		for(int i=0;i<m[x];i++){
			S[x]=i,dfs(x+1);
		}
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		m[i]=read();
		for(int j=1,len;j<=m[i];j++){
			scanf("%s",s+1),len=strlen(s+1);
			vector<int> v;
			for(int k=1;k<=len;k++)v.push_back(s[k]-'0');
			V[i].push_back(val(v));
		}
	}
	dfs(1);
	int ans=Sum*ldl(Tot)%Mod;
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

