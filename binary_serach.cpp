#include <iostream>

class Mas
{
protected:
    int len;
    int* mas;

public:
    Mas(int init_len)
    {
        len = init_len;
        mas = new int [len];
    }

    ~Mas(){delete[] mas;}

    void new_mas()
    {
        int j = 0;
        for (int i = 0; i < len; i++) {
            mas[i] = j;
            j += 2;
        }
    }

    void print_mas()
    {
        for (int i = 0; i < len; i++)
            std::cout << mas[i] << " ";
        std::cout << std::endl;
    }
};

class Binary_Search : public Mas
{
public:
    Binary_Search(int init_len) : Mas(init_len){}

    int iterative_binary_search(int target)
    {
        int left = 0;
        int right = len - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mas[mid] == target)
                return mid;

            if (mas[mid] > target)
                right = mid - 1;

            else
                left = mid + 1;
        }

        return -1;
    }

    int recursive_binary_search(int left, int right, int target)
    {
        if (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mas[mid] == target)
                return mid;

            if (mas[mid] > target)
                return recursive_binary_search(left, mid - 1, target);

            return recursive_binary_search(mid + 1, right, target);
        }

        return -1;
    }
};

int main()
{
    int len, target;
    std::cin >> len;

    Binary_Search mas = Binary_Search(len);
    mas.new_mas();
    mas.print_mas();

    std::cin >> target;

    std::cout << mas.iterative_binary_search(target) << std::endl;
    std::cout << mas.recursive_binary_search(0, len - 1, target) << std::endl;

    return 0;
}
