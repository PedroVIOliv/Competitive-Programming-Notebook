struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { // ordenar pelo x e depois pelo y
        if (fabs(x-other.x) > EPS) // diferente
            return x < other.x;
        return y < other.y;
    }
};

double euclidean_distance(const point &p1, const point &p2) {
    return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}

// M_PI is in <cmath>, but if your compiler does not have it, use
// const double PI = acos(-1.0)
double DEG_to_RAD(double d) { return d*M_PI / 180.0; }
double RAD_to_DEG(double r) { return r*180.0 / M_PI; }
// rotate p by theta degrees counter-clockwise around the origin (0, 0)
point rotate(const point &p, double theta) { // theta in degrees
    double rad = DEG_to_RAD(theta); // convert to radians
    return point(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}