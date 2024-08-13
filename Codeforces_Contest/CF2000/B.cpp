#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int L=a[1],R=a[1],tag=1;
        for(int i=2;i<=n;i++){
            if(a[i]==L-1)--L;
            else if(a[i]==R+1)++R;
            else tag=0;
        }
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


