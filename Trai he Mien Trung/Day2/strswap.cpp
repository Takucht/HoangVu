//                               _,add8ba,
//                             ,d888888888b,
//                            d8888888888888b                        _,ad8ba,_
//                           d888888888888888)                     ,d888888888b,
//                           I8888888888888888 _________          ,8888888888888b
//                 __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
//             ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
//          ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
//        ,a8^            ,d8888'                                     ^Y8888888P'
//       a88'           ,d8888P'                                        I88P"^
//     ,d88'           d88888P'                                          "b,
//    ,d88'           d888888'                                            `b,
//   ,d88'           d888888I                                              `b,
//   d88I           ,8888888'            ___                                `b,
//  ,888'           d8888888          ,d88888b,              ____            `b,
//  d888           ,8888888I         d88888888b,           ,d8888b,           `b
// ,8888           I8888888I        d8888888888I          ,88888888b           8,
// I8888           88888888b       d88888888888'          8888888888b          8I
// d8886           888888888       Y888888888P'           Y8888888888,        ,8b
// 88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
// Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
// `888888b         88888888888b,                           `Y8888P^        d88888
//  Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
//  I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
//  `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
//   88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
//   8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
//   88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
//   8888888888888888888888888888888888888888888baaad888888888888888888888888888'
//   Y8888888888888888888888888888888888888888888888888888888888888888888888888P
//   I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
//   `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
//    `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
//     `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
//      `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
//        "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
//          "Y88888888888P   `888888888888888888888b     d8888888888888888'
//             ^""""""""^     `Y88888888888888888888,    888888888888888P'
//                              "8888888888888888888b,   Y888888888888P^
//                               `Y888888888888888888b   `Y8888888P"^
//                                 "Y8888888888888888P     `""""^
//                                   `"YY88888888888P'
//  
#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int cnt[3][N], tot[3];

int main(){
    freopen("strswap.inp", "r", stdin);
    freopen("strswap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size(), res;
    s = ' ' + s + s; res = n;
    for (int i = 1; s[i]; i++){
        tot[s[i] - 'A']++;
        cnt[0][i] = tot[0];
        cnt[1][i] = tot[1];
        cnt[2][i] = tot[2];
    }
    tot[0] /= 2; tot[1] /= 2; tot[2] /= 2;
    for (int i = 1; i <= n; i++){
        res = min(res, tot[0] - (cnt[0][i + tot[0] - 1] - cnt[0][i - 1])
        + tot[1] - (cnt[1][i + tot[0] + tot[1] - 1] - cnt[1][i + tot[0] - 1])
        - min(cnt[0][i + tot[0] + tot[1] - 1] - cnt[0][i + tot[0] - 1],
        cnt[1][i + tot[0] - 1] - cnt[1][i - 1]));
        res = min(res, tot[0] - (cnt[0][i + tot[0] - 1] - cnt[0][i - 1])
        + tot[2] - (cnt[2][i + tot[0] + tot[2] - 1] - cnt[2][i + tot[0] - 1])
        - min(cnt[0][i + tot[0] + tot[2] - 1] - cnt[0][i + tot[0] - 1],
        cnt[2][i + tot[0] - 1] - cnt[2][i - 1]));
    }
    cout << res << '\n';
}