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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,L[N],R[N],pos[N],tot,f[N][300],ans;
set<int> num;
map<int,int> _p;
vector<int> line[N];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		L[i]=read(),R[i]=read();
		num.insert(R[i]);
		if(L[i]>1)num.insert(L[i]-1);
	}
	num.insert(1),num.insert(m);
	for(set<int>::iterator it=num.begin();it!=num.end();it++)pos[++tot]=*it,_p[*it]=tot;
	for(int i=1,j;i<=n;i++){
		j=_p[R[i]];
		while(pos[j]>=L[i])line[j].push_back(i),--j;
	}
	for(int i=1,s;i<=tot;i++){
		for(unsigned z=0,_z,p;z<(1ull<<line[i].size());z++){
			_z=0,p=0;
			for(unsigned w=0;w<line[i].size();w++)if(z&(1<<w)){
				p^=1;
				for(unsigned _w=0;_w<line[i-1].size();_w++)if(line[i-1][_w]==line[i][w])_z|=(1<<_w);
			}
			f[i][z]=max(f[i][z],f[i-1][_z]+signed(p)*(pos[i]-pos[i-1]));
		}
		s=0;
		for(unsigned w=0;w<line[i].size();w++){
			s|=(1<<w);
			for(unsigned _w=0;_w<line[i+1].size();_w++)if(line[i+1][_w]==line[i][w])s^=(1<<w);
		}
		for(int z=0;z<signed(1ull<<line[i].size());z++)if(!(s&z)){
			for(int t=s;t;t=(t-1)&s)f[i][z]=max(f[i][z],f[i][z|t]);
		}
	}
	for(unsigned z=0;z<(1ull<<line[tot].size());z++)ans=max(ans,f[tot][z]);
	printf("%d\n",ans);
	return 0;
}

