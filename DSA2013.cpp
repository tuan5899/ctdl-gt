#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
bool ok[300];
int b[405] = {0};
int n, p, s, vt;
vector<int>a;
vector<vector<int> >kq;

void sangNT(){
     b[0] = 1, b[1] = 1;
     for(int i = 2; i <= 20; i ++){
         for(int j = i * i; j <= 400; j+= i){
             if(b[i] == 0){
                 b[j] = 1;
             }
         }
     }
     for(int i = 2; i <= 200; i++){
         if(b[i] == 0)a.push_back(i);
     }
 }

 void init(){
     cin >> n >> p >> s;
     vt = lower_bound(a.begin(), a.end(), p) - a.begin() + 1;
     for (int i = 0; i < 300; i++) ok[i] = false;
     kq.clear();
 }

 void Try(int i, vector<int>v, int sum) {
     if (sum > s) return;
     if (sum == s && v.size() == n) {
         kq.push_back(v);
         return;
     }
     for (int j = i; j < a.size(); j++) {
         if (ok[j] == false && sum + a[j] <= s && v.size() < n) {
             v.push_back(a[j]);
             sum += a[j];
             ok[j] = true;
             Try(j + 1, v, sum);
             v.pop_back();
             sum -= a[j];
             ok[j] = false;
         }
     }
 }

int main(){
    int t;
    cin >> t;
    sangNT();
    while(t--){
        init();
        vector<int> v; v.clear();
        Try(vt, v, 0);
        cout << kq.size() << endl;
        for (int i = 0; i < kq.size(); i++) {
            for (int j = 0; j < kq[i].size(); j++) {
                cout << kq[i][j] << " ";
            }
            cout << endl;
        }
    }
}