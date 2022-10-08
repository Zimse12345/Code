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

using namespace std;
const int MAXN=5e5+5;
int T;
int p;
int n;
struct Eage{
	int From,To,Next;
}a[MAXN];
int cnt,Head[MAXN];
void addeage(int From,int To)
{
	a[++cnt].From=From;
	a[cnt].To=To;
	a[cnt].Next=Head[From];
	Head[From]=cnt;
}
int F[MAXN];
int cnt3=0;
int Anspoint[MAXN],Ansedge[MAXN]; 
void Dfs(int x,int fa,bool Check)
{
	for(int i=Head[x];i!=0;i=a[i].Next)
	{
		int too=a[i].To;
		if(too==fa)
		continue;
		F[x]=i;
		
		cnt3+=1;
		if(!Check)
		{
			Anspoint[too]=cnt3;
			Ansedge[(i+1)/2]=cnt3+n;
			Dfs(too,x,1);
		}
		else
		{
			Anspoint[too]=cnt3+n;
			Ansedge[(i+1)/2]=cnt3;
			Dfs(too,x,0);
		}
		
	}
}
int main()
{
	cin>>T;
	cnt3=0;
	for(int ii=1;ii<=T;++ii)
	{
		cin>>p;
		n=1;
		for(int i=1;i<=p;++i)
		n=n*2;
		int Front,Too;
		for(int i=1;i<n;++i)
		{
			cin>>Front>>Too;
			addeage(Front,Too);
			addeage(Too,Front);
		}
		Dfs(1,0,0);
		Anspoint[1]=n;
		cout<<1<<endl;
		for(int i=1;i<=n;++i)
		cout<<Anspoint[i]<<" ";
		cout<<endl;
		for(int i=1;i<n;++i)
		cout<<Ansedge[i]<<" ";
		cout<<endl;
		cnt=0;
		for(int i=1;i<=n;++i)
		Head[i]=0;
		cnt3=0;
	}
	return 0;
}
