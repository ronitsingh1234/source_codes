#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, b;
char ok[50];
long int a;

// Maximum number of users
#define MAX_USERS 10

// Structure to store user information
struct User
{
    char username[50];
    char password[50];
};

// Array to store user data
struct User users[MAX_USERS];

// Function to register a new user
void registerUser()
{
    b = 1;
    if (MAX_USERS <= 0)
    {
        printf("User registration is not allowed.\n");
        return;
    }

    printf("Enter your username: ");
    char username[50];
    scanf("%s", username);

    // Check if the username is already taken
    for (int i = 0; i < MAX_USERS; ++i)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("Username already exists. Please choose another one.\n");
            return;
        }
    }

    printf("Enter your password: ");
    char password[50];
    scanf("%s", &password);

    // Store the user data
    for (int i = 0; i < MAX_USERS; ++i)
    {
        if (users[i].username[0] == '\0')
        {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("Registration successful!\n");
            return;
        }
    }

    printf("User limit reached. Cannot register more users.\n");
}

// Function to authenticate a user
int authenticateUser()
{
    printf("Enter your username: ");
    char username[50];
    scanf("%s", username);

    printf("Enter your password: ");
    char password[50];
    scanf("%s", password);

    // Check if the entered credentials match any registered user
    for (int i = 0; i < MAX_USERS; ++i)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful!\n");
            return 1; // Authentication successful
        }
    }

    printf("Invalid username or password. Login failed.\n");
    return 0; // Authentication failed
}

int main()
{
    int choice;
up:
    while (1)
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (authenticateUser())
            {

                int n;
                printf("\n\n\n");
                printf("--------------------------------Welcome to the election--------------------------------\n\n");
                printf("Here are the contestants name\n\n");

                char contestant1[20] = {"Narendra modhi"};
                char contestant2[20] = {"Rahul Gandhi"};
                char contestant3[20] = {"vikas rawat"};
                char contestant4[20] = {"Nitin sharma"};
                char contestant5[20] = {"vijay thakur"};

                printf("1.%s\n\n", contestant1);
                printf("2.%s\n\n", contestant2);
                printf("3.%s\n\n", contestant3);
                printf("4.%s\n\n", contestant4);
                printf("5.%s\n\n", contestant5);

                printf("-->Please enter the number at which your contestant name to whom you want to vote\n");
                printf("-->To see result enter the 0\n\n");
                scanf("%d", &n);

                switch (n)
                {
                case 1:

                    if (b == 1)
                    {
                        count1++;
                        printf("Your vote succesfully counted\n\n");
                        b = 0;
                    }
                    else
                    {

                        printf("you have already voted\n\n");
                    }

                    goto up;
                    break;
                case 2:
                    if (b == 1)
                    {
                        count2++;
                        printf("Your vote succesfully counted\n\n");
                        b = 0;
                    }
                     else
                    {

                        printf("you have already voted\n\n");
                    }
                    goto up;
                    break;
                case 3:
                    if (b == 1)
                    {
                        count3++;
                        printf("Your vote succesfully counted\n\n");
                        b = 0;
                    }
                     else
                    {

                        printf("you have already voted\n\n");
                    }
                    goto up;
                    break;
                case 4:
                    count4++;
                    printf("Your vote succesfully counted\n\n");
                    if (b == 1)
                    {
                        count4++;
                        printf("Your vote succesfully counted\n\n");
                        b = 0;
                    }
                     else
                    {

                        printf("you have already voted\n\n");
                    }
                    goto up;
                    break;
                case 5:
                    if (b == 1)
                    {
                        count5++;
                        printf("Your vote succesfully counted\n\n");
                        b = 0;
                    }
                     else
                    {

                        printf("you have already voted\n\n");
                    }
                    goto up;
                    break;
                case 0:
                    goto result;
                    break;
                default:
                    break;
                }

            result:
                printf("Enter the admin id\n");
                scanf("%ld", &a);
                if (a == 233609002)
                {
                    printf("--------------------------------Here are the result how many vote contestants got--------------------------------\n\n");
                    printf("1.%s votecount is %d\n\n", contestant1, count1);
                    printf("2.%s votecount is %d\n\n", contestant2, count2);
                    printf("3.%s votecount is %d\n\n", contestant3, count3);
                    printf("4.%s votecount is %d\n\n", contestant4, count4);
                    printf("5.%s votecount is %d\n\n", contestant5, count5);

                    if (count1 > count2 && count1 > count3 && count1 > count4 && count1 > count5)
                    {
                        printf("--------------------------------%s won the election--------------------------------\n\n", contestant1);
                    }
                    else if (count2 > count1 && count2 > count3 && count2 > count4 && count2 > count5)
                    {
                        printf("--------------------------------%s won the election--------------------------------\n\n", contestant2);
                    }
                    else if (count3 > count1 && count3 > count2 && count3 > count4 && count3 > count5)
                    {
                        printf("--------------------------------%s won the election--------------------------------\n\n", contestant3);
                    }
                    else if (count4 > count2 && count4 > count3 && count4 > count1 && count4 > count5)
                    {
                        printf("--------------------------------%s won the election--------------------------------\n\n", contestant4);
                    }
                    else if (count5 > count2 && count5 > count3 && count5 > count4 && count5 > count1)
                    {
                        printf("--------------------------------%s won the election--------------------------------\n\n", contestant5);
                    }
                    else
                    {
                        printf("--------------------------------NO ONE WIN, ELECTION IS DRAW--------------------------------\n\n");
                    }
                    goto end;
                }

                else
                {
                    printf("Wrong admin id!!\n");
                    printf("You are not supposed to see result\n");
                }
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
end:
    return 0;
}