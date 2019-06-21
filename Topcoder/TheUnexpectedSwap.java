// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are given a String N that contains the decimal representation of a (possibly very large) positive integer.
In order to keep the input size low, you have to generate this number N on your own.
You are given the int digits, the String prefN, and the int seed.
Use the following pseudocode to generate N:


A[0] = seed
for i = 1 to digits-1:
	A[i] = (A[i-1] * 1009 + 10009) modulo 100019

for i = 0 to length(prefN)-1:
        N[i] = prefN[i]

for i = length(prefN) to digits-1:
	N[i] = N[ A[i] modulo i ]



We are going to swap two digits of the large number stored in N.
The digits to swap will be chosen uniformly at random.
More precisely, we will consider all pairs of indices (i, j) such that 0 <= i < j <= digits-1, we will select one of these pairs of indices uniformly at random, and then we will swap the digits N[i] and N[j].



Let E be the expected value of the number we will obtain.
(In other words, E is the average of all possible outcomes.)
Then, let F = E * digits * (digits - 1).
It can be shown that F is always an integer.
As the value F can be very large, please calculate and return the value (F modulo 1,000,000,007).


DEFINITION
Class:TheUnexpectedSwap
Method:findExpectedResult
Parameters:int, String, int
Returns:int
Method signature:int findExpectedResult(int digits, String prefN, int seed)


NOTES
-The reference solution would correctly solve any N that matches the constraints. It does not depend on the properties of the pseudorandom generator.


CONSTRAINTS
-digits will be between 2 and 200,000, inclusive.
-The length of prefN will be between 1 and min(1000,digits), inclusive.
-Each character of prefN will be a digit ('0'-'9').
-Character 0 of prefN will not be '0'.
-seed will be between 0 and 100,018, inclusive.


EXAMPLES

0)
2
"32"
0

Returns: 46


The number is N = "32". There is exactly one possible swap: we swap the characters N[0] and N[1], producing the new number "23".


As there is only one outcome, we get that E = 23, and then F = 23 * 2 * 1 = 46.


1)
2
"60"
0

Returns: 12

After the swap the number obtained from N can have a leading zero. This is allowed. In this case the only possible swap will produce the number "06". The value of this number is simply 6.

2)
10
"1"
0

Returns: 999999297

The number you'll generate is N = "1111111111". There are 45 different pairs of digits we can swap. Regardless of which two digits we swap, the value of the new number will always be 1,111,111,111. Thus, we get that E = 1,111,111,111, and then F = 1,111,111,111 * 10 * 9 = 99,999,999,990. Make sure you correctly compute and return the value F modulo 10^9 + 7.

3)
6
"123"
47

Returns: 5331084

When generating N, you should first compute the sequence A = { 47, 57432, 47896, 27896, 51734, 99716 } and then use that to obtain N = "123332".
There are 15 possible swaps. The average of their outcomes is E = 177702.8.

// END CUT HERE
import java.util.*;
public class TheUnexpectedSwap {
	public int findExpectedResult(int digits, String prefN, int seed) {
		
	}
	public static void main(String[] args) {
		TheUnexpectedSwap temp = new TheUnexpectedSwap();
		System.out.println(temp.findExpectedResult(int digits, String prefN, int seed));
	}
}
