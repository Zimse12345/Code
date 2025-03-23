#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,l,r,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>l>>r;
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(l<=i&&i<=r)s+=a[i];
        }
        sort(a+1,a+l);
        sort(a+l,a+r+1);
        sort(a+r+1,a+n+1);
        
        int x=0,y=0;
        int p=r,q=1;
        while(p>=l&&q<l&&a[p]>a[q]){
            x+=a[p]-a[q];
            --p,++q; 
        }
        p=r,q=r+1;
        while(p>=l&&q<=n&&a[p]>a[q]){
            y+=a[p]-a[q];
            --p,++q;
        }
        printf("%lld\n",s-max(x,y));
    }
    return 0;
}


