// Equation: ax + by = gcd(a, b)
// {x, y, gcd(a, b)}
vector<int> extendedEuclidean(int a, int b) {
    if(!b) return {1, 0, a};

    vector<int> result = extendedEuclidean(b, a % b);
    int smallX = result[0];
    int smallY = result[1];
    int gcd = result[2];

    int x = smallY;
    int y = smallX - ((a / b) * smallY);
    return {x, y, gcd};
}