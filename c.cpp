#include <vector>
#include <iostream>

#define ull unsigned long long

template<typename T>
void swap(T &x, T &y) {
  T t = x;
  x = y;
  y = t;
}

ull count(int n, std::vector<int> &bad) {
  int i = 0, j = 0;
  ull c = 0;
  for(; j < n; ++j) {
    if(bad[j] >= i) {
      int new_i = bad[j] + 1;
      ull delta_c = (j - i + 1)*(j - i)/2 - (j - new_i + 1)*(j - new_i)/2;
      c += delta_c;
      // std::cout << "(" << i << ", " << new_i - 1 << "): " << delta_c << std::endl;
      i = new_i;
    }
  }
  j -= 1;
  ull delta_c = (j - i + 2)*(j - i + 1)/2;
  c += delta_c;
//  std::cout << "(" << i << ", " << j << "): " << delta_c << std::endl;
  return c;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> perm(n);
  std::vector<int> invp(n);
  std::vector<int> bads(n);
  for(int i = 0; i < n; ++i) bads[i] = -1;

  for(int i = 0; i < n; ++i) {
    std::cin >> perm[i];
    --perm[i];
  }
  for(int i = 0; i < n; ++i) invp[perm[i]] = i;
  for(int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    int i_a = invp[a];
    int i_b = invp[b];
    if (i_b < i_a) swap(i_a, i_b);
    if (bads[i_b] == -1 || bads[i_b] < i_a) bads[i_b] = i_a;
  }
  std::cout << count(n, bads);
  return 0;
}
