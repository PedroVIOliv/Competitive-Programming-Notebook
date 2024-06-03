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

// Ler um número octal e printar
scanf("%o", &num); printf("%o", num);

// Ler um número hexadecimal e printar
scanf("%x", &num); printf("%x", num);

// converter uma string representando um número binário em número
string num = "11"; bitset<32> bs(num);
bs.to_ulong(); bs.to_ullong(); // unsigned long (long)

// logs
log(a) // base e
log2(a) // base 2
log10(a) // base 10
log(a)/log(b) // log(a) na base b

// numero de digitos de a na base b
(int)floor(1 + log10((double)a)/log10((double) b));