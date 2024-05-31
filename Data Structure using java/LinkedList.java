import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList {
    private Node head = null;

    public void insertAtBeg() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the number of elements to be added: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter data: ");
            int item = scanner.nextInt();
            Node newNode = new Node(item);
            newNode.next = head;
            head = newNode;
        }
        display();
    }

    public void insertAtEnd() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the number of elements to be added: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter data: ");
            int data = scanner.nextInt();
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
            } else {
                Node temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }
        }
        display();
    }

    public void insert() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter data: ");
        int data = scanner.nextInt();
        Node newNode = new Node(data);
        System.out.print("\nEnter the location you want to insert the data: ");
        int loc = scanner.nextInt();
        if (loc == 0) {
            newNode.next = head;
            head = newNode;
        } else {
            Node temp = head;
            for (int i = 0; i < loc - 1; i++) {
                if (temp != null) {
                    temp = temp.next;
                }
            }
            if (temp == null) {
                System.out.println("\nCan't insert");
            } else {
                newNode.next = temp.next;
                temp.next = newNode;
            }
        }
        display();
    }

    public void deleteBeg() {
        if (head == null) {
            System.out.println("\nLinked list is empty");
        } else {
            head = head.next;
            display();
        }
    }

    public void deleteEnd() {
        if (head == null) {
            System.out.println("\nLinked list is empty");
        } else if (head.next == null) {
            head = null;
            display();
        } else {
            Node temp = head;
            while (temp.next.next != null) {
                temp = temp.next;
            }
            temp.next = null;
            display();
        }
    }

    public void deletePos() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the position to be deleted: ");
        int pos = scanner.nextInt();
        if (head == null) {
            System.out.println("\nLinked list is empty");
        } else if (pos == 0) {
            head = head.next;
            display();
        } else {
            Node temp = head;
            for (int i = 0; i < pos - 1; i++) {
                if (temp != null) {
                    temp = temp.next;
                }
            }
            if (temp == null || temp.next == null) {
                System.out.println("\nCan't delete");
            } else {
                temp.next = temp.next.next;
                display();
            }
        }
    }

    public void search() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the data to be searched: ");
        int data = scanner.nextInt();
        Node temp = head;
        int index = 0;
        while (temp != null) {
            if (temp.data == data) {
                System.out.println("\nData found at the index: " + index);
                return;
            }
            temp = temp.next;
            index++;
        }
        System.out.println("\nData not found");
    }

    public void display() {
        if (head == null) {
            System.out.println("\nLinked list is empty");
        } else {
            Node temp = head;
            System.out.print("\nLinked list elements are: ");
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n\n*********Main Menu*********\n");
            System.out.println("Choose one option from the following list ...");
            System.out.println("\n===============================================\n");
            System.out.println("1. Insert in beginning");
            System.out.println("2. Insert at last");
            System.out.println("3. Insert at any random location");
            System.out.println("4. Delete from Beginning");
            System.out.println("5. Delete from last");
            System.out.println("6. Delete node after specified location");
            System.out.println("7. Search for an element");
            System.out.println("8. Show");
            System.out.println("9. Exit");
            System.out.print("\nEnter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    list.insertAtBeg();
                    break;
                case 2:
                    list.insertAtEnd();
                    break;
                case 3:
                    list.insert();
                    break;
                case 4:
                    list.deleteBeg();
                    break;
                case 5:
                    list.deleteEnd();
                    break;
                case 6:
                    list.deletePos();
                    break;
                case 7:
                    list.search();
                    break;
                case 8:
                    list.display();
                    break;
                case 9:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("\nPlease enter a valid choice..");
                    break;
            }
        } while (choice != 9);
        scanner.close();
    }
}
