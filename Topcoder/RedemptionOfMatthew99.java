// BEGIN CUT HERE
// PROBLEM STATEMENT
// Matthew99 was the predicted champion of IOI2017. Zhangzj, the Emperor of Yali Empire, warned that if Matthew99 failed the competition, he would be met with fire and fury, like the world had never seen before. However, Matthew99 totally sucked and only got a silver medal. Therefore, Zhangzj demanded Matthew99 to be arrested upon his arrivial to the empire.

Scared, Matthew99 turned to a priest for help. The priest said that his sin could be redeemed only if he proved that he had the ability to get a better place. Thus, he gave Matthew99 the last chance to prove himself.


There are two polylines in the plane.
Each polyline consists of N vertices.
The first polyline lies strictly above the x axis and the second polyline lies strictly below the x axis.


You are given four int[]s: X1, Y1, X2, and Y2, each with N elements.
The first polyline consists of the vertices (X1[0], Y1[0]), ..., (X1[N-1], Y1[N-1]), the second one is defined in the same way using X2 and Y2.


Each polyline goes from the left to the right. Formally, the coordinates given in X1 and X2 are strictly increasing.


Additionally, the points of the polylines are placed so that:

If we connected the first and the last vertex of the first polyline to the point (0, 10^10000), we would get the boundary of a convex polygon P1.
If we connected the first and the last vertex of the second polyline to the point (0, -10^10000), we would get the boundary of a convex polygon P2.



Finally, the 2N given points are placed so that no three of them are collinear.


A traversal is a sequence of 2N points that has the following properties:

It contains each vertex of each polyline exactly once.
Two consecutive points in the traversal cannot belong to the same polyline.
The line segment that connects two consecutive points in the traversal cannot intersect the polygons P1 and P2.



The length of the traversal is the sum of Euclidean distances between consecutive points in the traversal.


Matthew99 was given the task to find the shortest possible traversal.
Of course, Matthew99 was too weak and only deserved a silver medal.
Therefore, he didn't manage to solve it.
His sin was not redeemed and he was imprisoned by Zhangzj.


After hearing Matthew99's sad story, you feel sorry for him and you are relieved that as least you are not as weak as he was.
Solve this problem to prove that you are stronger than him!
Return the minimal length of a traversal.
If there is no valid traversal, return -1 instead.


DEFINITION
Class:RedemptionOfMatthew99
Method:bestTraversal
Parameters:int[], int[], int[], int[]
Returns:double
Method signature:double bestTraversal(int[] X1, int[] Y1, int[] X2, int[] Y2)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-A convex polygon is a simple polygon (not self-intersecting) in which no line segment between two points on the boundary ever goes outside the polygon.


CONSTRAINTS
-N will be between 2 and 1,000, inclusive.
-X1, Y1, X2, and Y2 will each contain exactly N elements.
-Each element of X1, Y1, X2, and Y2 will be between -1,000,000,000 and 1,000,000,000, inclusive.
-For each valid i, Y1[i] will be greater than 0, and Y2[i] will be less than 0.
-For each valid i, X1[i] will be less than X1[i + 1]; and X2[i] will be less than X2[i + 1].
-No three of the 2N points described by X1, Y1, X2, and Y2 will be collinear.
-The 2N points described by X1, Y1, X2, and Y2 will form the two convex polygons as described in the statement.


EXAMPLES

0)
{0, 1}
{1, 1}
{0, 1}
{-1, -1}

Returns: 6.23606797749979

The first polyline consists of the points (0, 1) and (1, 1).
The second polyline consists of the points (0, -1) and (1, -1).

One of the best traversals is (0, 1) → (0, -1) → (1, 1) → (1, -1), yielding a total distance of 4 + sqrt(5).

1)
{0, 1, 2}
{2, 1, 2}
{0, 1, 2}
{-2, -1, -2}

Returns: 16.32455532033676

One of the best traversals will be (0, 2) → (0, -2) → (1, 1) → (1, -1) → (2, 2) → (2, -2).

2)
{-2, 2}
{1, 5}
{-2, 2}
{-1, -4}

Returns: 15.614226788360828

This time one of the best traversals will be (2, -4) → (-2, 1) → (-2, -1) → (2, 5).

3)
{-2, 1, 2}
{1, 2, 6}
{-3, -2, -1}
{-1, -1, -2}

Returns: -1.0

There is no solution.

4)
{331, 667, 2926, 3285}
{536, 375, 375, 596}
{760, 1291, 2251, 2939}
{-615, -428, -428, -636}

Returns: 8698.860039486546



// END CUT HERE
import java.util.*;
public class RedemptionOfMatthew99 {
	public double bestTraversal(int[] X1, int[] Y1, int[] X2, int[] Y2) {
		
	}
	public static void main(String[] args) {
		RedemptionOfMatthew99 temp = new RedemptionOfMatthew99();
		System.out.println(temp.bestTraversal(int[] X1, int[] Y1, int[] X2, int[] Y2));
	}
}
