// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A group of F friends is working on an assignment for their Physics class.
Each of the friends made exactly M measurements of the same property. Their outcomes are given
in the int[] data. (More precisely, data is a concatenation 
of F arrays of length M each: the first M elements are the measurements 
made by one person, the next M elements are the measurements made by a second person, and so on.)


The median of a sequence is the element that would be in the middle if the sequence were sorted.
If the length of the sequence is even, we'll say that the smaller of the two middle elements is the median.
For example, in this problem the median of {10, 40, 30, 20} is 20.


According to the friends' textbook, the value they all measured should be goal.
The friends would like to tweak some of their measurements to make the median of data exactly equal to goal.
Your task is as follows:


Determine X = the smallest number of people who have to cheat and modify some of the values they measured.
Suppose we want to have exactly X cheaters. Determine Y = the smallest number of individual measurements that will have to be changed.
Return {X, Y}.


DEFINITION
Class:MedianFaking
Method:minimize
Parameters:int, int, int[], int
Returns:int[]
Method signature:int[] minimize(int F, int M, int[] data, int goal)


NOTES
-When modifying an element of data the friends can set it to any real value they like. In particular, the new value doesn't have to satisfy the input constraints.


CONSTRAINTS
-F and M will be positive.
-F*M will not exceed 1,000.
-data will have exactly F*M elements.
-Each element of data will be between 0 and 99, inclusive.
-goal will be between 0 and 99, inclusive.


EXAMPLES

0)
5
5
{1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15}
8

Returns: {1, 5 }

There are five friends, each of them made five measurements. Spaces in data are included for better readability.
The current median of data is 13. In order to bring it down to 8 it is enough if just one person cheats. For example, person #4 could change their measurements from {18,16,17,19,20} to {3,1,3,5,7}.
It can be shown that for this input there is no solution in which the only cheater changes fewer than all five of their measurements.

1)
5
5
{1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9}
8

Returns: {2, 5 }

In this test case the friends have the same collection of measurements but in this case there is no single person who can change the median to 5 by tweaking their outcomes. We need at least two cheaters.
One optimal solution: person 2 changes two of their outcomes to get {3,4,7,21,8} and person 4 changes three more to get {7,1,15,-1,-47}.

2)
1
4
{10, 40, 30, 20}
20

Returns: {0, 0 }

The example from the problem statement. The median is already 20, no changes are needed.

3)
4
3
{3,8,12, 3,8,12, 3,8,12, 8,12,17}
12

Returns: {1, 2 }

The measurements given in data are not necessarily distinct.

4)
5
1
{10, 20, 30, 40, 50}
23

Returns: {1, 1 }

The desired median is not among the measurements these five friends made. Luckily, there is an easy fix: person #3 should change their outcome from 30 to 23 and they will be done.

// END CUT HERE
import java.util.*;
public class MedianFaking {
	public int[] minimize(int F, int M, int[] data, int goal) {
		
	}
	public static void main(String[] args) {
		MedianFaking temp = new MedianFaking();
		System.out.println(temp.minimize(int F, int M, int[] data, int goal));
	}
}
