#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_Entry 100
struct diary
{
    char date[20];
    char medicine[100];
    char todaysWork[200];
    char placeToVisit[100];
    char purposeOfVisit[200];
    int bookMark;
};
struct diary  diarys[MAX_Entry] ;
int count=0;
//Function to add Entry
void addEntry()
{
    if(count>=MAX_Entry)
    {
        printf("\nDiary is full. Delete some entries to make space.\n");
        return;
    }

    struct diary newEntry;
    printf("\nEnter Date (e.g., 20-08-2023): ");
    scanf("%s", newEntry.date);
    printf("\nEnter today's work(1.Clean cloths...):\n ");
    printf("----------------------------------\n\n");
    getchar();
    fgets(newEntry.todaysWork,sizeof(newEntry.todaysWork),stdin);
    newEntry.todaysWork[strcspn(newEntry.todaysWork,"\n")]='\0';
    printf("\nEnter the name of medicine(1.Napa 3 times..):\n ");
    printf("----------------------------------------------\n\n");
    fgets(newEntry.medicine,sizeof(newEntry.medicine),stdin);
    newEntry.medicine[strcspn(newEntry.medicine,"\n")]='\0';
    printf("\nEnter name of places that need ti visit(e.g.,1.Hospital(10:30 pM)): \n");
    printf("---------------------------------------------------------------------\n\n");
    fgets(newEntry.placeToVisit,sizeof(newEntry.placeToVisit),stdin);
    newEntry.placeToVisit[strcspn(newEntry.placeToVisit,"\n")]='\0';
    printf("\nEnter the purpose to meet someone/why you do that\n(e.g.,1.meet karim(for return the money ...)):\n");
    printf("---------------------------------------------------\n\n");
    fgets(newEntry.purposeOfVisit,sizeof(newEntry.purposeOfVisit),stdin);
    newEntry.purposeOfVisit[strcspn(newEntry.purposeOfVisit,"\n")]='\0';
    printf("To add this page on bookmark enter '1' or else '0': ");
    scanf("%d",&newEntry.bookMark);
    diarys[count]=newEntry;
    count++;
    printf("\nEntry added successfully!\n");
}

// Function to delete an entry
void deleteEntry()
{
    if (count == 0)
        {
        printf("\nDiary is empty. Nothing to delete.\n");
        return;
        }

    int index,index1;
    printf("\nEnter the page number (1-%d) to delete: ", count);
    scanf("%d", &index1);
    index=index1-1;
    if (index < 0 || index >= count) {
        printf("\nInvalid index. Please enter a valid index.\n");
        return;
    }

    for (int i = index; i < count-1; i++) {
        diarys[i]=diarys[i+1];
    }
    count--;
    printf("\nEntry deleted successfully!\n");
}

// Function to display all entries
void displayDiary()
{
      if (count == 0) {
        printf("\nDiary is empty.\n");
        return;
    }
    printf("\n\n\t\t\tSECOND MEMORY FOR OLD PEOPLE\n\n");
    for(int i=0;i<count;i++)
    {
        printf("\nPage no : %d\n",i+1);
        printf("Date : %s\n",diarys[i].date);
        printf("List of today's Works:\n%s\n\n",diarys[i].todaysWork);
        printf("LIst of medicine :\n%s\n\n",diarys[i].medicine);
        printf("list of places to visit :\n%s\n\n",diarys[i].placeToVisit);
        printf("Purpose to meet those people :\n%s\n\n",diarys[i].purposeOfVisit);


    }



}
//function to display only bookmark pages
void displayBookmark()
{
    if (count == 0)
    {
        printf("\nDiary is empty.\n");
        return;
    }
    printf("\n\t\t\tBOOKMARK PAGES\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (diarys[i].bookMark == 1)
        {
            printf("\npage no : %d\n", i + 1);
            printf("Date : %s\n", diarys[i].date);
            printf("List of today's work:\n%s\n", diarys[i].todaysWork);
            printf("List of medicine :\n%s\n", diarys[i].medicine);
            printf("List of places to visit :\n%s\n", diarys[i].placeToVisit);
            printf("Purpose to meet those people:\n%s\n\n", diarys[i].purposeOfVisit);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\nThere are no Bookmark pages yet.\n");
    }

}

int main() {
    int choice;
    printf("\n\t\t\t WELCOME TO THE SECOND MEMORY OF OLD PEOPLE\n\n");

    while (1) {

        printf("\nDiary Menu:\n\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Display Entries\n");
        printf("4. Dispay only Bookmark pages.\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                displayDiary();
                break;
            case 4:
                displayBookmark();
                break;
            case 5:
                printf("\n\nExiting the diary. Goodbye!\n\n");
                return 0;
            default:
                printf("\n\nInvalid choice. Please enter a valid option.\n\n");
        }
    }

    return 0;
}
