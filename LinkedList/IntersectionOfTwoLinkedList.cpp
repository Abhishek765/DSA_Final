/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // !        Using hashset O(m + n) time where 'm' is size of headA and 'n' is size of headB and space will be O(m) since I am inserting only first Linked List

        //  !       Base condition when either of linkedList is empty
        if (headA == NULL || headB == NULL)
            return NULL;

        unordered_set<ListNode *> s;

        while (headA != NULL)
        {
            s.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL)
        {

            if (s.find(headB) != s.end())
                return headB;
            headB = headB->next;
        }

        return NULL;

        /*
Using two pointers Nodes p1 and p2 pointing to headA and headB initially and we will move both simultaneuosly and if suppose p1 reach null then we will do p1= headB and if p2 reach null then p2 = headA

We will do until p1 != p2 or until we found both nodes equal

Time: O(2*M) -> M will be my first List size(*we can choose second also) and in worst case (when no intersection point) my node has to travel both linked list and space is O(1) 
*/

        // !        Base condition when either of linkedList is empty
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while (p1 != p2)
        {

            if (p1 == NULL)
                p1 = headB;
            else
                p1 = p1->next;

            if (p2 == NULL)
                p2 = headA;
            else
                p2 = p2->next;
        }

        return p1; //answer will be required node or null also if both are disconnected list
    }
};