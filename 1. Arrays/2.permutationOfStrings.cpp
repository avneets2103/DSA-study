#include <iostream>
#include <string>
using namespace std;

void generate_permutations(string str, int start_index, int end_index) {
    // Base case: if start_index and end_index are equal, we have found a permutation
    if (start_index == end_index) {
        cout << str << endl;
        return;
    }

    // Recursive case: generate all permutations of the string
    for (int i = start_index; i <= end_index; i++) {
        // Swap the characters at positions start_index and i
        swap(str[start_index], str[i]);

        // Generate all permutations of the substring starting at start_index+1
        generate_permutations(str, start_index+1, end_index);

        // Swap the characters back to restore the original string
        swap(str[start_index], str[i]);
    }
}

// what we are doing here is to generate all permutations of the string starting at start_index and end_index as end.
// we are just making a lil chnages in the string, we reach the end of the string and print the full string
// then we get back to the upper waiting function
// where we swap the string characters at positions start_index and i and print that string and then get back, 
// to undo the changes we swap them back and this continues

// this completely follows the state-space tree 

int main() {
    string str = "abc";
    int n = str.length();

    // Call the generate_permutations function
    generate_permutations(str, 0, n-1);

    return 0;
}
