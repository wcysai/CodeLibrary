// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Basha promised her friend Mel that she will come for a visit somewhere between the firstDay of the firstMonth and the lastDay of the lastMonth in 2019.
Basha and Mel live in countries separated by the sea, so Basha has to buy plane tickets.


Airlines are using many tricks when pricing their tickets.
One of the important ones is the "Saturday night stay" concept: if your stay at the destination includes the night from a Saturday to a Sunday, you are unlikely to be a business traveler and thus they will give you a lower price for your tickets.
Basha would like to have cheap plane tickets (who wouldn't), so she wants to plan her trip in such a way that it will include at least one Saturday night.


To summarize:


Basha's day of arrival must be on the firstDay of the firstMonth 2019 or later.
Basha's day of departure must be on the lastDay of the lastMonth 2019 or earlier.
Basha must stay at Mel's place for at least one Saturday night.


Two trip schedules are considered different if Basha arrives and/or departs on a different day.
Count all possible trip schedules, and return the answer.


DEFINITION
Class:SaturdayNightStay
Method:countOptions
Parameters:int, int, int, int
Returns:int
Method signature:int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth)


NOTES
-The year 2019 is not a leap year. The number of days in the individual months of 2019 is 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, and 31.
-The 1st of January 2019 was a Tuesday.
-As explained in the statement, "Saturday night" is short for "the night that starts on a Saturday and ends on a Sunday".


CONSTRAINTS
-firstMonth and lastMonth will each be between 1 and 12, inclusive.
-firstDay will be between 1 and the number of days in firstMonth, inclusive.
-lastDay will be between 1 and the number of days in lastMonth, inclusive.
-The firstDay of the firstMonth will not be later in 2019 than the lastDay of the lastMonth.


EXAMPLES

0)
15
6
16
6

Returns: 1

The earliest day on which Basha can arrive is today: the 15th of June. This is a Saturday.
The latest day on which she can leave is the 16th of June: the Sunday tomorrow.
In order to spend the Saturday night in her destination, Basha must arrive on the 15th and depart on the 16th.

1)
16
6
22
6

Returns: 0

Regardless of when she arrives and departs, her trip will not include any Saturday nights.
Note that the trip which arrives on the 16th and departs on the 22nd includes both a Saturday (the 22nd) and a Sunday (the 16th) but that is not enough: the trip does not contain any Saturday night.

2)
1
1
31
1

Returns: 382

There are many viable options in January 2019, including the longest one: arriving on the 1st and departing on the 31st of January. (This trip contains four different Saturday nights. Additional Saturday nights do not matter, the only requirement is that there has to be at least one of them.)

3)
7
8
19
10

Returns: 2485



// END CUT HERE
import java.util.*;
public class SaturdayNightStay {
	public int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth) {
		
	}
	public static void main(String[] args) {
		SaturdayNightStay temp = new SaturdayNightStay();
		System.out.println(temp.countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth));
	}
}
