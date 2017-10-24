#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <dirent.h>
#include "check_data.c"
#include "check_test.c"

int main()
{
    int pid, user, problem, users_amount, problems_amount;
    char *user_number = NULL;
    char *problem_number = NULL;
    user_number = (char*)malloc(sizeof(char) * 2);
    user_number[0] = '0';
    user_number[1] = '0';
    problem_number = (char*)malloc(sizeof(char) * 2);
    problem_number[0] = '0';
    problem_number[1] = '0';
    check_data();
    check_test();
    freopen("data/info.txt", "r", stdin);
    cin >> users_amount;
    for(user = 1; user <= users_amount; user++)
    {
        user_number[1] = user + '0';
        for(problem = 1; problem <= problems_amount; problem++)
        {
            pid = fork();
            if(!pid)
            {
                problem_number[1] = problem + '0';
                execlp("./judge_unit", "./judge_unit", user_number, problem_number, NULL);
                printf("error\n");
                return 0;
            }
            wait(NULL);
        }
    }
    return 0;
}
