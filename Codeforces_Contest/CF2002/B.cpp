#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int L=1,R=n,tag=0;
        for(int i=1;i<n;i++){
            if(a[i]!=b[L]&&a[i]!=b[R]){
                tag=1;
                break;
            }
            if(a[i]==b[L])++L;
            else --R;
        }
        L=1,R=n;
        for(int i=n;i>1;i--){
            if(a[i]!=b[L]&&a[i]!=b[R]){
                tag=1;
                break;
            }
            if(a[i]==b[L])++L;
            else --R;
        }
        if(tag)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}


