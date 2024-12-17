#include <bits/stdc++.h>

/*
    二分查找 [l, r] 里，最后一个满足 func(x) = true 的位置
    func(x) = [1, 1, 1, 1, ..., 1, 0, 0, ... 0];
*/

template <std::integral T>
inline T work_last(T l, T r, const auto &&func) {
    for (r += 1; l + 1 < r;) {
        const T mid = (l + r) / 2;
        func(mid) ? l = mid : r = mid;
    }
    return l;
}

/*
    二分查找 [l, r] 里，第一个满足 func(x) = true 的位置
    func(x) = [0, 0, 0, 0, ..., 0, 1, 1, ... 1];
*/

template <std::integral T>
inline T work_first(T l, T r, const auto &&func) {
    for (l -= 1; l + 1 < r;) {
        const T mid = (l + r) / 2;
        func(mid) ? r = mid : l = mid;
    }
    return r;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 2, 2, 3};

    std::cout << '[';
    for (int i = 0; i < 6; i++) {
        std::cout << i << ":" << nums[i];
        if (i != 5) std::cout << ", ";
    }
    std::cout << "]\n";

    // 查找最后一个 <= 2 的位置
    int last_2_pos = work_last(0, 5, [&](int pos) -> bool {
        return nums[pos] <= 2;
    });
    std::cout << last_2_pos << ": " << nums[last_2_pos] << '\n';

    // 查找第一个 > 1 的位置
    int first_2_pos = work_first(0, 5, [&](int pos) -> bool {
        return nums[pos] > 1;
    });
    std::cout << first_2_pos << ": " << nums[first_2_pos] << '\n';

    return 0;
}