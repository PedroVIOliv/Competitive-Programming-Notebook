string isPalindrome(string S){
    string P = S;

    // Reverte P
    reverse(P.begin(), P.end());

    // Se S igual a P
    if (S == P){
        return 1;
    }else{
        return 0;
    }
}
