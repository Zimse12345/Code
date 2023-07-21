#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

inline void _max(int &x,int y){
    if(y>x)x=y;
    return;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		printf("%lld\n",a[1]);
		return;
	}
	int ans1=-1e18,ans2=-1e18;
	for(int i=1;i<=n;i++){
		if(i&1)_max(ans1,max(a[i],ans1+a[i]));
		else _max(ans2,max(a[i],ans2+a[i]));
	}
	printf("%lld\n",max(ans1,ans2));
	return;
}

signed main(){
    cin>>T;
    while(T--)solve();
    return 0;
}

