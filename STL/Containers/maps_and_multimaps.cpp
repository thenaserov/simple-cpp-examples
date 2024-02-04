#include <iostream>
#include <map>

int main() {
	// A map is an associative container that stores pairwise elements
	// Each element has a key and value
	// This Key -> Value association allows you to access elements by "name"
	// instead of simply by index or position

	// Accessor m
    // ------------------------------------------------------------------------------------------------------------------------
    // |     Contaianer      |   Associative  |   Oerdered  |    Mapped    |    Unique Keys    |    Hashing    |   Dynamic    | 
    // |        map          |        x       |      x      |       x      |         x         |               |       x      | 
    // |      multimap       |        x       |      x      |       x      |                   |               |       x      |
    // |    unordered_map    |        x       |             |       x      |                   |       x       |       x      |
    // | unnordered_multimap |        x       |             |       x      |         x         |       x       |       x      |
    // |----------------------------------------------------------------------------------------------------------------------|

	// *** MAP and UNORDERED_MAP only accept UNIQUE keys
	
	// Map containers are generally slower thann unordered_map containers to access 
	// individual elements by their key, nut they allow direct iteration on subsets based on their order.
	
	//Maps only allow unique keys, and will overwrite or reject insertions with the same key depending
	// on how the operation was performed.

	// *** In multimaps you can have multiple equivalent keys.
	// Multimaps also do not implement the operator []() functionality, you must use multimap::find()
	// to find the key you want!
	// find : will return the first element found by key.
	
	

	return 0;
}
