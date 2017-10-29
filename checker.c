#include <stdio.h>

int
main(int argc, char* argv[])
{
//    printf("%s\n", argv[1]);
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
        return 0;

    int ch1, ch2, flag = 1;
    while ((ch1 = fgetc(file)) != EOF)
    {
        ch2 = getchar();
        if (ch1 != ch2)
        {
            flag = 0;
            break;
        }
    }
    fclose(file);
/*    if (flag)
        printf("same\n");
	else
        printf("wrong ans\n");*/
	file = fopen(argv[2], "w");
	fprintf(file, "%d ", (flag));
	fclose(file);
    return 0;
}
