#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;
vector<ll> sums={};

int gif(float n){
    return (n/1);
}

int lif(float n){
    if(n-gif(n)==0.0){
        return (n);
    }
    return ((n/1)+1);
}

int countNegative(vector<ll> v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            count++;
        }
    }
    return count;
}

bool containZero(vector<ll> v){
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            return true;
        }
    }
    return false;
}

vector<ll> findDivisors(ll n) {
    vector<ll> divisors1={};
    vector<ll> divisors2={};
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors1.push_back(i);
            if (i != n / i) {
                divisors2.push_back(n / i);
            }
        }
    }
    for(ll i=divisors2.size()-1;i>=0;i--){
        divisors1.push_back(divisors2[i]);
    }
    return divisors1;
}

void displayVector(vector<ll> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll binarySearch(vector<ll> v, ll target,ll start, ll end){
    if(end-start==0){
        return start;
    }
    ll index = (start+end)/2;
    if(v[index]==target){
        return index;
    }
    else if(v[index]<target){
        return binarySearch(v,target,index+1,end);
    }
    else{
        return binarySearch(v,target,start,index-1);
    }
}


bool compareAbsolute(int a, int b) {
    return abs(a)<=abs(b);
}

ll vectorSum(vector<ll> v){
    ll s=0;
    for(ll i=0;i<v.size();i++){
        s+=v[i];
    }
    return s;
}

ll function1 (vector<ll> v){
//    cout<<'h';

    ll mn=*min_element(v.begin(),v.end());
    ll mx=*max_element(v.begin(),v.end());
    if(mx==mn){
        ll vsum1=v[0]*v.size();
        sums.push_back(vsum1);
        return vsum1;
    }
    ll md=(mn+mx)/2;

    vector<ll> vleft={};
    vector<ll> vright={};

    for(int i=0;i<v.size();i++){
        if(v[i]<=md){
            vleft.push_back(v[i]);
        }
        else{
            vright.push_back(v[i]);
        }
    }

    ll ans=function1(vleft)+function1(vright);
    sums.push_back(ans);

    return ans;
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> v1;
    vector<ll> v2;
    for(ll i=0;i<n;i++) {
        ll tem;
        cin >> tem;
        v1.push_back(tem);
    }
    for(int i=0;i<q;i++){
        ll tem;
        cin >> tem;
        v2.push_back(tem);
    }

    function1(v1);

//    for(int i=0;i<sums.size();i++){
//        cout<<sums[i]<<' ';
//    }
//    cout<<endl;

    std::sort(sums.begin(), sums.end());
    ll sumsSize=sums.size();
    for(int i=0;i<q;i++){
        if(binary_search(sums.begin(),sums.end(),v2[i])){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int main() {
    int t=1;
    cin >> t;
    while(t--) {
        sums={};
        solve();
    }
    return 0;
}
