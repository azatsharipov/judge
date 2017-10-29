#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>

int
main (int argc, char **argv)
{
    FILE *file;
    int prog_checker[2];
    int fd;
    int pid, pid1, pid2;
//    char * text = NULL;
    char text[10], result;
    int digit, ans;
    char * test_number_dat = NULL;
    char * test_number_ans = NULL;
    test_number_dat = (char*)malloc(sizeof(char) * 15);
    test_number_ans = (char*)malloc(sizeof(char) * 15);

    test_number_dat[0] = 't';
    test_number_dat[1] = 'e';
    test_number_dat[2] = 's';
    test_number_dat[3] = 't';
    test_number_dat[4] = '/';
    test_number_dat[5] = '0';
    test_number_dat[6] = '0';
    test_number_dat[7] = '/';
    test_number_dat[8] = '0';
    test_number_dat[9] = '0';
    test_number_dat[10] = '0';
    test_number_dat[11] = '.';
    test_number_dat[12] = 'd';
    test_number_dat[13] = 'a';
    test_number_dat[14] = 't';

    test_number_ans[0] = 't';
    test_number_ans[1] = 'e';
    test_number_ans[2] = 's';
    test_number_ans[3] = 't';
    test_number_ans[4] = '/';
    test_number_ans[5] = '0';
    test_number_ans[6] = '0';
    test_number_ans[7] = '/';
    test_number_ans[8] = '0';
    test_number_ans[9] = '0';
    test_number_ans[10] = '0';
    test_number_ans[11] = '.';
    test_number_ans[12] = 'a';
    test_number_ans[13] = 'n';
    test_number_ans[14] = 's';

    test_number_dat[5] = argv[2][0];
    test_number_dat[6] = argv[2][1];
    test_number_ans[5] = argv[2][0];
    test_number_ans[6] = argv[2][1];


    pid = fork();
    if (pid == 0)
    {
        execlp("gcc", "gcc", "-Wall", argv[1], "-o", "var/prog", NULL);
    }
    else
    {
        wait(NULL);
    }


	file = fopen("results.txt", "w");
	fprintf(file, "%d", 0);
    fclose(file);
//    freopen("test/info.txt", "r", stdin);
    file = fopen("test/info.txt", "r");
    fscanf(file, "%d", &digit);
    while(strcmp(text, argv[2]))
    {
        fscanf(file, "%s", text);
    }
    fscanf(file, "%s", text);
    fscanf(file, "%s", text);


    while(strcmp(text, "}"))
    {
        pipe(prog_checker);
        pid1 = fork();
        if (pid1 == 0)
        {
            test_number_dat[8] = text[0];
            test_number_dat[9] = text[1];
            test_number_dat[10] = text[2];
            fd = open(test_number_dat, O_CREAT);
            close(prog_checker[0]);
            dup2(fd, 0);
            close(fd);
            dup2(prog_checker[1], 1);
            close(prog_checker[1]);
            execlp("./var/prog", "./var/prog", NULL);
            return 0;
            exit(1);
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            close(prog_checker[1]);
            dup2(prog_checker[0], 0);
            close(prog_checker[0]);
            test_number_ans[8] = text[0];
            test_number_ans[9] = text[1];
            test_number_ans[10] = text[2];
            execlp("./checker", "./checker", test_number_ans, "results.txt", NULL);
            exit(1);
        }
        close(prog_checker[0]);
        close(prog_checker[1]);
        wait(NULL);
        wait(NULL);
        fscanf(file, "%s", text);
    }
    fclose(file);
	file = fopen("results.txt", "r");
	ans = 0;
	while(fscanf(file, "%d", &digit) != EOF)
	{
		if(digit == 1)
			ans++;
	}
	fclose(file);
	file = fopen("results.txt", "w");
	fprintf(file, "%d\n", ans);
	fclose(file);
    return 0;
}
