#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T;

#define ll long long
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = extended_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

bool crt(ll &a1, ll &m1, ll a2, ll m2) {
    ll g = gcd(m1, m2);
    ll c = a2 - a1;
    if (c % g != 0) return false;
    ll m1_g = m1 / g;
    ll m2_g = m2 / g;
    ll c_g = c / g;
    ll inv = mod_inverse(m1_g, m2_g);
    if (inv == -1) return false;
    ll k = (c_g * inv) % m2_g;
    a1 += k * m1;
    m1 = m1 / g * m2;
    a1 = (a1 % m1 + m1) % m1;
    return true;
}

ll f(ll x, ll y, ll a, ll b, ll n) {
    // 处理第一个同余方程 a*t ≡ (n - x) mod n
    ll c1 = (n - (x % n)) % n;
    ll d1 = gcd(a, n);
    if (c1 % d1 != 0) return -1;
    ll a1 = a / d1;
    ll m1 = n / d1;
    ll c1_prime = c1 / d1;
    ll inv_a1 = mod_inverse(a1, m1);
    if (inv_a1 == -1) return -1; // 理论上不可能出现
    ll t1 = (c1_prime * inv_a1) % m1;

    // 处理第二个同余方程 b*t ≡ (n - y) mod n
    ll c2 = (n - (y % n)) % n;
    ll d2 = gcd(b, n);
    if (c2 % d2 != 0) return -1;
    ll b2 = b / d2;
    ll m2 = n / d2;
    ll c2_prime = c2 / d2;
    ll inv_b2 = mod_inverse(b2, m2);
    if (inv_b2 == -1) return -1; // 理论上不可能出现
    ll t2 = (c2_prime * inv_b2) % m2;

    // 合并两个同余式 t ≡ t1 mod m1 和 t ≡ t2 mod m2
    ll a_merged = t1;
    ll m_merged = m1;
    if (!crt(a_merged, m_merged, t2, m2)) {
        return -1;
    }
    ll t = a_merged % m_merged;
    if (t == 0) {
        t = m_merged;
    }
    return t;
}

signed main(){
    cin>>T;
    while(T--){
        int n,x,y,vx,vy;
        cin>>n>>x>>y>>vx>>vy;
        int g=gcd(vx,vy);
        vx/=g,vy/=g;
        int t=f(x,y,vx,vy,n);
        if(t==-1){
            printf("-1\n");
            continue;
        }
        int s=(x+vx*t)/n-1+(y+vy*t)/n-1;
        s+=(x+y+(vx+vy)*t+n)/(n*2);
        int v=x-y+vx*t-vy*t;
        if(v<0)v=-v;
        s+=(v+n)/(n*2);
        if((x+vx*t+y+vy*t)%(2*n)==n)s-=2;
        printf("%lld\n",s); 
    }
    return 0;
}


