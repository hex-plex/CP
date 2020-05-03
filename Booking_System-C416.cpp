#include<iostream>
//#include<set>
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
 
 
struct box{
int c;
int p;
int ind;
};
bool operator<(const box& a,const box& b )
{
    return a.p > b.p;
 
}
 
void pri(pair<int,int> x)
{        cout<<x.first<<" "<<x.second<<"\n";
 
}
 
int main()
{
    int n, i ,ans;
    cin>>n;
    box cus[n];
 
    For(i,0,n){
        cin>>cus[i].c>>cus[i].p;
        cus[i].ind=(i+1);
    }
    int k;
    cin>>k;
    vector <pair<int,int> > r(k);
    int tak[k];
    memset(tak,0,k*sizeof(tak[0]));
    For(i,0,k){
        cin>>r[i].first;
        r[i].second=(i+1);
    }
    sort(cus,cus+n);
    //for_each(all(r),pri);
    //cout<<"\n";
    sort(all(r));
 
    vector<pair<int,int> > ind;
    ll sum=0;
    int mi,lo,hi;
    For(i,0,n){
        ans=-1;
        if(r.size()==0){
            break;
        }
        lo=0;hi=(r.size()-1);
        while(lo<=hi){
            mi=((lo+hi)/2);
            if(mi<0 || mi>=r.size()){
                    break;
            }
            if(r[mi].first==(cus[i].c)){
                ans=mi;
                break;
            }
            else if(r[mi].first>(cus[i].c)){
                ans=mi;
                hi=mi-1;
            }
            else{
 
                lo=mi+1;
            }
        }
        if(ans!=-1){
            ind.pb(make_pair(cus[i].ind,r[ans].second));
            sum+=cus[i].p;
            r.erase(r.begin()+ans);
        }
 
 
    }
    cout<<ind.size()<<" "<<sum<<"\n";
    for_each(all(ind),pri);
    return 0;
 
}
