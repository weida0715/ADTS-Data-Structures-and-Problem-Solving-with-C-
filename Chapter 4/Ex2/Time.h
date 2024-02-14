/*
    This header file defines the data type TIme for processing time.
    Basic operations are:
        Default constructor -- Initializes object to 12:00 AM
        set:     To set the time
        display: To display the time
*/

#include <iostream>

class Time
{
public:
    /******** Function Members ********/

    /***** Class constructors*/
    Time();
    /*
        Construct a class object (default).

        Precondition:  None.
        Postcondition: The Time object is initialized to 12:00 A.M.;
            that is, myHours, myMinutes, and myAMorPM are initialized
            to 12, 0, 'A', respectively, and myMilTime to 0.
    */

    Time(unsigned initHours, unsigned initMinutes, char initAMPM);
    /*
        Construct a class object (explicit values).

        Precondition:  initHours, initMinutes, and initAMPM are initial
            values for the data members; they must preserve the class
            invariant.
        Postcondition: Data members myHours, myMinutes, and myAMorPM
            have been initialized to initHours, initMinutes, and initAMPM,
            respectively, and myMilTime to the corresponding military time.
    */

    /***** Other FUnction Members *****/
    void set(unsigned hours, unsigned minutes, char am_pm);
    /*
        Set the data members of a Time object to specified values.

        Preconditions: 1 <= hours <= 12, 0 <= minutes <= 59,
            and am_pm is either 'A' or 'P'.
        Postcondition: Data members myHours, myMinutes, and myAMorPM
            are set to hours, minutes, and am_pm, respectively, and
            myMilTime to the equivalent military time.
    */

    void display(ostream &out) const;
    /*
        Display time in standard and military format using output stream out.

        Precondition:  The outstream out is open.
        Postcondition: The time represented by this Time object has been
            inserted into ostream out.
    */

private:
    /******** Data Members ********/
    unsigned myHours,
        myMinutes;
    char myAMorPM;      // 'A' or 'P'
    unsigned myMilTime; // military time equivalent
};
