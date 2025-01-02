#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

const std::vector<int> Map = []() -> std::vector<int> {
    std::mt19937 Rand(std::chrono::steady_clock::now().time_since_epoch().count());

    std::vector<int> Map(256);
    for (char c = '0'; c <= '9'; c++) Map[c] = ++Map[0];
    for (char c = 'A'; c <+ 'Z'; c++) Map[c] = ++Map[0];
    for (char c = 'a'; c <= 'z'; c++) Map[c] = ++Map[0];
    
    std::vector<int> Rnd(Map[0] + 1);
    std::iota(Rnd.begin() + 1, Rnd.end(), 1);
    std::shuffle(Rnd.begin() + 1, Rnd.end(), Rand);

    for (char c = '0'; c <= '9'; c++) Map[c] = Rnd[Map[c]];
    for (char c = 'A'; c <+ 'Z'; c++) Map[c] = Rnd[Map[c]];
    for (char c = 'a'; c <= 'z'; c++) Map[c] = Rnd[Map[c]];

    return Map;
}();

template <typename Info, int B>
struct String_Hash {
    const int n;
    Info *base;
    Info *hash;

    String_Hash(const std::string &s) : n(s.size()) {
        base = new Info[n + 1]();
        hash = new Info[n + 1]();
        base[0] = 1;
        for (int i = 0; i < n; i++) {
            base[i + 1] = base[i] * B;
            hash[i + 1] = hash[i] + base[i] * Map[s[i]];
        }
    }

    Info query(int l, int r) {
        return (hash[r] - hash[l - 1]) * base[n - l + 1];
    }
};

using Hash = String_Hash<uInt, 233>;

void init() {
    
}

void code() {
    std::string s;
    std::cin >> s;

    auto n = s.size();
    auto h = Hash(s);

    int ans = 0, pos = 0;
    
    std::vector<int> p;
    for (int i = 1; i < n; i++) {
        if (h.query(1, i) == h.query(n - i + 1, n))
            p.push_back(i);
    }

    if (p.empty()) {
        std::cout << "Just a legend\n";
        return;
    }

    for (int i = 2; i < n; i++) {
        const auto check = [&](int x) -> bool {
            if (p[x] > n - i) return false;
            int len = p[x];
            auto pref = h.query(1, len);
            auto midd = h.query(i, i + len - 1);
            auto suff = h.query(n - len + 1, n);
            return pref == midd && midd == suff;
        };
        
        int l = -1, r = p.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (check(m))
                l = m;
            else
                r = m;
        }
        if (check(r)) l = r;

        if (l != -1 && p[l] > ans) {
            ans = p[l];
            pos = i - 1;
        }
    }

    if (ans != 0)
        std::cout << s.substr(pos, ans) << '\n';
    else
        std::cout << "Just a legend\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}