// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You have a straight stick that is exactly 1,000,000 micrometers long.
You also have n tiny stickers.
Each sticker can be used to mark some point on the stick.
You want to place the stickers in a way that creates a makeshift ruler.
For each distance x between 1 and ceiling(n^2 / 4) there have to be two stickers that are exactly x micrometers apart.


Return a int[] with n elements: the positons of stickers (in micrometers, measured from one fixed end of the stick).
A solution always exists. Any valid solution will be accepted.


DEFINITION
Class:RulerMaker
Method:placeStickers
Parameters:int
Returns:int[]
Method signature:int[] placeStickers(int n)


NOTES
-The value ceiling(x) is the smallest integer greater than or equal to x. For example, ceiling(47) = 47, and ceiling(42.01) = 43.
-The position of each sticker must be an integer between 0 and 1,000,000, inclusive.
-If you don't place a sticker onto the end of the stick, you cannot use that end of the stick for a measurement. E.g., placing a single sticker at coordinate 3 does not allow you to measure the distance 3, only placing two stickers at coordinates 0 and 3 does.


CONSTRAINTS
-n will be between 2 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: {47, 50, 49 }

As ceiling(3^2 / 4) = 3, we have to place three stickers in such a way that we can measure (at least) the distances of 1, 2, and 3 micrometers.
If we place the stickers at coordinates A=47, B=50, and C=49, we see that 1 is the distance between B and C, 2 is the distance between A and C, and 3 is the distance between A and B.

1)
7

Returns: {38, 26, 35, 47, 31, 39, 37 }

Here we need the distances from 1 to 13, inclusive.

// END CUT HERE
import java.util.*;
public class RulerMaker {
	public int[] placeStickers(int n) {
		
	}
	public static void main(String[] args) {
		RulerMaker temp = new RulerMaker();
		System.out.println(temp.placeStickers(int n));
	}
}
