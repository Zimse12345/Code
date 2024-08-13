#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];
char s[N];

int query(int L,int R){
    if(!(L<R))return 0;
    while(L<R&&s[L]!='L')++L;
    while(L<R&&s[R]!='R')--R;
    if(s[L]=='L'&&s[R]=='R')return a[R]-a[L-1]+query(L+1,R-1);
    return 0;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
        scanf("%s",s+1);
        printf("%lld\n",query(1,n));
    }
    return 0;
}


