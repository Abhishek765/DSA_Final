int majorityElement(int a[], int size)
{

    // Moore's Voting algo

    int count = 0, ml = 0;
    for (int i = 0; i < size; i++)
    {

        if (count == 0)
        {
            ml = a[i];
        }

        if (ml == a[i])
            count++;

        else
            count--;
    }

    int count2 = 0;
    for (int i = 0; i < size; i++)
    {

        if (a[i] == ml)
            count2++;
    }

    if (count2 > size / 2)
        return ml;

    return -1;
}