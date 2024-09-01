void putnbr(int x, int size, int i, int *arr)
{
    if (x < 0)
        x = -x;
    if (x >= 10)
    {
        putnbr(x / 10, size, i + 1, arr);
    }
    arr[i] = x % 10;
}

int i_size(int x, int count)
{
    if (x == 0)
        return count;
    while(x != 0)
    {   
        count++;
        return(i_size(x / 10, count));
    }
    return (0);
}

int *rev_tab(int *arr, int size)
{
    int *rev;
    int i;

    i = 0;
    rev = malloc(size * sizeof(int));
    while (i < size)
    {
        rev[i] = arr[size - 1];
        rev[size - 1] = arr[i];
        i++;
        size--;
    }
    return (rev);
}

bool check_arrs(int *arr, int *rev_arr, int size, int i)
{
    while (i < size)
    {
        if (arr[i] == rev_arr[i])
            return(check_arrs(arr, rev_arr, size, i + 1));
        else
            return (false);
    }
    return (true);
}

bool isPalindrome(int x) {
    int size;
    int *arr;
    int *rev_arr;

    if (x >= 0 && x < 10)
        return true;
    if (x < 0)
        return false;
    size = i_size(x, 0);
    arr = malloc(size * sizeof(int));
    putnbr(x, size, 0, arr);
    rev_arr = rev_tab(arr, size);
    return(check_arrs(arr, rev_arr, size, 0));
}