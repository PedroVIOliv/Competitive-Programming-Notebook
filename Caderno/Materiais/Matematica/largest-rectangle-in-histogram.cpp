int getMaxArea(vector<int> &heights) {
    int n = heights.size();

    stack<int> s; s.push(-1);
    int area = heights[0];
    int i = 0;

    vector<int> left_smaller(n, -1), right_smaller(n, n);
    while(i < n) {
        while(!s.empty() && s.top() != -1 && heights[s.top()] > heights[i]) {
            right_smaller[s.top()] = i;
            s.pop();
        }

        if(i > 0 && heights[i] == heights[i-1])
            left_smaller[i] = left_smaller[i-1];
        else left_smaller[i] = s.top();

        s.push(i++);
    }

    for(int j = 0; j < n; j++)
        area = max(area, heights[j] * (right_smaller[j] - left_smaller[j] - 1));
    
    return area;
}