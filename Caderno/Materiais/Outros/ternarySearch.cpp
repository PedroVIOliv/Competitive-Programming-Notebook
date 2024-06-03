// queremos encontrar o minimo de uma funcao unimodal (que cresce e decresce apenas uma vez)
// f eh a funcao 
double ternary_search(double left, double right) {
    while (right - left > 1e-7) {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;
        // inverter o sinal e as variaveis para o maximo
        if (f(m1) < f(m2)) right = m2;
        else left = m1;
    }
    return (left + right) / 2.0;
}