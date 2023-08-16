#include <bits/stdc++.h>
using namespace std;

int n,c;
vector<pair<int,int>> v;
map <int,int> counting,order;

bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){
		return order[a.second] < order[b.second];
	}
	return a.first > b.first;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>c;
    int temp;
    for(int i=0; i<n;++i){
        cin>>temp;
        counting[temp]++;
        if(!order[temp]) order[temp]=i+1;
    }

    for(auto it : counting){ //{카운팅, 원소값}
		v.push_back({it.second, it.first});
	}
    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j=0; j<i.first; ++j){
            cout<<i.second<<' ';
        }
    }
    cout << '\n';
    return 0;
}
