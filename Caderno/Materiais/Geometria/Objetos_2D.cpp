// círculo centralizado na coordenada c = (a, b) com raio r
// (x - a)² + (y - b)² = r²
int insideCircle(const point_i &p, const point_i &c, int r) {
    int dx = p.x-c.x, dy = p.y-c.y;
    int Euc = dx*dx + dy*dy, rSq = r*r;
    return Euc < rSq ? 1 : (Euc == rSq ? 0 : -1); // in/border/out
}

bool canFormTriangle(int a, int b, int c) {
    return (a+b > c) && (a+c > b) && (b + c) > a;
}

// s: semiperimeter (perimeter * 0.5)
double triangleArea(int a, int b, int c, int s) {
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// retorna o raio do círculo inscrito em um triângulo, dado os comprimentos dos lados do triângulo
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}
// retorna o raio do círculo inscrito em um triângulo, dado os vértices do triângulo
double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// verifica se existe um círculo inscrito em um triângulo dado por três pontos
// Se existir, ela calcula o centro (ctr) do círculo inscrito e o raio (r)
bool inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return false;
    line l1, l2;
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1+ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1+ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr);
    return true;
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
// retorna o raio do círculo circunscrito em um triângulo, dado os vértices do triângulo
double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
    double ans = 0.0;
    // note: P[n-1] = P[0]
    for (int i = 0; i < (int)P.size()-1; ++i)
    ans += dist(P[i], P[i+1]);
    return ans;
}

// returns the area of polygon P
double polygon_area(const vector<point> &P) {
    double ans = 0.0;
    for (int i = 0; i < (int)P.size()-1; ++i)
        ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
    return fabs(ans)/2.0;
}

// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double polygon_area_alternative(const vector<point> &P) {
    double ans = 0.0; point O(0.0, 0.0);
    // O = the Origin
    for (int i = 0; i < (int)P.size()-1; ++i)
    // sum of signed areas
        ans += cross(toVec(O, P[i]), toVec(O, P[i+1]));
    return fabs(ans)/2.0;
}

// returns true if we always make the same turn
// while examining all the edges of the polygon one by one
bool isConvex(const vector<point> &P) {
    int n = (int)P.size();
    if (n <= 3) return false;
    bool firstTurn = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < n-1; ++i)
        if (ccw(P[i], P[i+1], P[(i+2) == n ? 1 : i+2]) != firstTurn)
            return false;
    return true;
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(point pt, const vector<point> &P) {
    int n = (int)P.size();
    if (n <= 3) return -1;

    bool on_polygon = false;
    for (int i = 0; i < n-1; ++i)
        if (fabs(dist(P[i], pt) + dist(pt, P[i+1]) - dist(P[i], P[i+1])) < EPS)
            on_polygon = true;
    if (on_polygon) return 0;
    double sum = 0.0;
    for (int i = 0; i < n-1; ++i) {
        if (ccw(pt, P[i], P[i+1]))
        sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]);
    }
    return fabs(sum) > M_PI ? 1 : -1;
    // 360d->in, 0d->out
}

// compute the intersection point between line segment p-q and line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y - A.x*B.y;
    double u = fabs(a*p.x + b*p.y + c);
    double v = fabs(a*q.x + b*q.y + c);
    return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

    // cuts polygon Q along the line formed by point A->point B (order matters)
    // (note: the last point must be the same as the first point)
vector<point> cutPolygon(point A, point B, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); ++i) {
        double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(toVec(A, B), toVec(A, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]);
        // Q[i] is on the left
        if (left1*left2 < -EPS)
        // crosses line AB
        P.push_back(lineIntersectSeg(Q[i], Q[i+1], A, B));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    return P;
}