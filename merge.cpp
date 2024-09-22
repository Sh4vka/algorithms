#include <iostream>
#include <random>

class Mas
{
private:
    int len;
    int *mas = new int [len];

public:
    Mas(int init_len){len = init_len;}

    void print_mas()
    {
        for (int i = 0; i < len; i++)
            std::cout << mas[i] << " ";
        std::cout << std::endl;
    }

    void rand_mas()
    {
        for (int i = 0; i < len; i++)
            mas[i] = random() % 100;
    }

    void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *left_mas = new int [n1];
        int *right_mas = new int [n2];

        for (int i = 0; i < n1; i++)
            left_mas[i] = mas[left + i];
        for (int i = 0; i < n2; i++)
            right_mas[i] = mas[mid + 1 + i];

        int i = 0; int j = 0; int k = left;

        while (i < n1 && j < n2)
        {
            if (left_mas[i] <= right_mas[j])
            {
                mas[k] = left_mas[i];
                i++;
            }
            else
            {
                mas[k] = right_mas[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            mas[k] = left_mas[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            mas[k] = right_mas[j];
            j++;
            k++;
        }

        delete[] left_mas;
        delete[] right_mas;
    }

    void merge_sort(int left, int right)
    {
        if (left < right)
        {
            int mid = left +(right - left) / 2;

            merge_sort(left, mid);
            merge_sort(mid + 1, right);

            merge(left, mid, right);
        }
    }
};

int main()
{
    int len;
    std::cin >> len;

    Mas mas_a = Mas(len);

    mas_a.rand_mas();
    mas_a.print_mas();

    mas_a.merge_sort(0, len - 1);
    mas_a.print_mas();

    return 0;
}