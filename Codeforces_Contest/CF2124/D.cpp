#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],b[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int c=0;
        for(int i=k;i<=n;i++)if(b[i]==b[k])++c;
        int ans=1,l=1,r=n;
        while(l<r){
            while(l<r&&a[l]>b[k])++l;
            while(l<r&&a[r]>b[k])--r;
            if(l>=r)break;
            if(a[l]==a[r]){
                ++l,--r;
            }
            else if(a[l]==b[k])--c,++l;
            else if(a[r]==b[k])--c,--r;
            else{
                ans=0;
                break;
            }
        }
        if(c<0)ans=0;
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


