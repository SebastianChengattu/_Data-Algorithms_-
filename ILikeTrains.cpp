// Sebastian Chengattu
//: Defines the entry point for the console application.

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// train car struct
struct TrainCar {
	int id;
	char type_of_car;
	/*
	p: passenger car, goes in front of train
	C: cargo, goes in the middle of tree
	M: miscellaneous, goes at the end of the train
	*/
	int number_of_stops;
};

// static variable for unique id of each train car
static int unique_id = 0;

class LinkedList {
	// Node structure, holds data
	struct Node {
		TrainCar *data;
		Node *next;
	};

public:
	// constructor
	LinkedList() {
		head = NULL;
	}

	// destructor
	~LinkedList() {
		Node *next = head;

		while (next) {
			Node *delete_node = next;
			next = next->next;
			delete delete_node;
		}
	}

	// add to front
	void addToFront(TrainCar *data) {
		cout << data->id << endl;
		Node *node = new Node();
		node->data = data;
		node->next = head;
		head = node;
	}

	// add to end
	void addToEnd(TrainCar *data) {
		Node *node = new Node();
		node->data = data;
		node->next = NULL;

		Node *iterator = head;

		// if linked list is empty
		if (iterator == NULL) {
			head = node;
		}
		else {
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			iterator->next = node;
		}
	}

	// add at index
	bool addAtIndex(TrainCar *data, int index) {
		Node *node = new Node();
		node->data = data;
		node->next = NULL;

		Node *iterator = head;
		int count = 0;

		try {
			while (count <= index) {
				if (count != index) {
					iterator = iterator->next;
					count++;
				}
				else {
					node->next = iterator->next;
					iterator->next = node;
					return true;
				}
			}
			return false;
		}
		catch (int ex) {
			return false;
		}
	}

	// remove from front
	TrainCar* removeFromFront() {
		if (head == NULL) {
			// do nothing since linked list is empty
			return NULL;
		}
		else {
			Node *iterator = head;
			head = head->next;

			TrainCar *tc = new TrainCar();
			tc->id = iterator->data->id;
			tc->type_of_car = iterator->data->type_of_car;
			tc->number_of_stops = iterator->data->number_of_stops;
			delete iterator;
			return tc;
		}
	}

	// remove from end
	TrainCar* removeFromEnd() {
		if (head == NULL) {
			// do nothing since linked list is empty
			return NULL;
		}
		else {
			Node *iterator = head;
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			TrainCar *tc = new TrainCar();
			tc->id = iterator->data->id;
			tc->type_of_car = iterator->data->type_of_car;
			tc->number_of_stops = iterator->data->number_of_stops;
			return tc;
		}
	}

