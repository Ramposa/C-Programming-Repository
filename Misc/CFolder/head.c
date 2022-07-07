node *head = NULL;
node *temp = head;

while (temp ->next != NULL) {
    printf("%d\n",temp-->val);
    temp = temp->next;
}