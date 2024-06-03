// ordenar os elementos antes de "v.begin()+i" do vetor
// O(nlog(i))
partial_sort(v.begin(), v.begin()+i, v.end());

// rearranja o vetor de forma que o elemento "i" é o "i" menor elemento
// todos elementos antes de "i" são menores ou iguais a "i"
// O(i)
// OBS: a função altera o vetor
nth_element(v.begin(), v.begin()+i, v.end());

// ordenar o vetor de forma estável
// O(nlog²n)
stable_sort(v.begin(), v.begin());