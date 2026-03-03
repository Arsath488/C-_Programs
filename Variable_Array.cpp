#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

   
    std::vector<std::vector<int>> a(n);

  
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        a[i].resize(k); 
        for (int j = 0; j < k; j++) {
            std::cin >> a[i][j];
        }
    }

    
    for (int query_count = 0; query_count < q; query_count++) {
        int i, j;
        std::cin >> i >> j;
        
        std::cout << a[i][j] << std::endl;
    }

    return 0;
}
