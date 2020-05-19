#include<iostream>
//#include<set>
#include<vector>
#include<algorithm>
//#include<iterator>
//#include<cmath>
#include<string.h>
//#include<queue>
//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf (ll)1e9
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
#define sd(a) scanf("%d",&(a))
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
#define BIG 100003

struct box{
int ind;
ll val;
};
void pri(int x)
{        cout<<(x)<<" ";

}


int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    int n,i;
    cin>>n;
    int a[n],b[n];
    ll dp[2];
    For(i,0,n){
        cin>>a[i];
    }
    For(i,0,n){
        cin>>b[i];
    }
    dp[0]=0;
    dp[1]=0;
    ll temp;
    For(i,1,n+1){
        temp=dp[0];
        dp[0]=max(dp[0],dp[1]+a[i-1]);
        dp[1]=max(dp[1],temp+b[i-1]);
    }
    cout<<max(dp[0],dp[1])<<"\n";
    return 0;
}