	// remove first instance of T
	void removeTheFirst(TrainCar *data) {
		Node *iterator = head;
		if (iterator == NULL) {
			// do nothing since linked list is empty
		}
		// check if the first node has the data
		else if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
			head = iterator->next;
			delete iterator;
		}
		// else loop through the list and match data
		else {
			Node *previous = iterator;
			iterator = iterator->next;
			while (iterator->next != NULL) {
				if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
					previous->next = iterator->next;
					delete iterator;
					// break loop since we only delete first instance
					break;
				}
				else {
					previous = iterator;
					iterator = iterator->next;
				}
			}
		}
	}
	
	// removal all matches of data
	void removeAllOf(TrainCar *data) {
		Node *iterator = head;
		if (iterator == NULL) {
			// do nothing since linked list is empty
		}
		// check if the first node has the data
		else if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
			head = iterator->next;
			delete iterator;
		}
		// else loop through the list and match data
		else {
			Node *previous = iterator;
			iterator = iterator->next;
			while (iterator->next != NULL) {
				if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
					previous->next = iterator->next;
					delete iterator;
					// reassign iterator to the next node after iterator;
					iterator = previous->next;
				}
				else {
					previous = iterator;
					iterator = iterator->next;
				}
			}
		}
	}

	// element exists
	bool elementExists(TrainCar *data) {
		Node *iterator = head;
		if (iterator == NULL) {
			return false;
		}
		else {
			while (iterator->next != NULL) {
				if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
					return true;
				}
				else {
					iterator = iterator->next;
				}
			}
			return false;
		}
	}

	// find
	Node* find(TrainCar *data) {
		Node *iterator = head;
		if (iterator == NULL) {
			return NULL;
		}
		else {
			while (iterator->next != NULL) {
				if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
					return iterator;
				}
				else {
					iterator = iterator->next;
				}
			}
			return NULL;
		}
	}

	// index of
	int indexOf(TrainCar *data) {
		Node *iterator = head;
		int index = 0;
		if (iterator == NULL) {
			return -1;
		}
		else {
			while (iterator->next != NULL) {
				if (iterator->data->id == data->id && iterator->data->type_of_car == data->type_of_car && iterator->data->number_of_stops == data->number_of_stops) {
					return index;
				}
				else {
					iterator = iterator->next;
					index++;
				}
			}
			return -1;
		}
	}

	// retrieve front
	TrainCar* retrieveFront() {
		if (head != NULL) {
			TrainCar *tc = new TrainCar();
			tc->id = head->data->id;
			tc->type_of_car = head->data->type_of_car;
			tc->number_of_stops = head->data->number_of_stops;
			return tc;
		}
		else {
			return NULL;
		}
	}

	// retrieve end
	TrainCar* retrieveEnd() {
		Node *iterator = head;
		if (head == NULL) {
			return NULL;
		}
		else {
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			TrainCar *tc = new TrainCar();
			tc->id = iterator->data->id;
			tc->type_of_car = iterator->data->type_of_car;
			tc->number_of_stops = iterator->data->number_of_stops;
			return tc;
		}
	}

	// retrieve index
	TrainCar* retrieve(int index) {
		int count = 0;
		Node *iterator = head;
		if (iterator == NULL) {
			return NULL;
		}
		else {
			while (iterator->next != NULL) {
				if (count == index) {
					TrainCar *tc = new TrainCar();
					tc->id = iterator->data->id;
					tc->type_of_car = iterator->data->type_of_car;
					tc->number_of_stops = iterator->data->number_of_stops;
					return tc;
				}
				else {
					iterator = iterator->next;
					count++;
				}
			}
			return NULL;
		}
	}

	// to array
	vector<TrainCar*> toArray() {
		// use a vector to convert int linked list to a vector array
		vector<TrainCar*> ll_array;
		Node *iterator = head;
		if (iterator == NULL) {
			return ll_array;
		}
		else {
			while (iterator->next != NULL) {
				TrainCar *tc = new TrainCar();
				tc->id = iterator->data->id;
				tc->type_of_car = iterator->data->type_of_car;
				tc->number_of_stops = iterator->data->number_of_stops;
				ll_array.push_back(tc);
				iterator = iterator->next;
			}
			return ll_array;
		}
	}

	// empty
	void empty() {
		Node *iterator = head;
		Node *next;
		if (iterator == NULL) {
			// do nothing since linked list is empty
		}
		else {
			next = iterator->next;
			delete iterator;
			iterator = next;
		}
	}

	// length
	int length() {
		Node *iterator = head;
		if (iterator == NULL) {
			return 0;
		}
		else {
			int count = 0;
			while (iterator != NULL) {
				count++;
				iterator = iterator->next;
			}
			return count;
		}
	}

	// decrement all stops by 1
	void decrement() {
		Node *iterator = head;
		// do nothing if head is null
		if (iterator == NULL) {

		}
		else {
			while (iterator->next != NULL) {
				iterator->data->number_of_stops--;
				iterator = iterator->next;
			}
		}
	}

	// remove all train cars that have no more stops and print the values
	void removeZeroStops() {
		Node *iterator = head;
		// do nothing if head is null
		if (iterator == NULL) {

		}
		// check if the first node has no more stops
		else if (iterator->data->number_of_stops == 0) {
			head = iterator->next;
			cout << "[" << iterator->data->id << ":" << iterator->data->type_of_car << "]  removed" << endl;
			delete iterator;
		}
		// else loop through the list and match data
		else {
			Node *previous = iterator;
			iterator = iterator->next;
			while (iterator->next != NULL) {
				if (iterator->data->number_of_stops == 0) {
					cout << "[" << iterator->data->id << ":" << iterator->data->type_of_car << "]  removed" << endl;
					previous->next = iterator->next;
					delete iterator;
					// reassign iterator to the next node after iterator;
					iterator = previous->next;
				}
				else {
					previous = iterator;
					iterator = iterator->next;
				}
			}
		}
	}

	// print trains in order
	void printTrainCars() {
		Node *iterator = head;
		// do nothing if head is null
		if (iterator == NULL) {
			
		}
		// print
		else {
			while (iterator->next != NULL) {
				cout << "[" << iterator->data->id << ":" << iterator->data->type_of_car << ":" << iterator->data->number_of_stops << "] ";
				iterator = iterator->next;
			}
			cout << "[" << iterator->data->id << ":" << iterator->data->type_of_car << ":" << iterator->data->number_of_stops << "] ";
		}
	}
	
