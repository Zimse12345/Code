#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <iostream>
#include <cstring>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
char s[N];
int p[N];

void solve(){
    scanf("%s",s+1);
    int x=0;
    for(int i=1;i<=26;i++)p[s[i]-'A']=i;
    for(int i=0;i+1<26;i++){
        if(p[i]<p[i+1])x+=p[i+1]-p[i];
        else x+=p[i]-p[i+1];
    }
    printf("%d\n",x);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
