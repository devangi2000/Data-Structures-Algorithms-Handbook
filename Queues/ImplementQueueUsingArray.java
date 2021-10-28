class MyQueue {

    int front, rear;
	int arr[] = new int[100005];

    MyQueue()
	{
		front=0;
		rear=0;
	}
	
	void push(int x)
	{
	    if(rear >= 100000)
	        return;
	    arr[rear++] = x;
	} 

    //Function to pop an element from queue and return that element.
	int pop()
	{
		return front == rear ? -1 : arr[front++];
	} 
}
