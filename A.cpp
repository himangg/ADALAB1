#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

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

bool inTheGeneratedSubsequences(int size, const vector<int>& v,int target , int rem) {
    for (int subsetMask = 0; subsetMask < (1 << size); subsetMask++){
        int sumt=0;
        bool flag=false;
        for (int i = 0; i < size; i++) {
            if ((subsetMask & (1 << i)) && rem != i) {
                flag=true;
                sumt+=v[i];
            }
        }
        if (flag && (sumt%target)==0) {
            return true;
        }
    }
    return false;
}


void solve() {
    int m,n;
    cin>>m>>n;

    vector<int> v;
    int tem;
    for(int i=0;i<m;i++){
        cin>>tem;
        v.push_back(tem);
    }

    if(m==1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<m;i++){
        bool ans = inTheGeneratedSubsequences(m,v,n , i);
        if(!ans){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}


int main() {
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
