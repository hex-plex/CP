#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<cmath>
#include<string.h>
#include<queue>
//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf (ll)4e18
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
#define BIG 100003
 
struct box{
int ma=0;
int mi=0;
};
void pri(int x)
{        cout<<(x)<<" ";
 
}
 
 
int main(){
    IOS;
    ll n,p,q,r,i,maxp1=-inf,maxp2=-inf,maxi=-inf;
    cin>>n>>p>>q>>r;
    int a[n];
    For(i,0,n){
        cin>>a[i];
        maxp1=max(maxp1,a[i]*p);
        maxp2=max(maxp2,a[i]*q + maxp1);
        maxi=max(maxi,a[i]*r + maxp2);
    }
    cout<<maxi;
    return 0;
}
