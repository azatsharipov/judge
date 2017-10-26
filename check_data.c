void check_data()
{
    freopen("data/info.txt", "w", stdout);
    int i, j, users_amount = 0, problems_amount = 0;
    char* user_number = NULL;
    /* считаем кол-во пользователей */
    DIR *dir = opendir("data");
    while (readdir(dir) != NULL)
        users_amount++;
    users_amount -= 3;
    closedir(dir);
    printf("%d\n", users_amount); /* вывод кол-ва пользователей */
    /* строка с номером задачи */
    user_number = (char*)malloc(sizeof(char) * 11);
    user_number[0] = 'd';
    user_number[1] = 'a';
    user_number[2] = 't';
    user_number[3] = 'a';
    user_number[4] = '/';
    user_number[5] = 'u';
    user_number[6] = 's';
    user_number[7] = 'e';
    user_number[8] = 'r';
    user_number[9] = '0';
    user_number[10] = '0';
    /* обрабатываем каждого пользователя */
    for(i = 1; i <= users_amount; i++)
    {
        printf("user%02d { ", i);
        user_number[9] = i / 10 + '0';
        user_number[10] = i + '0';
        dir = opendir(user_number);
        problems_amount = 0; /* счетчик для кол-ва задач */
        while (readdir(dir) != NULL)
            problems_amount++;
        for(j = 1; j <= problems_amount - 2; j++)
            printf("%02d ", j);
        printf("}\n");
    }
}
