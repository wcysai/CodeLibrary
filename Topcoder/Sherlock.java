// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Computer, find "BENADRYL CUCUMBERPATCH".
Did you mean the actor who played Sherlock, Benedict Cumberbatch?


Benedict Cumberbatch is an actor who is famous not only because of his roles.
It is also known that you can misspell his name almost arbitrarily and people (and computers too!) will still recognize him.


In this problem, you are given the name of a person: the Strings firstName and lastName.
We say that this name matches Benedict Cumberbatch if it has all properties listed below.


Each name must have at least seven letters.
The first name must start with 'B' and the last name must start with 'C'.
At least three characters of firstName must appear somewhere in the name "BENEDICT".
At least five characters of lastName must appear somewhere in the name "CUMBERBATCH".


In conditions 3 and 4 we count each occurrence of a letter, even if that letter occurs in the given name more times than in the actor's actual name.
For example, "BATAXXAT" is a valid first name because three of its characters ('B', 'T', 'T') appear in "BENEDICT".


Return "It is him" if all conditions are satisfied and "It is someone else" if they aren't.


DEFINITION
Class:Sherlock
Method:isItHim
Parameters:String, String
Returns:String
Method signature:String isItHim(String firstName, String lastName)


NOTES
-Note that the return value is case-sensitive.


CONSTRAINTS
-firstName and lastName will each consist of between 1 and 20 characters, inclusive.
-Each character in firstName and lastName will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"BENEDICT"
"CUMBERBATCH"

Returns: "It is him"



1)
"BENADRYL"
"CUCUMBERPATCH"

Returns: "It is him"



2)
"HARSHIT"
"MEHTA"

Returns: "It is someone else"



3)
"BATAXXAT"
"CURMUDGEON"

Returns: "It is him"



4)
"BENEDI"
"CUMBER"

Returns: "It is someone else"

Both names are too short.

5)
"BAXAXAXY"
"CENTRIFUGAL"

Returns: "It is someone else"

The first name has too few characters in common with BENEDICT.

6)
"BUMBLESHACK"
"CRUMPLEHORN"

Returns: "It is him"



// END CUT HERE
import java.util.*;
public class Sherlock {
	public String isItHim(String firstName, String lastName) {
		
	}
	public static void main(String[] args) {
		Sherlock temp = new Sherlock();
		System.out.println(temp.isItHim(String firstName, String lastName));
	}
}
