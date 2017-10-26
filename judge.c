#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "check_data.c"
#include "check_test.c"

int main()
{
    int pid, user, problem, users_amount;
    char *text = NULL;
    char *problem_number = NULL;
    problem_number = (char*)malloc(sizeof(char) * 2);
    problem_number[0] = '0';
    problem_number[1] = '0';
    char *one_string = NULL;
    one_string = (char*)malloc(sizeof(char) * 16);
    one_string[0] = 'd';
    one_string[1] = 'a';
    one_string[2] = 't';
    one_string[3] = 'a';
    one_string[4] = '/';
    one_string[5] = 'u';
    one_string[6] = 's';
    one_string[7] = 'e';
    one_string[8] = 'r';
    one_string[9] = '0';
    one_string[10] = '0';
    one_string[11] = '/';
    one_string[12] = '0';
    one_string[13] = '0';
    one_string[14] = '.';
    one_string[15] = 'c';
    check_data();
    check_test();

    freopen("data/info.txt", "r", stdin);
    scanf("%d", &users_amount);
    for(user = 1; user <= users_amount; user++)
    {
        one_string[9] = user / 10 + '0';
        one_string[10] = user + '0';
        scanf("%s%s%s", text, text, text);
        problem = 1;
//      for(problem = 1; problem <= problems_amount; problem++)
        while(strcmp(text, "}"))
        {
            pid = fork();
            if(!pid)
            {
                problem_number[0] = problem / 10 + '0';
                problem_number[1] = problem + '0';
                one_string[12] = problem / 10 + '0';
                one_string[13] = problem + '0';
                execlp("./judge_unit", "./judge_unit", one_string, problem_number, NULL);
                printf("error\n");
                return 0;
            }
            wait(NULL);
            problem++;
            scanf("%s", text);
        }
    }
    return 0;
}
