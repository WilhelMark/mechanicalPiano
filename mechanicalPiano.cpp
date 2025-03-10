#include <iostream>
#include <string>

// Define an enumeration for the notes, each note is represented by a unique bitmask
enum Note {
    DO = 1,   // 00000001 in binary
    RE = 2,   // 00000010 in binary
    MI = 4,   // 00000100 in binary
    FA = 8,   // 00001000 in binary
    SOL = 16, // 00010000 in binary
    LA = 32,  // 00100000 in binary
    SI = 64   // 01000000 in binary
};

int main() {
    // Prompt the user to enter a chord
    std::cout << "Enter a chord (a sequence of digits from 1 to 7): ";
    std::string chord;
    std::cin >> chord;

    // Initialize the bitmask for the chord
    int chordMask = 0;

    // Iterate over each character in the input string
    for (char c : chord) {
        // Convert the character to an integer (note index)
        int noteIndex = c - '1'; // Subtract '1' to convert from char to int (0-based index)

        // Check if the note index is valid (0 to 6)
        if (noteIndex >= 0 && noteIndex <= 6) {
            // Create the bitmask for the current note using left shift
            int noteMask = 1 << noteIndex;

            // Combine the current note's bitmask with the chord's bitmask
            chordMask |= noteMask;
        }
    }

    // Output the notes in the chord based on the bitmask
    std::cout << "The chord contains the following notes: ";

    // Check each note and print it if the corresponding bit is set in the chordMask
    if (chordMask & DO) {
        std::cout << "DO ";
    }
    if (chordMask & RE) {
        std::cout << "RE ";
    }
    if (chordMask & MI) {
        std::cout << "MI ";
    }
    if (chordMask & FA) {
        std::cout << "FA ";
    }
    if (chordMask & SOL) {
        std::cout << "SOL ";
    }
    if (chordMask & LA) {
        std::cout << "LA ";
    }
    if (chordMask & SI) {
        std::cout << "SI ";
    }

    std::cout << std::endl;

    return 0;
}