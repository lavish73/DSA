#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL; // Initialize head to NULL
    int numElements, value;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    // Get the values for the nodes from the user
    for (int i = 0; i < numElements; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }

    // Display the linked list
    printf("Linked List:\n");
    displayList(head);

    // Free the allocated memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
