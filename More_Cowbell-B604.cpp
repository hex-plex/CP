#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<string.h>
#include<deque>
//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf 1000000000
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
using namespace std;
 
 
struct box{
int b;
int a;
 
};
bool operator<(const box& a,const box& b )
{
    if(a.b!=b.b){
    return a.b<b.b;}
    else
        return a.a<b.a;
 
}
 
void pri(int x)
{        cout<<x<<" ";
 
}
 
int main()
{
    ll n,k,i,j;
    cin>>n>>k;
    ll a[n];
    For(i,0,n){
        cin>>a[i];
    }
    if(k>=n){
        cout<<a[n-1]<<"\n";
        return 0;
    }
    ll ma=0;
    For(i,0,(n-k)){
        ma=max(ma,a[i]+a[(2*(n-k))-i-1]);
    }
    cout<<max(ma,a[n-1]);
    return 0;
 
}
