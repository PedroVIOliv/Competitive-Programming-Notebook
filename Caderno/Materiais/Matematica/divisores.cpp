// divisores de n: O(sqrt(n))
void divisores(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            divisores.push_back(i);
            if(i != n/i) divisores.push_back(n/i);
        }    
    }
}


// O(sqrt(n))
void divisores_primos(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            divisores.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) divisores.pb(n); // n eh primo
}