// ax é congruente a 1 (mod m)
// (ax) mod m == 1 mod m
// queremos encontrar x

int modInverse(int a, int m) {
    auto [ x, gcd ] = extendedEuclidean(a, m);
    
}