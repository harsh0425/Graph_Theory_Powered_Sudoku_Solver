#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
int t;
cin>>t;

while(t--){
    int n,m;// n- months & m- money each month
    cin>>n >>m;
    vector <int> arr(n);
    for (int i=0;i<n;i++)
        {
        cin>>arr[i];
        }
    priority_queue<int>pq;
    int mon=0;
    int hap=0;
    for(int i=0;i<n;i++)
        {

         if  (arr[i] <= mon)
            {
            mon -= arr[i];
            pq.push(arr[i]);
            hap++;
            }

        else if  (!pq.empty() && pq.top()>arr[i])
            {
            mon+=pq.top();
            pq.pop();
            mon-=arr[i];
            pq.push(arr[i]);
            }
            mon+=m;
        }
cout<<hap<<'\n';

}






return 0;}
