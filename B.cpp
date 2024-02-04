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

//ll vectorSum(vector<ll> v){
//    ll sum=0;
//    for(int i=0;i<v.size();i++){
//        sum+=v[i];
//    }
//}

//vector<ll> checkSubsequence(ll size,vector<ll> v,ll target){
//    vector<ll> v1={};
//    ll currentSum=0;
//    for(ll i=0;i<size;i++){
//        currentSum=v[i];
//        for(ll j=i+1;j<size;j++){
////            cout<<currentSum<<endl;
//            if(currentSum%target==0){
////                cout<<'h';
//                v1.push_back(i);
//                v1.push_back(j);
//            }
//            currentSum+=v[j];
//        }
//    }
//    return v1;
//}

void solve() {
    ll n,b;
    cin>>n>>b;
    vector<vector<ll>> v1;
    vector<vector<ll>> v2;
    ll tem;
    for(int i=0;i<n;i++){
        cin>>tem;
        v1.push_back({tem,i});
    }
    for(int i=0;i<b;i++){
        ll a,b;
        cin>>a>>b;
        vector<ll> temp={a,b};
        v2.push_back(temp);
    }
    std::sort(v2.begin(), v2.end());
    std::sort(v1.begin(), v1.end());

    ll sum=0;
    ll index1=0;
    ll index2=0;
    while(index1<n){
        if(index2>=b){
            v1[index1].push_back(sum);
            index1++;
            continue;
        }
        while(v1[index1][0]>=v2[index2][0]){
            sum+=v2[index2][1];
            index2++;
            if(index2==b){
                break;
            }
        }

        v1[index1].push_back(sum);
        index1++;
    }

    for(int i=0;i<n;i++){
        v1[i].erase(v1[i].begin());
    }
    std::sort(v1.begin(), v1.end());
    for(int i=0;i<n;i++){
        cout<<v1[i][1]<<' ';
    }
}

int main() {
    int t=1;
//    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
