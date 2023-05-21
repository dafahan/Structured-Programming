#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

vector<cpp_int> dp(105, -1);

cpp_int fibDP(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return dp[n] = 0;
    if (n == 1 || n == 2) return dp[n] = 1;
    return dp[n] = fibDP(n - 1) + dp[n - 2]; 
}

cpp_int fib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

void solve(){
    vector<int>valSeq = {10,20,30,40,70,100};
    cout<<"DENGAN DP\n";
    for(int soal = 0; soal<valSeq.size() ;soal++){
        clock_t start = clock();  
    
        cpp_int result = fibDP(valSeq[soal]);
        
        clock_t end = clock();  
    
        double duration = double(end - start);
        cout <<"Fibonacci ke-"<<valSeq[soal]<<" : "<<result<< ",Running time: " << duration << " ms" << endl;
        clock_t reset = clock();
        
    }
    cout<<"\nTANPA DP\n";
    for(int soal = 0; soal<valSeq.size() ;soal++){
        clock_t start = clock();  
    
        cpp_int result = fib(valSeq[soal]);
        
        clock_t end = clock();  
    
        double duration = double(end - start);
        cout <<"Fibonacci ke-"<<valSeq[soal]<<" : "<<result<< ",Running time: " << duration << " ms" << endl;
        clock_t reset = clock();
        
    }
}

int main() {
    solve();
    return 0;
}