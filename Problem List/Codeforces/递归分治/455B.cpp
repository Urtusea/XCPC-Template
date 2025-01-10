#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int M[] = {0, 10, 26, 36, 26, 36, 52, 62};

template <int N, int M, int State>
struct Trie {
    int idx;
    int map[128];
    int nxt[N + 1][M + 2];

    constexpr Trie() {
        if constexpr (State >> 0 & 1) for (char c = '0'; c <= '9'; c++) map[c] = map[0]++;
        if constexpr (State >> 1 & 1) for (char c = 'A'; c <= 'Z'; c++) map[c] = map[0]++;
        if constexpr (State >> 2 & 1) for (char c = 'a'; c <= 'z'; c++) map[c] = map[0]++;
    }

    void clear() {
        std::memset(nxt, 0, sizeof(nxt[0]) * (idx + 1));
        idx = 0;
    }

    int get_next(int &p) {
        return p ? p : p = ++idx;
    }

    void insert(const std::string &s, int u = 0) {
        for (auto &c : s)
            nxt[u = get_next(nxt[u][map[c]])][M]++;
        nxt[u][M + 1]++;
    }

    void erase(const std::string &s, int u = 0) {
        for (auto &c : s)
            nxt[u = get_next(nxt[u][map[c]])][M]--;
        nxt[u][M + 1]--;
    }

    int count(const std::string &s, int Mode = 0, int u = 0) {
        for (auto &c : s)
            if ((u = nxt[u][map[c]]) == 0) return 0;
        return nxt[u][M + Mode];
    }
};
Trie<100000, M[0b100], 0b100> tree;

void init() {
    
}

void code() {
    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        tree.insert(s);
    }

    auto nxt = tree.nxt;

    const auto dfs1 = [&](auto &&self, int u) -> int {
        int cnt_son = 0;
        for (int i = 0; i < 26; i++) {
            cnt_son += nxt[u][i] != 0;
            if (nxt[u][i] && !self(self, nxt[u][i]))
                return 1;
        }
        if (cnt_son == 0)
            return 0;
        else
            return 0;
    };
    const auto dfs2 = [&](auto &&self, int u) -> int {
        int cnt_son = 0;
        for (int i = 0; i < 26; i++) {
            cnt_son += nxt[u][i] != 0;
            if (nxt[u][i] && !self(self, nxt[u][i]))
                return 1;
        }
        if (cnt_son == 0)
            return 1;
        else
            return 0;;
    };
    int f1 = dfs1(dfs1, 0);
    int f2 = dfs2(dfs2, 0);

    if (f1) {
        if (f2) {
            std::cout << "First\n";
        } else {
            if (k & 1) {
                std::cout << "First\n";
            } else {
                std::cout << "Second\n";
            }
        }
    } else {
        std::cout << "Second\n";
    }
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