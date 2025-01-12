#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)    
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    constexpr Int INF = 1e18;
    std::unordered_map<int, Int> dis;
    min_heap<std::tuple<Int, int>> heap;

    for (int i = 1; i <= n; i++) {
        if (!dis.count(a[i])) dis[a[i]] = INF;
        if (dis[a[i]] > b[i]) {
            heap.push({dis[a[i]] = b[i], a[i]});
        }
    }

    while (!heap.empty()) {
        auto [d, u] = heap.top(); heap.pop();
        if (d != dis[u]) continue;

        for (int i = 1; i <= n; i++) {
            int g = std::gcd(a[i], u);
            if (!dis.count(g)) dis[g] = INF;
            if (dis[g] > d + b[i]) {
                heap.push({dis[g] = d + b[i], g});
            }
        }
    }

    if (!dis.count(1))
        std::cout << -1 << '\n';
    else
        std::cout << dis[1] << '\n';
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