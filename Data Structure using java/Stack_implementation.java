import java.util.Scanner;
class Stack <T>{
    private T array[];
    private int top=-1,size,n=-1;

    Stack(int size){
        this.size=size;
        this.array=(T[]) new Object[size];
    }

    void push(T val){
        if(top==(size-1)){
            System.out.println("Stack Overflow");
        }
        else{
            this.array[++this.top]=val;
            this.n=top;
        }
    }

    T pop(){
        if(top==-1){
            System.out.println("Stack underflow");
            return null;
        }
        else{
            n-=1;
            return this.array[this.top--];
        }
    }

    void display(){
        for(int i=0;i<=this.n;i++){
            System.out.print(array[i]+"\t");
        }
    }

    T peek(){
        return this.array[this.top];
    }

    void isfull(){
        if(top==(this.size-1)){
            System.out.println("Stack is full");
        }
        else{
            System.out.println("Stack is not full");
        }
    }

    void isempty(){
        if(top==(-1)){
            System.out.println("Stack is empty");
        }
        else{
            System.out.println("Stack is not empty");
        }
    }

}

class Stack_implementation{
    public static void main(String[] args) {
        Scanner inp=new Scanner(System.in);
        int size,ch=0;
        String val,dtype;
        System.out.print("Enter size of the array: ");
        size=inp.nextInt();
        Stack<String> stack=new Stack<>(size);
        while(true){
            System.out.println("\n\n\t\tSTACK MENU\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Is full\n 6. Is empty\n 7. Exit");
            System.out.print("Enter your choice: ");
            ch=inp.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Enter the value to be added: ");
                    val=inp.next();
                    stack.push(val);
                    break;

                case 2:
                    System.out.println("Poped data: "+stack.pop());
                    break;

                case 3:
                    System.out.println("Peek value: "+stack.peek());
                    break;

                case 4:
                    System.out.println("Stack values: ");
                    stack.display();
                    break;
                
                case 5:
                    stack.isfull();
                    break;

                case 6:
                    stack.isempty();
                    break;

                case 7:
                    return;
            
                default:
                    System.out.println("Invalid Input");
                    break;
            }
        }
        
    }
}