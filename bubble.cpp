#include <iostream>
#include <random>

using namespace std;

void rand_mas(int *mas, int n)
{
    for (int i = 0; i < n; i++)
        mas[i] = random() % 100;
}

void print_mas(int *mas, int n)
{
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";

    cout << endl;
}

void swap(int *mas, int a, int b)
{
    int temp = mas[a];
    mas[a] = mas[b];
    mas[b] = temp;
}

void sort_bubble(int *mas, int len)
{
    for (int j = 0; j < len; j++)
    {
        bool f = true;
        for (int i = 0; i < len - j; i++)
        {
            if (mas[i] > mas[i+1])
            {
                swap(mas, i, i+1);
                f = false;
            }
        }
        if (f)
            break;
    }
}

int main()
{
    int len;
    cin >> len;
    int mas[len];

    rand_mas(mas, len);
    print_mas(mas, len);

    sort_bubble(mas, len);
    print_mas(mas, len);

    return 0;
}