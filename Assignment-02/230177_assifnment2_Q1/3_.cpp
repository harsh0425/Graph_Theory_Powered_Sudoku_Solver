#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int d;
    int cure;
    int harm;
};

int change(long long x){
    int ans = 0;
    int i = 0;
    while(x){
        if(x%10) ans|=1<<i;
        i++;
        x/=10;
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        long long s;cin>>s;
        int initial = change(s);

        struct edge edges[m];
        for (int i = 0; i < m; i++){
            int d;cin>>d;
            long long cure;cin>>cure;
            long long harm;cin>>harm;
            struct edge new_edge;
            new_edge.d = d;
            new_edge.cure = change(cure);
            new_edge.harm = change(harm);
            edges[i] = new_edge;
        }

        vector<int32_t> arr(1<<(n), INT32_MAX);
        arr[initial] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({-arr[initial], initial});

        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            for (int i = 0; i < m; i++){
                int a = top.second;
                int b = a & (~edges[i].cure);
                b |= edges[i].harm;


                if(arr[b]>(-top.first + edges[i].d)){
                    arr[b] = (-top.first + edges[i].d);
                    pq.push({-arr[b], b});
                }
            }

        }
        cout<<((arr[0]==INT32_MAX)? -1: arr[0]) << endl;

    }
}



/*include<iostream>
using namespace std;

class data{
public:
    int d;
    int cure;
    int harm;

};



int main(){
int t;
cin>>t;
while (t!=0)
    {

    int nos, med;
    cin>>nos >> med ;
    string s;
    cin>>s;


   int start=0;
   for(i,0,nos)
   {
    if(s[i]=='1')
        start+=1<<i;
   }
   vector<info>edges;
   for(int i=0;i<m;i++){
    int x;
    cin >>x;
    string a,b;
    cin>> a >> b ;
    for(i,0,nos)
   {
    if(a[i]=='0')
        and+=1<<i;
    if(b[i]=='1')
      or+=1<<i;
   }

   data newedge(x,and,or);
   edges.eb(newedge);

   }

   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> pq;
   pq.push({0,start});
   d[start]=0;
   while(!pq.empty()){
    int dist, state;
    tie(dist,state)=pq.top();
    pq.pop();

    for(int i=0;i<m;i++){
        int newsta=state & edges[i].and;
        newsta=newsta | edges[i].or;

        if(d[newsta]>d[state]+edges[i].d){
            d[newsta]=d[state]+edges[i].d;
            pq.push({d[newstat},newstate});
        }

    }



   }

  cout<<((d[0]==inf)? -1: d[0]) << nl;

}






return 0;
}
*/
