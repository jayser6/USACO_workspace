package othercode.linkedlists;

class LinkedList {
    Node root;

    // add a new node at the end of the linked list
    void add(int value) {
        if (root == null) {
            /* the root was previously empty */

            root = new Node(value);
            root.next = null;
        } else {
            Node curr = root;

            while (curr.next != null)
                curr = curr.next;

            curr.next = new Node(value);
            curr.next.next = null;
        }
    }
}

class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
    }
}