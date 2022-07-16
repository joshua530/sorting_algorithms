#include "tests.h"

int main()
{
    int n = 0;
    int l2[] = {0};
    int l3[] = {16, 18, -23, 29, 36, 44, 45, -11, -8, -48};
    int l4[] = {-2, 3, 5, 3, 3, 20, -50};

    int l2_e[] = {0};
    int l3_e[] = {-48, -23, -11, -8, 16, 18, 29, 36, 44, 45};
    int l4_e[] = {-50, -2, 3, 3, 3, 5, 20};

    // actual lists
    listint_t *l_al = NULL;
    listint_t *l2_al = create_list(l2, 1);
    listint_t *l3_al = create_list(l3, 10);
    listint_t *l4_al = create_list(l4, 7);

    // expected lists
    listint_t *l_el = NULL;
    listint_t *l2_el = create_list(l2_e, 1);
    listint_t *l3_el = create_list(l3_e, 10);
    listint_t *l4_el = create_list(l4_e, 7);
    
    printf("Insertion Sort List Tests:\n");
    // null
    insertion_sort_list(&l_al);
    print_result(are_equal_int_lists(l_al, l_el, 0), "Test #1");

    // single item
    insertion_sort_list(&l2_al);
    print_result(are_equal_int_lists(l2_al, l2_el, 1), "Test #2");

    // multiple (all unique items)
    insertion_sort_list(&l3_al);
    print_result(are_equal_int_lists(l3_al, l3_el, 10), "Test #3");

    // multiple (has repeated items)
    insertion_sort_list(&l4_al);
    print_result(are_equal_int_lists(l4_al, l4_el, 7), "Test #4");
}
