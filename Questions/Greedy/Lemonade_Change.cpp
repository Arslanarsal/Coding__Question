#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    Where 'N' is the length of array 'bill'.
*/

bool lemonadeChange(vector<int> &bill)
{

    // Initialise integer variables 'five' and 'ten' with zero.
    int five = 0, ten = 0;

    for (int amount : bill)
    {

        // If 'amount' is five, we need not to return any change.
        if (amount == 5)
        {
            five++;
        }

        // If 'amount' is ten, we return one five coin else we return false.
        else if (amount == 10)
        {
            if (five == 0)
            {
                return false;
            }
            else
            {
                five--, ten++;
            }
        }

        // If 'amount' is twenty.
        else
        {

            // If one or more ten and one or more five is present, we return it.
            if (ten > 0 and five > 0)
            {
                ten--, five--;
            }

            // If we have 3 or more five, we return three five.
            else if (five > 2)
            {
                five -= 3;
            }

            // Else we return false.
            else
            {
                return false;
            }
        }
    }

    // If change for each 'bill' value is present, we return true.
    return true;
}

int main()
{

    return 0;
}