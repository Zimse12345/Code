#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,l[N],r[N],a[N],b[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[i]>>r[i];
            if(l[i]==r[i])a[l[i]]=1,++b[l[i]];
        }
        for(int i=1;i<=n*2;i++)a[i]+=a[i-1];
        for(int i=1;i<=n;i++){
            if(a[r[i]]-a[l[i]-1]!=r[i]-l[i]+1||(l[i]==r[i]&&b[l[i]]==1))printf("1");
            else printf("0");
        }
        printf("\n");
        for(int i=1;i<=n*2;i++)a[i]=b[i]=0;
    }
    return 0;
}


