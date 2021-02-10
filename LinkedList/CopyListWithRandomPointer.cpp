// ! Time : O(n) and Space: O(1)
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        //         Step 1-> creating the dummy node next to node in our original list

        Node *itr = head;
        Node *front = head;

        while (itr != NULL)
        {

            front = itr->next;
            Node *cpy = new Node(itr->val);

            itr->next = cpy;
            cpy->next = front;
            itr = front;
        }

        //         Step 2 -> attaching the random pointer of the dummy node

        itr = head;

        while (itr != NULL)
        {

            // if itr->random is not pointing to NULL
            if (itr->random != NULL)
            {
                itr->next->random = itr->random->next; // take an example to understand it clearly
            }
            //Note we don't need to handle the NULL case as random is already pointing to NULL

            //move the itr by two steps-> i.e next node of original list
            itr = itr->next->next;
        }

        // Step 3 -> Seperating the original ans dummy lists

        itr = head;

        Node *pseudoHead = new Node(0);
        Node *cpItr = pseudoHead; // for traversing the dummy list

        while (itr != NULL)
        {

            front = itr->next->next; // one ahead node of original list
            cpItr->next = itr->next;
            itr->next = front;
            cpItr = cpItr->next;
            itr = front;
        }

        return pseudoHead->next;
    }
};