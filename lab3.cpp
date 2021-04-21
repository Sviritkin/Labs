#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int const MASS = 10;
    int arr [MASS];

    bool already_there;

    for (int i = 0; i < MASS; )
    {
        already_there = false;
        int new_random_value = rand () % 40;

        for (int j = 0; j < i; j++)
        {
            if (arr [j] == new_random_value)
            {
                already_there = true;

                break;
            }
        }
        if (!already_there)
        {
            arr [i] = new_random_value;
            i++;
        }
    }

    for (int i = 0; i < MASS; i++)
    {
        cout << arr[i] << endl;
    }

    int min_value = arr [0];

    for (int i = 0; i < MASS; i++)
    {
       if (arr [i] < min_value)
        {
            min_value = arr [i];
        }
    }

    cout << "The smallest number in the array = " << min_value << endl;

    return 0;
}
