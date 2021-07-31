#include <stdio.h>
//queue implementation using circular array

//using a small array, for the clearness of the example
#define SIZE 4  //constant

int vector[SIZE];

int front = -1;
int back = -1;


bool isFull() {
	if ((front == back + 1) || (front == 0 && back == SIZE - 1)) {
		return true;

	}
	else //optional
		return false;
}


bool isEmpty() {
	if (front == -1) {
		return true;
	}
	else
		return false;
}


void Enqueue(int el) {
	if (isFull()) {
		printf("Queue is full\n");

	}
	else {
		if (front == -1) { //from initial, + 1
			front = 0;
		}

		back = (back + 1) % SIZE; //circular
		vector[back] = el; //inserted
		


		printf("Inserted: %d\n", el);
	}
}



int Dequeue() {
	int el;
	if (isEmpty()) {
		printf("Empty queue\n");
		return -1;
	}
	else {
		el = vector[front]; //need to return the useful info
		if (front == back) {
			front = back = -1;
			
		}
		else {
			front = (front + 1) % SIZE;
		}

		


		printf("Deleted: %d\n", el);  //display, but also return
		return el;
	}

}


void displayQueue(){
	int i;
	if (isEmpty()) {
		printf("Empty queue\n");
		
	}
	else {
		
		printf("Items: ");
		for (i = front; i != back; i = (i + 1) % SIZE) {
			printf("%d  ", vector[i]);
		}
		printf("%d \n", vector[i]); //don't forget, back
		
	}
}


int main() {


	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);



	Enqueue(5); //full

	displayQueue();

	Dequeue();

	displayQueue();

	Enqueue(5);
	displayQueue();

	Enqueue(6); //full again

	Dequeue(); 
	Dequeue();
	Dequeue();
	Dequeue();
	displayQueue(); //empty
	
}