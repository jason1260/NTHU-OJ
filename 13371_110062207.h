void mergeSort(int* arg, int st, int ed) {
    if (st >= ed)
        return;
    //printf("st = %d, ed = %d\n", st, ed);
    int arr[ed];
    //int *arr = (int *)malloc(sizeof(int)*(ed - st + 1));
    //printf("sucessfully split!\n");
    int mid = ((ed - st) >> 1) + st;
    int st1 = st, ed1 = mid;
    int st2 = mid + 1, ed2 = ed;
    //printf("st1 = %d, ed1 = %d\n", st1, ed1);
    mergeSort(arg, st1, ed1);
    //printf("st2 = %d, ed2 = %d\n", st2, ed2);
    mergeSort(arg, st2, ed2);
    //printf("-------------\n");
    int k = st;
    while (st1 <= ed1 && st2 <= ed2)
        arr[k++] = arg[st1] < arg[st2] ? arg[st1++] : arg[st2++];
    while (st1 <= ed1)
        arr[k++] = arg[st1++];
    while (st2 <= ed2)
        arr[k++] = arg[st2++];
    for (k = st; k <= ed; k++) {
        arg[k] = arr[k];
        //printf("%d ", arg[k]);
    }
    //printf("\n");
}