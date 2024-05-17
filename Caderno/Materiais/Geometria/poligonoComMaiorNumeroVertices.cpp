class Point {
    public:
        int x, y;
};

Point points[MAXN];
int dp[MAXN][MAXN]; // # máximo de vértices que formam um polígono convexo usando os pontos[i...j]
int N;

Point vetor(Point a, Point b) {
    Point res;
    res.x = b.x - a.x;
    res.y = b.y - a.y;
    return res;
}

// calcular a orientação dos pontos e também para ver se um ponto está dentro ou fora de um polígono convexo
int cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// ordenar de forma crescente no sentido anti-horário
// se o produto vetorial for negativo, sentido anti-horário
bool cmp(Point a, Point b) {
    return b.x * a.y - b.y * a.x <= 0; 
}

void solve() {
    points[0].x = points[0].y = 0; // origem
    memset(dp, 0, sizeof(dp));
    memset(points, 0, sizeof(points));

    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        points[i].x = x; points[i].y = y;
    }

    // ordenando no sentido anti-horário
    sort(points + 1, points + N + 1, cmp);

    int ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = 2;

        // pontos anteriores a "i"
        for(int j = 1; j < i; j++) {
            dp[i][j] = 0;

            for(int k = 0; k < j; k++) {
                Point ponto_k = points[k]; Point ponto_j = points[j];
                Point ponto_i = points[i];
                // vetor que representa a direção e magnitude entre os pontos "k" e "j"
                Point vetor_kj = vetor(ponto_k, ponto_j);

                // vetor que vai do ponto "i" ao ponto "j"
                Point vetor_ji = vetor(ponto_j, ponto_i);

                // o polígono com mais vértices usando os pontos [j...k] tem mais vértices que
                // o polígono com mais vértices usando os pontos [i...j]
                // e o ponto "i" está dentro do polígono formado em dp[j][k]
                if(dp[j][k] >= dp[i][j] && cross_product(vetor_kj, vetor_ji) > 0)
                    dp[i][j] = dp[j][k] + 1;
                
            }
                ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl << endl;
}