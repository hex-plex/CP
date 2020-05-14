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
#define inf 1000000000
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
#define BIG 100003

void pri(int x)
{        cout<<(x)<<" ";

}



int main(){
    IOS;
    int n,i;
    cin>>n;
    int a[n],pos[n+1];
    char ans[n+1];
    ans[n]='\0';
    For(i,0,n){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(i=n;i>0;i--)
    {
        int init = pos[i];
        ans[init]='B';
        for(int j = (init%a[init]) ; j<n;j+=a[init]){
            if(a[j]>a[init]&&ans[j]=='B'){
                ans[init]='A';
            }
        }

    }
    cout<<ans;
    return 0;
}
