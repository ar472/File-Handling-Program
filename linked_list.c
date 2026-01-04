#include <stdio.h>
#include <stdlib.h>

/* --------- Structure of Node --------- */
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* --------- Function to Insert at End --------- */
void insert()
{
    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

/* --------- Function to Delete a Node --------- */
void delete()
{
    struct Node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    /* If first node is to be deleted */
    if (temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found in list.\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
    }
}

/* --------- Function to Display Linked List --------- */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* --------- Main Function --------- */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
