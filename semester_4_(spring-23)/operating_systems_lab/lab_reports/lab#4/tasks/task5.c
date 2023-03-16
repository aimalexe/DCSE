// Task 5: Run the following program and observe the output.

#include <stdio.h>

int main()
{
    struct student
    {
        char name[20];
        int id;
    };

    struct student s1, s2, s3;

    printf("Please enter the student name, and id\n");
    scanf("%s %d", &s1.name, &s1.id);
    scanf("%s %d", &s2.name, &s2.id);
    scanf("%s %d", &s3.name, &s3.id);

    printf("\nThe students details");
    printf("\n %s \t\t %d", s1.name, s1.id);
    printf("\n %s \t\t %d", s2.name, s2.id);
    printf("\n %s \t\t %d", s3.name, s3.id);

    return 0;
}
