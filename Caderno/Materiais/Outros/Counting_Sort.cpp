// Se o array tiver apenas um elemento não ordenado O(n)
for(int j = i-1; j >= 0; j--) // O(n) when inserting in a sorted array
    if(B[j] > B[j+1]) swap(B[j], B[j+1]);