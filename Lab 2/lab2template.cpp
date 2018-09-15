#include <iostream>

using namespace std;

// Put your prototypes here, there should be several,
// one for every function that you write.
//
// Two are given to get you started.

void arrayCountdown(int *outputArray, int elements);
void subtractNumbers();

int main()
{
	char userResponse;

	// The user's menu should go here.  It should use
	// a loop.  Remember to use some sort of bool variable
	// or a comparison to tell when you should end the loop.

	// HINT: a for loop is NOT a good idea for this.
	// HINT: Look at page 252 in your text book.

	// Since main() is an int-type function, return an int,
	// in this case 0.

	return 0;
}

// I have included all of the menu functions here for you.  Remember
// to make sure they have prototypes.  Also remember that the lab
// assignment asks you to write a few more functions than these.

void subtractNumbers()
{

}

void countingArray()
{
	// You will need more variables than this, but
	// these are essential.  The i variable is used
	// to increment the loop.

	int numbersToAdd[10];
	int i;
	char userResponse;

	for (i=0;i<10;i++) {
		// Initialize the array elements here
	}

	// Now, you need to write a loop that will ask
	// the user if they want to put in a new number.
	// If they do, then you need to put that number
	// in the array.  REMEMBER you need to keep
	// count of how many elements of the array have
	// been used, AND you need to correctly place
	// the array element. The array does NOT start at
	// element 1, it starts at element 0, and the
	// last element is NOT numbersToAdd[10], it is
	// numbersToAdd[9].

	// Once you have that done, write another loop
	// to add up the sum and print it out.

}

void multiplicationTable()
{
	// declare a two-dimensional array of ints here
	// Then have two loops, nested (one inside the
	// other).  Calculate the contents of the
	// array.

	// Then use another set of nested loops to
	// print the array contents.
}

void castToShort()
{
	// remember to use static_cast for this!
}

void runCuntdown()
{
	// use arrayCountdown() to fill up an array,
	// and then print the contents of each
	// element of the array.
}
