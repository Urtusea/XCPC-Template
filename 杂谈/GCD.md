# $GCD$ - 最大公约数

1. 从 $i$ 开始的连续不同 $GCD$ 值至多 $log(a_i)$ 个
    - 因为对于每次 $GCD$ 的变化，我的该值质因子分解出来，质因子个数一定减少，而质因子个数的规模是 $log$ 个的
2. $GCD(a_i, a_j, a_k) = GCD(GCD(a_i, a_j), a_k)$
    - 本质是对质因子幂次取 $min$
    - 判断 $a_n$ 是否存在 $GCD = x$ 的子序列，只需要去把所有的 $x$ 的倍数全部 $GCD$ 起来即可