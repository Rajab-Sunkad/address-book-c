/*Name:Rajab J Sunkad
Date: 22/09/2024
Project: Address Book
Description: The Address Book project is a menu-driven application that allows users to store, manage, and retrieve contact information 
			 efficiently. It provides basic operations like adding, viewing, searching, editing, and deleting contact details.
*/
#include <stdio.h>
#include "contact.h"

int main() 
{
    int choice;

    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do 
    {
	
	//print the list of operations of addressbook
	printf("\nAddress Book Menu:\n");
	printf("1. Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Save and Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	char ch;

	//check whether the input is character or digit
	if (choice == ch) 
	{
		//if input choice is character then print error msg 
        printf("Invalid input. Try again.\n");

		// Clear input buffer to prevent infinite loop
        while (getchar() != '\n'); // Clear input buffer
        continue;  // Skip to next iteration of loop
    }

	switch (choice) 
	{
	    case 1:
		createContact(&addressBook);
		break;
	    case 2:
		searchContact(&addressBook);
		break;
	    case 3:
		editContact(&addressBook);
		break;
	    case 4:
		deleteContact(&addressBook);
		break;
	    case 5:
		listContacts(&addressBook);
		break;
	    case 6:
		//printf("Saving and Exiting...\n");
		saveContactsToFile(&addressBook);
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);
    return 0;
}


