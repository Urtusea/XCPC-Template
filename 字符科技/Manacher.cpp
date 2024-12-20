#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void manacher(const std::string& s) {
    std::string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }

    int n = t.size();
    std::vector<int> p(n, 0); 
    int c = 0, r = 0;  

    for (int i = 1; i < n - 1; i++) {
        if (i < r) {
            p[i] = std::min(r - i, p[2 * c - i]); 
        }

        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    int mx = 0, idx = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > mx) {
            mx = p[i];
            idx = i;
        }
    }

    for (int i = idx - mx; i <= idx + mx; i++) {
        if (t[i] != '#') {
            std::cout << t[i];
        }
    }
}


