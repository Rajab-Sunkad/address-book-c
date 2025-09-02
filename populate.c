#include "contact.h"
 #include <string.h>
// Dummy contact data
/* static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};  */

void populateAddressBook(AddressBook* addressBook) 
{
    // Open the CSV file in read mode ("r")
    FILE* file = fopen("contacts.csv", "r");

    // Check if file opening failed
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;      // Exit function if file cannot be opened
    }

    char line[100];     // Buffer to store each line from the file

    // Read file line by line
    while (fgets(line, sizeof(line), file)) 
    {
        // Tokenize the line using comma (,) as delimiter
        char* token = strtok(line, ",");

        // Check if tokenization succeeded
        if (token != NULL) 
        {
            // Copy name from token to address book
            strcpy(addressBook->contacts[addressBook->contactCount].name, token);

            // Tokenize next field (phone)
            token = strtok(NULL, ",");

            // Check if phone token is valid
            if (token != NULL) 
            {
                // Copy phone from token to address book
                strcpy(addressBook->contacts[addressBook->contactCount].phone, token);

                // Tokenize next field (email)
                token = strtok(NULL, "\n");

                // Check if email token is valid
                if (token != NULL) 
                {
                    // Copy email from token to address book
                    strcpy(addressBook->contacts[addressBook->contactCount].email, token);

                    // Increment contact count
                    addressBook->contactCount++;
                }
            }
        }
    }
    
    // Close the file
    fclose(file);
}

/* void populateAddressBook(AddressBook* addressBook)
{
    //find the no. of elements in the contact array
    int size = sizeof(dummyContacts) / sizeof(dummyContacts[0]);

    //copy dummy contact elements into the contacts array
    for(int i=0;i< size;i++)
    {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }

    addressBook->contactCount = size;
} */


/* int validum(char *num)
{
    int flag = 0;
    printf("Enter the number : ");
    scanf("%s",num);
    while(num!='\0')
    {
        for(int i=0;num[i]!='\0';i++)
        {
            if(num[i]>='0' && num[i]<='9');
            {
                flag = 1;
            }
        }
    }
    return flag;
} */