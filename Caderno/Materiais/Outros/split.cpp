//split a string with a delimiter
//eg.: split("Olá, tudo bem?", " ") -> ["Olá,", "tudo", "bem?"]

vector<string> split(string in, string delimiter){
    vector<string> numbers;
    string token = "";
    int pos;
    while(true){
        pos = in.find(delimiter);
        if(pos == -1) break;
        token = in.substr(0, pos);
        numbers.push_back(token);
        in = in.erase(0, pos + delimiter.length());
    }
    numbers.push_back(in);
    return numbers;
}