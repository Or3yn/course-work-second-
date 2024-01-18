#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

struct Node
{
    int plantNumber;
    int branchNumber;
    char surname[50];
    int beginningAssets;
    int receivedAssets;
    int disposedAssets;
    Node *prev;
    Node *next;
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void goToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, {x, y});
}
// Function to create a new doubly linked list

int checkIfPlantNumberIsUnique(Node *head, int plantNumber)
{

    while (head)
    {

        if (head->plantNumber == plantNumber)
        {
            return 0;
        }

        head = head->next;
    }
    return 1;
}

Node *createDoublyLinkedList()
{
    Node *head = NULL;
    Node *temp = NULL;
    Node *newNode = NULL;
    system("cls");
    int choice;
    do
    {
        system("cls");
        goToXY(50, 15);
        newNode = new Node();
        cout << "Enter plant number: ";

        while (!(cin >> newNode->plantNumber))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value. Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        while (!checkIfPlantNumberIsUnique(head, newNode->plantNumber))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Plant number must be unique";
            cin.clear();
            _getch();
            system("cls");
            goToXY(50, 15);

            while (!(cin >> newNode->plantNumber))
            {
                system("cls");
                goToXY(50, 15);
                cout << "Bad value. Enter to rewrite.";
                getch();
                system("cls");
                goToXY(50, 15);
                cin.clear();
                goToXY(50, 15);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        system("cls");
        goToXY(50, 15);
        cout << "Enter branch number: ";
        while (!(cin >> newNode->branchNumber))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value! Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("cls");
        goToXY(50, 15);
        cout << "Enter surname of responsible person: ";
        cin.ignore();
        cin.getline(newNode->surname, 50);
        system("cls");
        goToXY(50, 15);
        cout << "Enter availability of material assets at the beginning: ";
        while (!(cin >> newNode->beginningAssets))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value! Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("cls");
        goToXY(50, 15);
        cout << "Enter material assets received: ";
        while (!(cin >> newNode->receivedAssets))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value! Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("cls");
        goToXY(50, 15);
        cout << "Enter material assets disposed: ";
        while (!(cin >> newNode->disposedAssets))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value! Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        goToXY(50, 15);
        cout << "Do you want to add another element? (1 for Yes, 0 for No): ";
        cin >> choice;

    } while (choice != 0);
    system("cls");
    return head;
}
void updateField(Node *&head, int plantNumber)
{
    system("cls");
    bool found = false;
    Node *currNode = head;

    while (currNode != nullptr)
    {
        if (currNode->plantNumber == plantNumber)
        {
            found = true;
            int fieldChoice;
            goToXY(50, 15);
            cout << "Enter the field number you want to update:\n"
                 << "1. Plant Number\n"
                 << "2. Branch Number\n"
                 << "3. Surname\n"
                 << "4. Beginning Assets\n"
                 << "5. Received Assets\n"
                 << "6. Disposed Assets\n";

            cin >> fieldChoice;

            switch (fieldChoice)
            {
            case 1:
                cout << "Enter new Plant Number: ";
                cin >> currNode->plantNumber;
                break;
            case 2:
                cout << "Enter new Branch Number: ";
                cin >> currNode->branchNumber;
                break;
            case 3:
                cout << "Enter new Surname: ";
                cin.ignore(); // Ignore newline character
                cin.getline(currNode->surname, 49);
                break;
            case 4:
                cout << "Enter new Beginning Assets: ";
                cin >> currNode->beginningAssets;
                break;
            case 5:
                cout << "Enter new Received Assets: ";
                cin >> currNode->receivedAssets;
                break;
            case 6:
                cout << "Enter new Disposed Assets: ";
                cin >> currNode->disposedAssets;
                break;
            default:
                cout << "Invalid field number!";
                break;
            }

            break;
        }

        currNode = currNode->next;
    }

    if (!found)
    {
        char choice;

        cout << "Plant number is not found" << endl;
    }
}
void displayPage(Node *node, Node *hNode, int items, int page, int totalPages)
{

    Node *current = node;

    int itemsDisplayed = 0;

    // display the head of a table
    cout << "+----------------+-----------------+-------------------+--------------------+-------------------+-----------------+" << endl;
    cout << "|                |                 |                   |                    |                   |                 |" << endl;
    cout << "|  Plant Number  |  Branch Number  |      Surname      |  Beginning Assets  |  Received Assets  | Disposed Assets |" << endl;
    cout << "|                |                 |                   |                    |                   |                 |" << endl;

    // display the core of a list
    while (current != nullptr && itemsDisplayed != items)
    {
        if (current->plantNumber != hNode->plantNumber)
        {
            cout << "+----------------+-----------------+-------------------+--------------------+-------------------+-----------------+" << endl;
            cout << "| " << setw(14) << current->plantNumber
                 << " | " << setw(15) << current->branchNumber
                 << " | " << setw(17) << current->surname
                 << " | " << setw(18) << current->beginningAssets
                 << " | " << setw(17) << current->receivedAssets
                 << " | " << setw(15) << current->disposedAssets << " |" << endl;
        }
        else
        {
            cout << "+----------------+-----------------+-------------------+--------------------+-------------------+-----------------+" << endl;
            cout << "| "
                 << "\e[4;35m" << setw(14) << current->plantNumber << "\033[0m"
                 << " | "
                 << "\e[4;35m" << setw(15) << current->branchNumber << "\033[0m"
                 << " | "
                 << "\e[4;35m" << setw(17) << current->surname << "\033[0m"
                 << " | "
                 << "\e[4;35m" << setw(18) << current->beginningAssets << "\033[0m"
                 << " | "
                 << "\e[4;35m" << setw(17) << current->receivedAssets << "\033[0m"
                 << " | "
                 << "\e[4;35m" << setw(15) << current->disposedAssets << "\033[0m"
                 << " |" << endl;
        }

        current = current->next;

        itemsDisplayed++;
    }
    cout << "+----------------+-----------------+-------------------+--------------------+-------------------+-----------------+" << endl;
    // Display navigation instructions
    cout << "Page " << page << " of " << totalPages << " | Use Left and Right arrow keys to navigate | Press 'Q' to quit" << endl;
}
void displayDoublyLinkedList(Node *head)
{
    system("cls");

    if (head == NULL)
    {
        cout << "Doubly linked list is empty!" << endl;
        return;
    }

    int page = 1;
    int nodesPerPage = 20;
    int highlightNum = 1;
    Node *highlightedNode = head;
    Node *temp = head;
    Node *itemsPtr = head;
    int totalNodes = 0;
    while (temp != nullptr)
    {
        totalNodes++;
        temp = temp->next;
    }
    int totalPages = (totalNodes + nodesPerPage - 1) / nodesPerPage;

    temp = head;

    displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
    while (1)
    {
        // getting arrow key code
        char input = _getch();

        if (input == -32)
        {
            input = _getch();
            switch (input)
            {
            case 75:
                if (page != max(1, page - 1))
                {
                    page = max(1, page - 1);
                    for (int i = 0; i < nodesPerPage; i++)
                    {
                        itemsPtr = itemsPtr->prev;
                    }

                    highlightNum = 1;
                    highlightedNode = itemsPtr;

                    system("cls");
                    displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
                }

                break;
            case 77:
                if (page != min(totalPages, page + 1))
                {
                    page = min(totalPages, page + 1);
                    for (int i = 0; i < nodesPerPage; i++)
                    {
                        itemsPtr = itemsPtr->next;
                    }

                    highlightNum = 1;
                    highlightedNode = itemsPtr;

                    system("cls");
                    displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
                }

                break;
            case 72:
                if (highlightNum > 1)
                {
                    highlightedNode = highlightedNode->prev;
                    highlightNum--;

                    system("cls");
                    displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
                }
                break;
            case 80:
                if (highlightNum + 1 <= nodesPerPage)
                {
                    if (highlightedNode->next != nullptr)
                    {
                        highlightedNode = highlightedNode->next;
                        highlightNum++;

                        system("cls");
                        displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
                    }
                }
                break;
            }
        }
        else if (input == 13)
        {
            updateField(head, highlightedNode->plantNumber);
            system("cls");
            displayPage(itemsPtr, highlightedNode, nodesPerPage, page, totalPages);
        }
        else
        {
            break;
        }
    }
}
/*Function to swap the nodes */
struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
void bubbleSort(Node **head)
{
    if (*head == nullptr || (*head)->next == nullptr)
    {
        cout << "Cannot sort" << endl;
        return;
    }

    bool swapped;
    Node *current;
    Node *lastSorted = nullptr;

    do
    {
        swapped = false;
        current = *head;

        while (current->next != lastSorted)
        {
            if (current->plantNumber > current->next->plantNumber)
            {
                std::swap(current->plantNumber, current->next->plantNumber);
                std::swap(current->beginningAssets, current->next->beginningAssets);
                std::swap(current->branchNumber, current->next->branchNumber);
                std::swap(current->disposedAssets, current->next->disposedAssets);
                std::swap(current->receivedAssets, current->next->receivedAssets);
                swapped = true;
            }

            current = current->next;
        }

        lastSorted = current;
    } while (swapped);
    cout << "Swapping succeeded" << endl;
}
void addElementToEnd(Node *head)
{
    system("cls");
    if (head == NULL)
    {
        cout << "Doubly linked list is not created. Please create a list first." << endl;
        return;
    }

    Node *newNode = new Node();

    cout << "Enter plant number: ";
    while (!(cin >> newNode->plantNumber))
    {
        system("cls");
        goToXY(50, 15);
        cout << "Bad value. Enter to rewrite.";
        getch();
        system("cls");
        goToXY(50, 15);
        cin.clear();
        goToXY(50, 15);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (!checkIfPlantNumberIsUnique(head, newNode->plantNumber))
    {
        system("cls");
        goToXY(50, 15);
        cout << "Plant number must be unique";
        cin.clear();
        _getch();
        system("cls");
        goToXY(50, 15);

        while (!(cin >> newNode->plantNumber))
        {
            system("cls");
            goToXY(50, 15);
            cout << "Bad value. Enter to rewrite.";
            getch();
            system("cls");
            goToXY(50, 15);
            cin.clear();
            goToXY(50, 15);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Enter branch number: ";
    cin >> newNode->branchNumber;
    cout << "Enter surname of responsible person: ";
    cin.ignore();
    cin.getline(newNode->surname, 50);
    cout << "Enter availability of material assets at the beginning: ";
    cin >> newNode->beginningAssets;
    cout << "Enter material assets received: ";
    cin >> newNode->receivedAssets;
    cout << "Enter material assets disposed: ";
    cin >> newNode->disposedAssets;

    newNode->prev = NULL;
    newNode->next = NULL;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to remove any element from the doubly linked list
void removeElement(Node *&head, Node *elem)
{
    system("cls");
    if (head == NULL)
    {
        cout << "Doubly linked list is empty!" << endl;
        return;
    }

    if (elem->prev != NULL)
    {
        elem->prev->next = elem->next;
    }
    else
    {
        head = elem->next;
    }

    if (elem->next != NULL)
    {
        elem->next->prev = elem->prev;
    }

    delete elem;
}

// Function to highlight the selected menu item
void highlightMenuItem(const string &menuItem, bool isSelected)
{
    if (isSelected)
    {
        cout << "\e[4;35m" << menuItem << "\033[0m" << endl;
    }
    else
    {
        cout << menuItem << endl;
    }
}
void searchNode(Node *head)
{
    system("cls");
    if (head == NULL)
    {
        cout << "Doubly linked list is empty!" << endl;
        return;
    }
    int fieldChoice;
    cout << "Which field do you want to search by?" << endl;
    cout << "1. Plant Number" << endl;
    cout << "2. Branch Number" << endl;
    cout << "3. Surname" << endl;
    cout << "4. Beginning Assets" << endl;
    cout << "5. Received Assets" << endl;
    cout << "6. Disposed Assets" << endl;
    cout << "Enter your choice: ";
    cin >> fieldChoice;

    Node *current = head;
    bool found = false;

    switch (fieldChoice)
    {
    case 1:
    {
        int plantNumber;
        cout << "Enter plant number: ";
        cin >> plantNumber;
        while (current != nullptr)
        {
            if (current->plantNumber == plantNumber)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    case 2:
    {
        int branchNumber;
        cout << "Enter branch number: ";
        cin >> branchNumber;
        while (current != nullptr)
        {
            if (current->branchNumber == branchNumber)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    case 3:
    {
        char surname[50];
        cout << "Enter surname: ";
        cin.ignore(); // Ignore newline character left in the stream
        cin.getline(surname, sizeof(surname));
        while (current != nullptr)
        {
            bool match = true;
            for (int i = 0; i < sizeof(current->surname); i++)
            {
                if (current->surname[i] != surname[i])
                {
                    match = false;
                    break;
                }
                else if (current->surname[i] == '\0' && surname[i] == '\0')
                {
                    break;
                }
            }
            if (match)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    case 4:
    {
        int beginningAssets;
        cout << "Enter beginning assets: ";
        cin >> beginningAssets;
        while (current != nullptr)
        {
            if (current->beginningAssets == beginningAssets)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    case 5:
    {
        int receivedAssets;
        cout << "Enter received assets: ";
        cin >> receivedAssets;
        while (current != nullptr)
        {
            if (current->receivedAssets == receivedAssets)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    case 6:
    {
        int disposedAssets;
        cout << "Enter disposed assets: ";
        cin >> disposedAssets;
        while (current != nullptr)
        {
            if (current->disposedAssets == disposedAssets)
            {
                found = true;
                break;
            }
            current = current->next;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
    }

    if (found)
    {
        cout << "Node found:" << endl;
        cout << "Plant Number: " << current->plantNumber << endl;
        cout << "Branch Number: " << current->branchNumber << endl;
        cout << "Surname: " << current->surname << endl;
        cout << "Beginning Assets: " << current->beginningAssets << endl;
        cout << "Received Assets: " << current->receivedAssets << endl;
        cout << "Disposed Assets: " << current->disposedAssets << endl;
    }
    else
    {
        cout << "No node with the specified field exists." << endl;
    }
}
// Function to calculate the length of a null-terminated char array
int getCharArrayLength(const char *arr)
{
    int count = 0;
    while (arr[count] != '\0')
    {
        count++;
    }
    return count;
}

// Function to copy a null-terminated char array
void copyCharArray(const char *source, char *destination)
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Function to concatenate two null-terminated char arrays
void concatenateCharArray(const char *str1, const char *str2, char *result)
{
    int len1 = getCharArrayLength(str1);
    int len2 = getCharArrayLength(str2);

    int i = 0;
    for (int j = 0; j < len1; j++)
    {
        result[i++] = str1[j];
    }
    for (int j = 0; j < len2; j++)
    {
        result[i++] = str2[j];
    }
    result[i] = '\0';
}

// Function to save the doubly linked list to text and binary files
void saveLinkedListToFile(Node *head)
{
    system("cls");
    const int MAX_FILENAME_LENGTH = 100;
    char textFileName[MAX_FILENAME_LENGTH];
    char binaryFileName[MAX_FILENAME_LENGTH];

    cout << "Enter the name of the text file: ";
    cin.getline(textFileName, MAX_FILENAME_LENGTH);
    concatenateCharArray(textFileName, ".txt", textFileName);

    cout << "Enter the name of the binary file: ";
    cin.getline(binaryFileName, MAX_FILENAME_LENGTH);
    concatenateCharArray(binaryFileName, ".bin", binaryFileName);

    ofstream textFile(textFileName);
    ofstream binaryFile(binaryFileName, ios::binary);

    if (!textFile || !binaryFile)
    {
        cout << "Failed to create/open output files!" << endl;
        return;
    }

    textFile << left;
    textFile << setw(15) << "Plant Number";
    textFile << setw(15) << "Branch Number";
    textFile << setw(15) << "Surname";
    textFile << setw(25) << "Beginning Assets";
    textFile << setw(25) << "Received Assets";
    textFile << setw(25) << "Disposed Assets";
    textFile << endl;

    Node *current = head;
    while (current != nullptr)
    {
        textFile << left << setw(15) << current->plantNumber
                 << setw(15) << current->branchNumber
                 << setw(15) << current->surname
                 << setw(25) << current->beginningAssets
                 << setw(25) << current->receivedAssets
                 << setw(25) << current->disposedAssets << endl;

        binaryFile.write(reinterpret_cast<char *>(current), sizeof(Node));

        current = current->next;
    }

    textFile.close();
    binaryFile.close();

    cout << "Data saved to files successfully." << endl;
}
//-----------------------------------------------------------------------------------READ
void refreshList(Node *&head)
{
    system("cls");
    const int MAX_FILENAME_LENGTH = 100;
    char binaryFileName[MAX_FILENAME_LENGTH];

    cout << "Enter the name of the binary file to refresh from: ";
    cin.getline(binaryFileName, MAX_FILENAME_LENGTH);
    concatenateCharArray(binaryFileName, ".bin", binaryFileName);

    ifstream binaryFile(binaryFileName, ios::binary);

    if (!binaryFile)
    {
        cout << "Failed to open the binary file!" << endl;
        return;
    }

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *current = nullptr;
    while (true)
    {
        Node *newNode = new Node();
        binaryFile.read(reinterpret_cast<char *>(newNode), sizeof(Node));

        if (binaryFile.eof())
        {
            delete newNode;
            break;
        }

        newNode->prev = current;
        newNode->next = nullptr;

        if (current)
        {
            current->next = newNode;
        }
        else
        {
            head = newNode;
        }

        current = newNode;
    }

    binaryFile.close();

    cout << "List refreshed from the binary file successfully." << endl;
}
//-----------------------------------------PROCEED
void handleData(Node *head)
{
    system("cls");
    int branchNumber;
    Node *temp = head;
    cout << "Enter the branch number you want to proceed: ";
    cin >> branchNumber;
    while (temp != nullptr)
    {
        if (branchNumber != temp->branchNumber)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
        if (temp->next == nullptr)
        {
            cout << "There's no such branch. Try again" << endl;
            return;
        }
    }
    int sum1 = 0; // Sum of beginning assets, received assets, and disposed assets in a particular branch
    int sum2 = 0; // Sum of beginning assets, received assets, and disposed assets across all branches
    int sum3 = 0; // Sum of beginning assets across all nodes
    int sum4 = 0; // Sum of received assets across all nodes
    int sum5 = 0; // Sum of disposed assets across all nodes

    Node *current = head;
    while (current != nullptr)
    {
        sum2 += (current->beginningAssets + current->receivedAssets) - current->disposedAssets;

        if (current->branchNumber == branchNumber)
        {
            sum1 += (current->beginningAssets + current->receivedAssets) - current->disposedAssets;
        }

        sum3 += current->beginningAssets;
        sum4 += current->receivedAssets;
        sum5 += current->disposedAssets;

        current = current->next;
    }

    cout << "Sum of beginning assets, received assets, and disposed assets in branch " << branchNumber << " = " << sum1 << endl;
    cout << "Sum of assets along all branches = " << sum2 << endl;
    cout << "Sum of assets along factory, including only beginning assets = " << sum3 << endl;
    cout << "Sum of assets along factory, including only received assets = " << sum4 << endl;
    cout << "Sum of assets along factory, including only disposed assets = " << sum5 << endl;
}
int main()
{
    Node *doublyLinkedList = NULL;
    int plantNumber;
    int choice = 0;
    int menuIndex = 0;
    char keyPressed;
    bool shouldExit = false;

    while (!shouldExit)
    {
        system("cls"); // Clear console screen
        goToXY(48, 8);
        cout << "     ...::::::.," << endl;
        goToXY(48, 9);
        cout << "   .::::::::::::::." << endl;
        goToXY(48, 10);
        cout << "  .::..  .::::::::::." << endl;
        goToXY(48, 11);
        cout << " :::::.       .:.::::.              " << endl;
        goToXY(48, 12);
        cout << "::::::::.         .:::: " << endl;
        goToXY(48, 13);
        cout << "::::::::::.        .:::  " << endl;
        goToXY(48, 14);
        cout << ".::::::::.      .:::::: " << endl;
        goToXY(48, 15);
        cout << " ::::::::    .::::::::     " << endl;
        goToXY(48, 16);
        cout << "  ::::::..::::::::::.  " << endl;
        goToXY(48, 17);
        cout << "    .::::.:::::::.  " << endl;
        goToXY(48, 18);
        cout << "       ::.::::  " << endl;
        goToXY(45, 19);
        cout << ".----.  ----..-. .-. .---. .-. .-." << endl;
        goToXY(45, 20);
        cout << "{ {__  | {_  | | | |:   __}| { } |" << endl;
        goToXY(45, 21);
        cout << ".-._} }| {__ : :_/ /:  {_ }| {_} |" << endl;
        goToXY(45, 22);
        cout << "`----' `----' `---'  `---' `-----'" << endl;
        goToXY(50, 24);
        highlightMenuItem("Create list", menuIndex == 0);
        goToXY(50, 25);
        highlightMenuItem("Add an element", menuIndex == 1);
        goToXY(50, 26);
        highlightMenuItem("Remove any element", menuIndex == 2);
        goToXY(50, 27);
        highlightMenuItem("Display the list", menuIndex == 3);
        goToXY(50, 28);
        highlightMenuItem("Rewrite the field", menuIndex == 4);
        goToXY(50, 29);
        highlightMenuItem("Sort the list", menuIndex == 5);
        goToXY(50, 30);
        highlightMenuItem("Find node", menuIndex == 6);
        goToXY(50, 31);
        highlightMenuItem("Save the database", menuIndex == 7);
        goToXY(50, 32);
        highlightMenuItem("Refresh list", menuIndex == 8);
        goToXY(50, 33);
        highlightMenuItem("Proceed data", menuIndex == 9);

        // Handle up and down arrow key presses
        keyPressed = _getch();
        if (keyPressed == 80)
        { // Down arrow key
            menuIndex = (menuIndex + 1) % 10;
        }
        else if (keyPressed == 72)
        { // Up arrow key
            menuIndex = (menuIndex - 1 + 10) % 10;
        }
        else if (keyPressed == 13)
        { // Enter key
            switch (menuIndex)
            {
            case 0:
            {
                doublyLinkedList = createDoublyLinkedList();
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            }
            case 1:
                addElementToEnd(doublyLinkedList);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 2:
            {
                int position;
                cout << "Enter the position of the element to remove: ";
                cin >> position;
                Node *temp = doublyLinkedList;
                while (position > 1 && temp != NULL)
                {
                    temp = temp->next;
                    position--;
                }
                if (temp != NULL)
                {
                    removeElement(doublyLinkedList, temp);
                }
                else
                {
                    cout << "Invalid position!" << endl;
                }
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            }
            case 3:
                displayDoublyLinkedList(doublyLinkedList);
                cout << "\n\nPress enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 4:
                cout << "Enter the plant number you want to update: ";
                cin >> plantNumber;
                updateField(doublyLinkedList, plantNumber);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 5:
                bubbleSort(&doublyLinkedList);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 6:
                searchNode(doublyLinkedList);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 7:
                saveLinkedListToFile(doublyLinkedList);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 8:
                refreshList(doublyLinkedList);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            case 9:
                handleData(doublyLinkedList);
                goToXY(50, 15);
                cout << "Press enter to continue.............";
                cin.ignore();
                cin.get();
                break;
            }
        }
        else if (keyPressed == 27)
        { // Escape key
            shouldExit = true;
        }
    }
    return 0;
}