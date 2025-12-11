#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],b[N],sum;
multiset<int> s;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        sum=0;
        for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        sort(a+1,a+n+1);
        s.clear();
        for(int i=1;i<=n;i++)cin>>b[i],sum+=b[i],s.insert(b[i]);
        s.insert(m);
        for(int i=n;i>=1;i--){
            set<int>::iterator it=s.lower_bound(m-a[i]);
            if(*it==m)continue;
            s.erase(it),sum-=m;
        }
        printf("%lld\n",sum);
    }
    return 0;
}


