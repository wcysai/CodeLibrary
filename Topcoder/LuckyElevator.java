// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You are in charge of programming the hotel elevator.


Many hotel guests consider the digit 4 unlucky. To make their stay more comfortable, the hotel has decided that when numbering the floors it will skip all numbers that contain the digit 4.
Thus, the sequence of floor numbers starts as follows: 0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 25, 26, 27, 28, 29, 30, 31, 32, 33, 35, 36, 37, 38, 39, 50, 51, ...


Suppose a guest entered the elevator in the lobby of the hotel (i.e., floor 0) and pushed the button buttonPressed.
We want to send the elevator to the desired floor.
Calculate and return the number of physical floors the elevator should ascend.


DEFINITION
Class:LuckyElevator
Method:actualFloor
Parameters:int
Returns:int
Method signature:int actualFloor(int buttonPressed)


CONSTRAINTS
-buttonPressed will be between 1 and 100,000, inclusive.
-buttonPressed will not contain the digit 4.


EXAMPLES

0)
3

Returns: 3

The floor number 3 is the actual third floor from the bottom.

1)
5

Returns: 4

When the guest pushes the button number 5, we should bring them to the floor that's fourth from the bottom. (Remember that there is no floor number 4.)

2)
18

Returns: 16

As there is no floor 4 and no floor 14, the button number 18 will bring you to the sixteenth physical floor.

3)
50

Returns: 36



4)
100000

Returns: 59049

This is the largest possible input. The button number 100,000 sends the elevator to the 59,049-th actual floor of the building.

// END CUT HERE
import java.util.*;
public class LuckyElevator {
	public int actualFloor(int buttonPressed) {
		
	}
	public static void main(String[] args) {
		LuckyElevator temp = new LuckyElevator();
		System.out.println(temp.actualFloor(int buttonPressed));
	}
}
