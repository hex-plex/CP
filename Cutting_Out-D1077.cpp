#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<cmath>
#include<string.h>
//#include<deque>
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
 
 
void pri(int x)
{        cout<<x<<" ";
 
}
 
int main()
{
    int n,k,i;
    cin>>n>>k;
    map <int, int> cnt;
    int a[n];
    For(i,0,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    //for(auto it : cnt){
      //  cout<<it.first<<" "<<it.second<<"\n";
    //}
    int lo=0,hi=2e6,mi,rem,ans=0;
    vector<int> t;
    while((lo+1)<hi){
        rem=k;
        mi=(lo+hi)/2;
        t.clear();
        for(auto item: cnt){
            rem = min(item.second/mi,k-int(t.size()));
            For(i,0,rem)
            {
                t.push_back(i);
            }
        }
        if(t.size()==k){
            lo=mi;
        }
        else{
            hi=mi;
        }
    }
    t.clear();
    for(auto item: cnt){
        rem = min(item.second/hi,k-int(t.size()));
        For(i,0,rem)
        {
            t.push_back(i);
        }
    }
    if(t.size()==k){
        ans=hi;
    }
    else{ans=lo;}
    vector<int> fin;
    int flag=1;
    for(auto it = cnt.begin();flag&&it!=cnt.end();it++){
        int c = it->second/ans ;
        For(i,0,c){
            if(fin.size()>=k)
                {flag=0;break;}
            fin.pb(it->first);
        }
    }
    for_each(all(fin),pri);
    return 0;
 
}
