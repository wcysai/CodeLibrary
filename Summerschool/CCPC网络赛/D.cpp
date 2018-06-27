void getNext(char *s,int next[]){
    int nn = strlen(s);
    next[0] = nn;
    int p = 0;
    while (p+1 < nn && s[p] == s[p+1]) p++;
    next[1] = p;
    int k = 1, L;
    for (int i = 2; i < nn; i++){
        p =     k + next[k] - 1; L = next[i - k];
        if (i + L <= p) next[i] = L;
        else {
            int j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < nn && s[i + j] == s[j]) j++;
            next[i] = j; k = i;

        }
    }
/*    for (int i=0;i<nn;i++){
        cout<< next[i] <<" ";
    }cout<<endl;
*/
}
