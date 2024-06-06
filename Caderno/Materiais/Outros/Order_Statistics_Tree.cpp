// Estrutura para achar o 'i' menor elemento -> find_by_order(i); 0 based
// tambem acha a posicao do elemento 'e' se o vetor estivesse ordenado
// mudando a logica pode encontrar o 'i' maior elemento (n-i-1)
#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h> // pbds

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ost;

int main() {
    int n = 9;
    int A[] = { 2, 4, 7,10,15,23,50,65,71};
    ost tree;
    for (int i = 0; i < n; ++i) 
        tree.insert(A[i]);
    // O(log n) select
    cout << *tree.find_by_order(0) << "\n"; // 1-smallest = 2
    cout << *tree.find_by_order(n-1) << "\n"; // 9-smallest = 71
    cout << *tree.find_by_order(4) << "\n"; // 5-smallest = 15
    // O(log n) rank
    cout << tree.order_of_key(2) << "\n"; // index 0 (rank 1)
    cout << tree.order_of_key(71) << "\n"; // index 8 (rank 9)
    cout << tree.order_of_key(15) << "\n"; // index 4 (rank 5)
    return 0;
}