#include<iostream>
#include<map>
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
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
using namespace std;
 
 
struct box{
int c;
int p;
int ind;
};
bool operator<(const box& a,const box& b )
{
    return a.p > b.p;
 
}
 
void pri(int x)
{        cout<<(x)<<" ";
 
}
 
 
int main()
{
    ll m,n,i,j,k;
    cin>>n;
    ll par[n+1],res[n+1],rmv[n+1];
    For(i,1,n+1)
    {
        cin>>par[i]>>res[i];
        rmv[i]=1;
    }
 
    For(i,1,n+1)
    {
        if(res[i]==0)
        {
            rmv[i]=0;
            rmv[par[i]]=0;
        }
    }
 
    int flag=1;
 
    For(i,1,n+1)
    {
        if(rmv[i]==1)
        {
            cout<<i<<" " ;
            flag=0;
        }
    }
 
    if(flag)
        {cout<<"-1"<<endl;}
    return 0;
 
}
