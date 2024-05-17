// Function to calculate f(x) 
float func(float x) { return (3*x - (x*x)); } 
  
// Function for approximate integral 
// ll: lower limit, ul: upper limit, n: number of subintervals in [ll, ul]
float simpsons_(float ll, float ul, int n) { 
    float h = (ul - ll) / n; 
    float x[10], fx[10]; 
  
    for (int i = 0; i <= n; i++) { 
        x[i] = ll + i * h; 
        fx[i] = func(x[i]); 
    } 
    // Calculating result 
    float res = 0; 
    for (int i = 0; i <= n; i++) { 
        if (i == 0 || i == n) 
            res += fx[i]; 
        else if (i % 2 != 0) 
            res += 4 * fx[i]; 
        else
            res += 2 * fx[i]; 
    } 
    res = res * (h / 3); 
    return res; 
} 