#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct librarymanagement
{
    char bname[100];
    char bauthor[100];
    int price;
};

void addbook();
void displaybook();
void searchbook();

int d, m, i;
struct librarymanagement b[100];

void addbook() {
    printf("Enter the number of books to add: ");
    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++) {
        printf("\nEnter Book %d details:\n", i + 1);
        printf("Book Name: ");
        fgets(b[i].bname, sizeof(b[i].bname), stdin);
        b[i].bname[strcspn(b[i].bname, "\n")] = '\0';
        printf("Author: ");
        fgets(b[i].bauthor, sizeof(b[i].bauthor), stdin);
        b[i].bauthor[strcspn(b[i].bauthor, "\n")] = '\0';
        printf("Price: ");
        scanf("%d", &b[i].price);
        getchar();
    }
}

void displaybook() {
    printf("\nBook Details:\n");
    printf("------------------------------------------\n");
    printf("Book Name\tAuthor\t\tPrice\n");
    printf("------------------------------------------\n");
    for (i = 0; i < m; i++) {
        printf("%s\t\t%s\t\t%d\n", b[i].bname, b[i].bauthor, b[i].price);
    }
    printf("------------------------------------------\n");
}

void searchbook() {
    char search[100];
    printf("Enter the Book Name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';
    int found = 0;
    for (i = 0; i < m; i++) {
        if (strcmp(b[i].bname, search) == 0) {
            found = 1;
            printf("\nBook found!\n");
            printf("Book Name: %s\n", b[i].bname);
            printf("Author: %s\n", b[i].bauthor);
            printf("Price: %d\n", b[i].price);
            break;
        }
    }
    if (!found) {
        printf("\nBook not found.\n");
    }
}

int main() {
    printf("_________________________________________________________________\n\n");
    printf("\t\tLibrary\n\t\t\tManagement\n    \t\t\t\t   System\n");
    printf("_________________________________________________________________\n\n");
    do {
        printf("enter the choice(1.add book 2.display book 3.search 4.exit): ");
        scanf("%d", &d);
        getchar();
        switch (d) {
            case 1:
                addbook();
                break;
            case 2:
                displaybook();
                break;
            case 3:
                searchbook();
                break;
            case 4:
                exit(0);
            default:
                printf("enter the valid number...\n");
                break;
        }
    } while (d != 4);
    return 0;
}


