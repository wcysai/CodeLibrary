// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given a positive integer N, find and return the length of the longest sequence a_1, ..., a_K of positive integers such that:

The sum of all a_i is N.
For each valid i, a_i < a_{i+1}.
For each valid i, a_i divides a_{i+1}.


DEFINITION
Class:DivisorSequences
Method:longest
Parameters:int
Returns:int
Method signature:int longest(int N)


CONSTRAINTS
-N will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
15

Returns: 4

The only optimal sequence is {1,2,4,8}. Clearly, 1 divides 2, 2 divides 4, 4 divides 8, and 1+2+4+8 = 15.

1)
12

Returns: 2

The are four distinct optimal sequences: {1,11}, {2,10}, {3,9}, and {4,8}. There is no valid sequence with more than two elements.

2)
34

Returns: 4

The only optimal sequence is {1, 3, 6, 24}.

// END CUT HERE
import java.util.*;
public class DivisorSequences {
	public int longest(int N) {
		
	}
	public static void main(String[] args) {
		DivisorSequences temp = new DivisorSequences();
		System.out.println(temp.longest(int N));
	}
}