private:
	Node *head;	
};

int main()
{
	// initialize the train cars
	LinkedList ll;
	for (int i = 0; i < 10; i++) {
		unique_id++;
		int stops = rand() % 5 + 1;
		TrainCar *tc = new TrainCar();
		tc->id = unique_id;
		tc->number_of_stops = stops;

		// first car (passenger)
		if (i == 0) {
			tc->type_of_car = 'P';
			ll.addToFront(tc);
		}
		// end car
		else if (i == 9) {
			tc->type_of_car = 'M';
			ll.addToEnd(tc);
		}
		// middle car
		else {
			tc->type_of_car = 'C';
			ll.addToEnd(tc);
		}
	}
	
	ll.printTrainCars();
	cout << endl << endl;
	// ask user how many stops they want
	bool user_input = true;
	while (user_input) {
		int user_stops = 0;
		cout << "Enter number of stops (Enter 0 to end program): " << endl;
		cin >> user_stops;
		if (user_stops == 0) {
			break;
		}
		// iterate through each stop, display list, and decrement number of stops
		while (user_stops > 0) {
			cout << "Stop #" << user_stops << endl;
			cout << "Train Arriving: ";
			ll.printTrainCars();
			cout << endl;
			// decrement all stops by 1
			ll.decrement();
			cout << "Removing Cars: " << endl;
			// remove all train cars that have number of stops equal to 0
			ll.removeZeroStops();
			cout << "Adding Cars: " << endl;
			// add 5 random cars
			int random_cars = rand() % 5 + 1;
			for (int i = 0; i < random_cars; i++) {
				unique_id++;
				int stops = rand() % 5 + 1;
				TrainCar *tc = new TrainCar();
				tc->id = unique_id;
				tc->number_of_stops = stops;

				// determine which type of car is added
				int type_num = rand() % 3 + 1;
				// represents passenger car
				if (type_num == 1) {
					tc->type_of_car = 'P';
					ll.addToFront(tc);
					cout << "[" << tc->id << ":" << tc->type_of_car << ":" << tc->number_of_stops << "]  added" << endl;
				}
				// cargo car
				else if (type_num == 2) {
					tc->type_of_car = 'C';
					ll.addAtIndex(tc, 1);
					cout << "[" << tc->id << ":" << tc->type_of_car << ":" << tc->number_of_stops << "]  added" << endl;
				}
				// misc car
				else {
					tc->type_of_car = 'M';
					ll.addToEnd(tc);
					cout << "[" << tc->id << ":" << tc->type_of_car << ":" << tc->number_of_stops << "]  added" << endl;
				}
			}
			cout << "Train Exiting: ";
			ll.printTrainCars();
			cout << endl;

			user_stops--;
		}
	}	
}

