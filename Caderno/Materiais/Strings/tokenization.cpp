// Separar a string 'line' de acordo com o char 'divisao'
// as separações são os tokens
string line = "GeeksForGeeks is a must try", intermediate;
char divisao = ' '; // separate the string by blank space
vector<string> tokens;
stringstream check(line);
while(getline(check, intermediate, divisao)) 
    tokens.pb(intermediate);
