// verificar se a soma de de dois elementos do vetor é igual a B[index]
// O(n)
bool isItASum(int index) {
    int sum = 0, l = 0, h = index-1;
    while(l <= h) {
        sum = B[l] + B[h];
        if(sum == B[index]) return true;
        else (sum > B[index]) ? h-- : l++;
    }
    return false;
}