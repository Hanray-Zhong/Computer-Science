package Demo;

public class Test {

	public ListNode head;
    public ListNode current;


	public static void main(String[] args) {
		


		for(int i = 0; i < 4; i++){
			
		}


	}

	public void add(int data) {
        if(head == null) {
            head = new ListNode(data);
            current = head;
        } else {
            current.next = new ListNode(data);
            current = current.next;
        }
	}
	
	public void print(ListNode node) {
        if(node == null) {
            return;
        }

        current = node;
        while(current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }

}
