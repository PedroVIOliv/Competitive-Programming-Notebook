bool isPalindrome(string S){
    string P = S;
    reverse(P.begin(), P.end()); // Reverte P
    return (S == P); //retorna true se verdadeiro, false se falso
}
