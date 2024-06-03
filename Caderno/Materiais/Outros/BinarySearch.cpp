int BinarySearch(vector<int> &arr, int x){
    int k = 0;
    int n = arr.size();

    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && arr[k+b] <= x) k += b;
    }
    if (arr[k] == x)
        return k;
}
// upper_bound: retorna o indice do primeiro elemento que eh maior que "element"
int ub = upper_bound(v.begin(), v.end(), element) - v.begin();
// lower_bound: retorna o indice do primeiro elemento que eh maior ou igual ao "element"
int lb = lower_bound(v.begin(), v.end(), element) - v.begin();
int freq = ub - lb; // frequencia de "element" no vetor