#include <stdio.h>

int
main(int argc, char* argv[])
{
//    printf("%s\n", argv[1]);
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
        return 0;

    int ch1, ch2, flag = 0;
    while ((ch1 = fgetc(file)) != EOF)
    {
        ch2 = getchar();
        if (ch1 != ch2)
        {
            flag = 1;
            break;
        }
    }
    fclose(file);
    if (flag == 0)
        printf("same\n");
    if (flag == 1)
        printf("wrong ans\n");
    return 0;
}
