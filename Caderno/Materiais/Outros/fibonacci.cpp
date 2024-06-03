int fib(int n){
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int fib(int n) {
    return (pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2, n))/sqrt(5);
}