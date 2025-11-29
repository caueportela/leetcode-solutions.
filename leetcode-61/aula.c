#include <stdio.h>
#include <stdlib.h>
 

// struct da lista
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *rotateMore(struct ListNode *head) {
                                                      
    struct ListNode *slow = NULL; 
    struct ListNode *fast = head; 
    
    if (head == NULL || head->next == NULL) {
        return head;  
    }   

    while (fast->next != NULL) { 
        slow = fast; 
        fast = fast->next; 
    }
   
    slow->next = NULL; 
    fast->next = head;  
    head = fast; 

    return head; 
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }  
 
    if (k == 0) {  
        return head;
    }

    int n = 0; 
    struct ListNode *fast = head; 

    while (fast != NULL) {
        n++; 
        fast = fast->next; 
     
    }
     
    for (int i = 0; i < k; i++) { 
        head = rotateMore(head);
    } 

    return head; 
}

void freeList(struct ListNode *head) {
    struct ListNode *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {


    int values[] = {1,2,3,4,5};
    int n = sizeof(values) / sizeof(values[0]);

    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = values[i];
        node->next = NULL;

        if (head == NULL) {
            head = node;
            curr = node;
        } else {
            curr->next = node;
            curr = curr->next;
        }
    }

    printf("original list: ");
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    int k = 300;
    head = rotateRight(head, k);

    printf("Rotate for %d: ", k);
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    freeList(head);
    return 0;
}
