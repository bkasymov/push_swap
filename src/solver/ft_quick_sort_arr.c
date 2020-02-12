#include "../../includes/push_swap.h"

/*
 *
 */

void        ft_quick_sort(int *s_arr, int first, int last)
{
    int left;
    int right;
    int middle;
    int tmp;

    left = first;
    right = last - 1;
    middle = s_arr[(left + right) / 2];
    if (first < last) {
        while (s_arr[left] < middle)
            left++;
        while (s_arr[right] > middle)
            right--;
        while (left <= right) {
            if (left <= right) {
                tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
            ft_quick_sort(s_arr, first, right);
            ft_quick_sort(s_arr, left, last);
        }
    }
}