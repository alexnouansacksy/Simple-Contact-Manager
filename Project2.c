// Alex Nouansacksy
// Simple Contact Manager (Project 2)
// 12/14/2023
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int askQuestion() {
    int num;
    printf("__________________________________________________\n");
    printf("|                                                |\n");
    printf("|   Simple Contact Manager by Alex Nouansacksy   |\n");
    printf("|   [1] View Contacts                            |\n");
    printf("|   [2] Add Contact                              |\n");
    printf("|   [3] Search Contact                           |\n");
    printf("|   [4] Exit                                     |\n");
    printf("|________________________________________________|\n");

    printf("Enter Choice: ");
    scanf("%d", &num);
    return num;
}

int main() {
    int num = -1;

    char names[20][2000];
    char emails[20][2000];
    char numbers[20][2000];
    
    int cnt = 0;

    while (num != 4) {
        num = askQuestion();
        if (num == 1) {
            if (cnt == 0) printf("Contact list is empty.\n");
            else {
                printf("Contact List\n");
                printf("Name\tEmail\t\tPhone Number\n");
                for (int i = 0; i < cnt; i++) {
                    printf("%s\t%s\t%s\n", names[i], emails[i], numbers[i]);
                }
            }
        } else if (num == 2) {
            printf("Enter name: ");
            fgets(names[cnt], 50, stdin);
            scanf("%s", &names[cnt]);

            printf("Enter email: ");
            fgets(emails[cnt], 50, stdin);
            scanf("%s", &emails[cnt]);

            printf("Enter phone number: ");
            fgets(numbers[cnt], 50, stdin);
            scanf("%s", &numbers[cnt]);

            cnt++;
        } else if (num == 3) {
            char name[50];
            printf("Enter name: ");
            fgets(name, 50, stdin);
            scanf("%s", &name);

            bool found = false;
            for (int i = 0; i < cnt; i++) {
                if (strcmp(names[i], name) == 0) {
                    printf("Name: %s\nEmail: %s\nPhone Number: %s\n", names[i], emails[i], numbers[i]);
                    found = true;
                }
            }
            if (!found) printf("Name is not in the list.\n");

        }
    }
}

/*
PS C:\Users\alexn\Desktop\AP-CSP> cd "c:\Users\alexn\Desktop\AP-CSP\" ; if ($?) { gcc Project2.c -o Project2 } ; if ($?) { .\Project2 }
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 1
Contact list is empty.
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 2
Enter name: alex
Enter email: alex@gmail
Enter phone number: 123
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 2
Enter name: claire
Enter email: claire@gmail
Enter phone number: 123
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 1
Contact List
Name    Email           Phone Number
alex    alex@gmail      123
claire  claire@gmail    123
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 3
Enter name: claire
Name: claire
Email: claire@gmail
Phone Number: 123
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 3
Enter name: daniel
Name is not in the list.
__________________________________________________
|                                                |
|   Simple Contact Manager by Alex Nouansacksy   |
|   [1] View Contacts                            |
|   [2] Add Contact                              |
|   [3] Search Contact                           |
|   [4] Exit                                     |
|________________________________________________|
Enter Choice: 4
PS C:\Users\alexn\Desktop\AP-CSP> 
*/