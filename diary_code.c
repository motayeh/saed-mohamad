#include <stdio.h>
#include <stdlib.h>

void createEntry();
void viewEntries();

int main() {
    int choice;
    do {
        printf("Personal Diary System\n");
        printf("1. Create new entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void createEntry() {
    char date[20];
    char content[1000];
    FILE *fp;

    fp = fopen("diary.txt", "a"); // Open file in append mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);
    getchar(); // Consume newline character left in input buffer

    printf("Enter the content:\n");
    fgets(content, sizeof(content), stdin);

    fprintf(fp, "Date: %s\n", date);
    fprintf(fp, "Content: %s\n", content);

    fclose(fp);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *fp;
    char c;

    fp = fopen("diary.txt", "r"); // Open file in read mode
    if (fp == NULL) {
        printf("No entries found.\n");
        return;
    }

    // Print the content of the file character by character
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
}
