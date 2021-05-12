
#include <bits/stdc++.h>
using namespace std;

//! TC: O(nlogn) and SC: O(n) - for data structure
//? Approach: Get the meetings done with short periods- end that meeting with small end time
class Meeting
{

public:
    int start;
    int end;
    int pos;
};

class Solution
{
public:
    // Comparator to sort according to end time
    static bool comparator(Meeting m1, Meeting m2)
    {

        if (m1.end < m2.end)
        {
            // no need to do anything
            return true;
        }
        else if (m1.end > m2.end)
            return false; // swap case
        else if (m1.pos < m2.pos)
            return true; // case when end time are equal then smaller index should come first
        else
            return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        if (n == 1)
            return 1;

        vector<Meeting> meet(n);
        // putting the meeting into the datastructure
        for (int i = 0; i < n; i++)
        {

            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        // sort the meetings
        sort(meet.begin(), meet.end(), comparator);

        // we know first meeting is going to be happen
        int meets = 1;              // meet 1
        int curr_end = meet[0].end; // storing the end time

        // checking for rest of the meetings
        for (int i = 1; i < n; i++)
        {
            // if ith meet start is greater than curr_end
            if (meet[i].start > curr_end)
            {
                curr_end = meet[i].end;
                // and increment the meets
                meets++;
            }
        }

        return meets;
    }
};