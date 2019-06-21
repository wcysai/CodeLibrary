// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
A slash maze is a rectangular table of characters, each being either a slash or a backslash. Example:


\\/\/
\\//\
\//\/
\\/\\


Each character represents a square cell with penetrable walls but an impenetrable diagonal wall. 
The entrance to the maze is always on the leftmost unit segment of the top side, and the exit is always on the rightmost unit segment of the bottom side.
Thus, the slashes shown above correspond to the following maze:





You start outside of the maze and you must end outside of the maze. 
Entering the maze takes one step, and leaving the maze takes one step. 
In each other step you can move from your current triangle across the side of a square into an adjacent triangle. 
The above figure shows a 17-step path through the maze.


You are given the int steps. Construct any rectangular slash maze with the following properties:


the number of rows is between 1 and 50, inclusive
the number of colums is between 1 and 50, inclusive
steps is exactly equal to the smallest number of steps needed to cross the maze from start to finish


Return the maze as a String[]. If there is no maze with the desired properties, return an empty String[] instead.


DEFINITION
Class:SlashPath
Method:construct
Parameters:int
Returns:String[]
Method signature:String[] construct(int steps)


CONSTRAINTS
-steps will be between 1 and 3000, inclusive.


EXAMPLES

0)
7

Returns: {"\\\\/\\", "/\\\\\\", "\\\\\\\\" }

A nicer formatting for the returned maze:

\\/\
/\\\
\\\\


(Note that in all example outputs the backslashes in strings are escaped: each \\ represents a single backslash.)

1)
17

Returns: {"\\\\/\\/", "\\\\//\\", "\\//\\/", "\\\\/\\\\" }

The example from the problem statement.
The return value shown above corresponds to the figure in the statement.

2)
1234

Returns: { }



// END CUT HERE
import java.util.*;
public class SlashPath {
	public String[] construct(int steps) {
		
	}
	public static void main(String[] args) {
		SlashPath temp = new SlashPath();
		System.out.println(temp.construct(int steps));
	}
}
