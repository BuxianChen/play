char* replaceSpaces(char* S, int length){
    int i = 0, num = 0, j = 0;
    for (; i < length; i++)
        if (S[i] == ' ')
            num++;
    j = num*2+i;
    S[j--] = 0;
    for (--i; i >= 0; --i){
        if (S[i] != ' ')
            S[j--] = S[i];
        else {
            S[j--] = '0';
            S[j--] = '2';
            S[j--] = '%';
        }
    }
    return S;
}