import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {
    private Node root = null;

    public Node insert(Node root, int val) {
        if (root == null) {
            return new Node(val);
        }
        if (val >= root.data) {
            root.right = insert(root.right, val);
        } else {
            root.left = insert(root.left, val);
        }
        return root;
    }

    public void preOrder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + "\t");
        preOrder(root.left);
        preOrder(root.right);
    }

    public void inOrder(Node root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        System.out.print(root.data + "\t");
        inOrder(root.right);
    }

    public void postOrder(Node root) {
        if (root == null) {
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data + "\t");
    }

    public Node search(Node root, int val) {
        if (root == null || root.data == val) {
            return root;
        }
        if (root.data < val) {
            return search(root.right, val);
        }
        return search(root.left, val);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree tree = new BinaryTree();
        int ch, val;

        while (true) {
            System.out.print("\t\tBINARY TREE\n 1. Insert\n 2. Inorder traversal\n 3. Preorder traversal\n 4. Postorder traversal\n 5. Search\n 6. Exit");
            System.out.print("\nEnter your choice: ");
            ch = scanner.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("\nEnter the number: ");
                    val = scanner.nextInt();
                    tree.root = tree.insert(tree.root, val);
                    break;

                case 2:
                    System.out.println("Inorder Traversal: ");
                    tree.inOrder(tree.root);
                    System.out.println();
                    break;

                case 3:
                    System.out.println("Preorder Traversal: ");
                    tree.preOrder(tree.root);
                    System.out.println();
                    break;

                case 4:
                    System.out.println("Postorder Traversal: ");
                    tree.postOrder(tree.root);
                    System.out.println();
                    break;

                case 5:
                    System.out.print("\nEnter the value to search: ");
                    val = scanner.nextInt();
                    Node result = tree.search(tree.root, val);
                    if (result != null) {
                        System.out.println("Value found in the tree.");
                    } else {
                        System.out.println("Value not found in the tree.");
                    }
                    break;

                case 6:
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid input");
                    break;
            }
        }
    }
}
