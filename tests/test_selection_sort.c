#include "tests.h"

int main()
{
    int n = 0;
    int *l = NULL;
    int l2[] = {};
    int l3[] = {0};
    int l4[] = {16, 18, -23, 29, 36, 44, 45, -11, -8, -48};
    int l5[] = {-2, 3, 5, 3, 3, 20, -50};

    int *l_e = NULL;
    int l2_e[] = {};
    int l3_e[] = {0};
    int l4_e[] = {-48, -23, -11, -8, 16, 18, 29, 36, 44, 45};
    int l5_e[] = {-50, -2, 3, 3, 3, 5, 20};

    printf("Bubble Sort Tests:\n");
    // null
    selection_sort(l, 0);
    print_result(are_equal_int_arrays(l, l_e, 0), "Test #1");

    // empty
    selection_sort(l2, 0);
    print_result(are_equal_int_arrays(l2, l2_e, 0), "Test #2");

    // single item
    selection_sort(l3, 1);
    print_result(are_equal_int_arrays(l3, l3_e, 1), "Test #3");

    // multiple (all unique items)
    selection_sort(l4, 10);
    print_array(l4, 10);
    print_array(l4_e, 10);
    print_result(are_equal_int_arrays(l4, l4_e, 10), "Test #4");

    // multiple (has repeated items)
    selection_sort(l5, 7);
    print_result(are_equal_int_arrays(l5, l5_e, 7), "Test #5");
}
