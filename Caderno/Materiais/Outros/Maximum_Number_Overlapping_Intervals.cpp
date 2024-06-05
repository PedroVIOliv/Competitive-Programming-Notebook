// Function that print maximum
// overlap among ranges
void overlap(vector<pair<int, int> > v) {
    // variable to store the maximum
    // count
    int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
 
    // storing the x and y
    // coordinates in data vector
    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i].first, 'x' });
        data.push_back({ v[i].second, 'y' });
    }
 
    sort(data.begin(), data.end());
 
    // Traverse the data vector to
    // count number of overlaps
    for (int i = 0; i < data.size(); i++) {
 
        // if x occur it means a new range
        // is added so we increase count
        if (data[i].second == 'x')
            count++;
 
        // if y occur it means a range
        // is ended so we decrease count
        if (data[i].second == 'y')
            count--;
        ans = max(ans, count);
    }
 
    cout << ans << endl;
}