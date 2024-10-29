#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 3200, M = N << 1;
int n;
char s[N][N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=1;j<=(n+1)/2;j++){
            if(min(i,j)%4==0){
                continue;
            }
            if(min(i,j)%4==1){
                char t=s[i][j];
                s[i][j]=s[n-j+1][i];
                s[n-j+1][i]=s[n-i+1][n-j+1];
                s[n-i+1][n-j+1]=s[j][n-i+1];
                s[j][n-i+1]=t;
            }
            if(min(i,j)%4==2){
                swap(s[i][j],s[n-i+1][n-j+1]);
                swap(s[n-j+1][i],s[j][n-i+1]);
            }
            if(min(i,j)%4==3){
                char t=s[i][j];
                s[i][j]=s[j][n-i+1];
                s[j][n-i+1]=s[n-i+1][n-j+1];
                s[n-i+1][n-j+1]=s[n-j+1][i];
                s[n-j+1][i]=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%c",s[i][j]);
        printf("\n");
    }
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
