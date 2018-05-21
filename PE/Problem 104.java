BigInteger fn2 = 1;
BigInteger fn1 = 1;
BigInteger fn;
 
BigInteger tailcut = 1000000000;
 
int n = 2;
bool found = false;
 
while (!found) {
    n++;
 
    fn = fn1 + fn2;
    long tail = (long)(fn % tailcut);
    if (IsPandigital(tail)) {
        int digits = 1 + (int) BigInteger.Log10(fn);
        if (digits > 9) {
            long head = (long)(fn / BigInteger.Pow(10, digits - 9));
            if (IsPandigital(head)) {
                found = true;
            }
        }
    }
 
    fn2 = fn1;
    fn1 = fn;
}