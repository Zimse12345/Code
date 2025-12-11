#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,a[N]; 

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m-=a[i];
    }
    if(m>=0)printf("Yes\n");
    else printf("No\n");
    return 0;
}


