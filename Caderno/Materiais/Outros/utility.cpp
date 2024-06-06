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

is_sorted(v.begin(), v.end());

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

// MMC
int lcm(int a, int b) { return a / __gcd(a, b) * b; }

// Converter decimal para hexadecimal
stringstream ss;
ss << hex << ans; // ans eh um numero decimal
auto res = ss.str;

// Converter hexadecimal para decimal
string hexa_number = "2beff";
int decimal_number = stoi(hexa_number, 0, 16);


// Converter de string para double
double ans = stod(str);

// Dar merge em dois vetores v1 e v2 em um vetor v
merge(v1.bb, v1.ee, v2.bb, v2.ee, back_inserter(v));


// tuple
tuple<int, int, string> tupleName;
tupleName.emplace_back(v1, v2, v3);
get<index>(tupleName);


// deque
deque<type> d;
d.push_front(element);
d.push_back(element);
d.pop_front();
d.pop_back();


// permutation
sort(str.begin(), str.end());
do { cout << str << endl; } 
    while(next_permutation(str.begin(), str.end()));