#include "tests.h"

/**
 * are_equal_int_arrays - compares two int arrays for equality
 * 
 * @a: the first array
 * @b: second array
 * @size: size of each of the arrays
 * 
 * Return: true if equal, false if not equal
 */
bool are_equal_int_arrays(int *a, int *b, int size)
{
    int i = 0;

    for (; i < size; ++i)
    {
        if (a[i] != b[i])
            return (false);
    }
    return (true);
}

bool are_equal_int_lists(listint_t *a, listint_t *b, int size)
{
    listint_t *tmp_a = a, *tmp_b = b;

    if (!a && !b)
        return (true);
    if (!a && b)
        return (false);
    if (a && !b)
        return (false);

    while (--size)
    {
        if (tmp_a->n != tmp_b->n)
            return (false);
        tmp_a = tmp_a->next;
        tmp_b = tmp_b->next;
    }
    return (true);
}

void print_result(bool test_passed, char *message)
{
    printf("%s: ", message);
    if (!test_passed)
        printf("Failed");
    else
        printf("Success");
    printf("\n");
}

/**
 * create_list - instantiates a list of numbers
 * 
 * @nums: the numbers to be added to the list
 * @size: the length of the list
 * 
 * Return: instantiated list
 */
listint_t *create_list(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}
