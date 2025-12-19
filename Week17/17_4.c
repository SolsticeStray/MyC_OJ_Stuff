#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long id;
    int grade;
    struct Node* next;
} Node;

Node* create_node(long id, int grade) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->grade = grade;
    new_node->next = NULL;
    return new_node;
}

void insert_sorted(Node** head, long id, int grade) {

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->id < id) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->id == id) {
        if (current->grade < grade) {
            current->grade = grade;
        }
        return;
    }

    Node* new_node = create_node(id, grade);

    if (prev == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        new_node->next = prev->next;
        prev->next = new_node;
    }

}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%ld %d\n", current->id, current->grade);
        current = current->next;
    }
}

int main(void) {

    Node* head = NULL;
    long id;
    int grade;

    while (scanf("%ld %d", &id, &grade) == 2) {
        if (id==0) break;
        insert_sorted(&head, id, grade);
    }

    display(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}