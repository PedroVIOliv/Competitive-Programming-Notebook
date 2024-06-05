bool subset_sum(int index, int sum) { // current index of the array, remaining sum
    if(index == -1) return sum == 0;
    
    if(memo1[index][sum] != -1) return memo1[index][sum];
    // exclude
    bool ans = subset_sum(index-1, sum);

    // include
    if(sum - nums[index] >= 0)
        ans |= subset_sum(index-1, sum - nums[index]);
    
    return memo1[index][sum] = ans;
}