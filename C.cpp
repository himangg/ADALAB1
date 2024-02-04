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


//ll isPerfect(ll size,vector<char> v, char c){
//    if(size==1 && v[0]==c){
//        return 0;
//    }
//
//    ll ans=0;
//
//    ll count1=0,count2=0;
//    //if first half contains only char
//
//    for(int i=0;i<size/2;i++){
//        if(v[i]==c){
//            count1++;
//        }
//    }
//
//    for (int i = size / 2; i < size; i++) {
//        if (v[i] != c) {
//            count2++;
//        }
//    }
//
//    if (count1>=count2){
//
//    }
//    if(flag==true){
//        vector<char> temp={};
//        for(int i=size/2;i<size;i++){
//            temp.push_back(v[i]);
//        }
//        ans+=isPerfect(size/2,temp,(char)((int)c+1));
//    }
//    else {
//        // if second half only contains char
//        flag = true;
//
//
//        if (flag == true) {
//            vector<char> temp = {};
//            for (int i = 0; i < size / 2; i++) {
//                temp.push_back(v[i]);
//            }
//            ans += isPerfect(size / 2, temp, (char) ((int) c + 1));
//        }
//    }
//
//    if (count1>count2){
//        ans+=
//    }
//    else{
//
//    }
//
//    return ans;
//}

ll function1 (vector<char> v,char c){
    if (v.size()==2){
        if((v[0]==c and v[1]==char((int)c+1)) or (v[1]==c and v[0]==char((int)c+1))){
            return 0;
        }
        else if((v[0]==c or v[1]==char((int)c+1)) or (v[1]==c or v[0]==char((int)c+1))){
            return 1;
        }
        else{
            return 2;
        }
    }

    vector<char> vleft={};
    vector<char> vright={};
    ll countLeft=0,countRight=0;

    for(int i=0;i<v.size()/2;i++){
        vleft.push_back(v[i]);
        if(v[i]==c){
            countLeft++;
        }
    }

    for(int i=v.size()/2;i<v.size();i++){
        vright.push_back(v[i]);
        if(v[i]==c){
            countRight++;
        }
    }

    ll leftC=((v.size()/2)-countRight)+function1(vleft,char((int)c+1));
    ll rightC=((v.size()/2)-countLeft)+ function1(vright,char((int)c+1));

    if(leftC>=rightC){
        return rightC;
    }
    else{
        return leftC;
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<char> v;
    for(int i=0;i<n;i++) {
        char tem;
        cin >> tem;
        v.push_back(tem);
    }
    if(n==1){
        if(v[0]=='a'){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
        return;
    }
    ll ans = function1(v, 'a');
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
