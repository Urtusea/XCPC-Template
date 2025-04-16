#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename Info>
using OrderedSet = tree<Info, null_type, std::less<Info>, rb_tree_tag, tree_order_statistics_node_update>;

/*
  insert(x);
  erase(it);
  order_of_key(x);  返回严格小于 x 的数量
  find_by_order(x); 返回排名为 x 的迭代器
*/