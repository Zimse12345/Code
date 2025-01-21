#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(a[i]<b[i]){
                if(s==0)s=b[i]-a[i];
                else s=-1;
            }
        }
        if(s==-1){
            printf("NO\n");
            continue;
        }
        int tag=1;
        for(int i=1;i<=n;i++)if(a[i]>=b[i]){
            if(a[i]-b[i]<s)tag=0;
        }
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


