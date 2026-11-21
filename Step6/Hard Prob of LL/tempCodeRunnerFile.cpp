    if (!head || !head->next) return head;

        // Step 1: flatten the right side first
        head->next = flattenLinkedList(head->next);

        // Step 2: merge current list with flattened right list
        head = merge(head, head->next);

        return head;