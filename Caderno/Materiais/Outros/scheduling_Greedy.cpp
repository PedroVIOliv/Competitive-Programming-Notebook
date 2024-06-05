bool cmp(pair<int, int> a, pair<int, int> b) { return a.ss < b.ss; }
sort(intervals.bb, intervals.ee, cmp);
int ending = intervals[0].ss;
int ans = 1;
for(int i = 1; i < n; i++) {
    if(ending <= intervals[i].ff) {
        ans++;
        ending = intervals[i].ss;
    }
}