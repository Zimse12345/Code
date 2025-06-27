#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,k[N];
vector<int> a[N];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1,x;j<=k[i];j++){
            cin>>x;
            a[x].push_back(i);
        }
    }
    int ans=0;
    while(n--){
        int x=0;
        cin>>x;
        for(unsigned i=0;i<a[x].size();i++){
            --k[a[x][i]];
            if(!k[a[x][i]])++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


