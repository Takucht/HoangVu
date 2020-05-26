#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string task = "boundseq";

int main(){
    for (int i = 1; i <= 10; i++){
        stringstream ss; string name;
        ss << setw(2) << setfill('0') << i << "\n";
        ss >> name; name = "test" + name;
        ofstream inp(task + ".inp");
        int n = size_t(rng()) % 500000;
        inp << n << '\n';
        for (int i = 1; i <= n; i++)
            inp << size_t(rng()) % 100000000 << ' ';
        system(("mkdir -p " + name).c_str());
        inp.close(); system("./solution");
        system(("mv " + task + ".inp " + name).c_str());
        system(("mv " + task + ".out " + name).c_str());
    }
}