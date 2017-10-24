void check_test()
{
    freopen("test/info.txt", "w", stdout);
    int i, j, problems_amount = 0, tests_amount = 0;
    char* problem_number = NULL;
    /* считаем кол-во задач */
    DIR *dir = opendir("test");
    while (readdir(dir) != NULL)
        problems_amount++;
    problems_amount -= 3;
    closedir(dir);
    printf("%d\n", problems_amount); /* вывод кол-ва задач */
    /* строка с номером задачи */
    problem_number = (char*)malloc(sizeof(char) * 7);
    problem_number[0] = 't';
    problem_number[1] = 'e';
    problem_number[2] = 's';
    problem_number[3] = 't';
    problem_number[4] = '/';
    problem_number[5] = '0';
    /* обрабатываем каждую задачу */
    for(i = 1; i <= problems_amount; i++)
    {
        printf("%02d { ", i);
        problem_number[6] = i + '0';
        dir = opendir(problem_number);
        tests_amount = 0; /* счетчик для кол-ва тестов */
        while (readdir(dir) != NULL)
            tests_amount++;
        for(j = 1; j < tests_amount / 2; j++)
            printf("%03d ", j);
        printf("}\n");
    }
}
