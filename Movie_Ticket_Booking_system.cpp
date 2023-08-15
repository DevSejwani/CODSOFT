#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 10.0;

vector<vector<bool>> seatAvailability(NUM_ROWS, vector<bool>(NUM_COLS, true));

map<int, string> movieListing = {
    {1, "Avengers: Endgame"},
    {2, "The Lion King"},
    {3, "Inception"}
};

void displaySeats() {
    cout << "   ";
    for (int col = 0; col < NUM_COLS; ++col) {
        cout << " " << col + 1;
    }
    cout << endl;

    for (int row = 0; row < NUM_ROWS; ++row) {
        cout << " " << char('A' + row) << " ";
        for (int col = 0; col < NUM_COLS; ++col) {
            if (seatAvailability[row][col]) {
                cout << " O"; // Available seat
            } else {
                cout << " X"; // Booked seat
            }
        }
        cout << endl;
    // ... (same as before)
}
}

double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    char row;
    int col;
    int numTickets;
    int movieChoice;

    while (true) {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Available Movies:\n";
                for (const auto& movie : movieListing) {
                    cout << movie.first << ". " << movie.second << endl;
                }
                break;
            case 2:
                displaySeats();
                cout << "Enter the movie number: ";
                cin >> movieChoice;

                if (movieListing.find(movieChoice) != movieListing.end()) {
                    cout << "Enter the row (A-E) and column (1-5) of the seat: ";
                cin >> row >> col;

                if (row >= 'A' && row <= 'E' && col >= 1 && col <= 5) {
                    if (seatAvailability[row - 'A'][col - 1]) {
                        cout << "Enter the number of tickets: ";
                        cin >> numTickets;

                        double totalCost = calculateTotalCost(numTickets);

                        cout << "Total cost: $" << totalCost << endl;
                        cout << "Confirm booking? (Y/N): ";
                        char confirm;
                        cin >> confirm;

                        if (confirm == 'Y' || confirm == 'y') {
                            seatAvailability[row - 'A'][col - 1] = false;
                            cout << "Booking confirmed. Enjoy the movie!\n";
                        } else {
                            cout << "Booking canceled.\n";
                        }
                    } else {
                        cout << "Selected seat is already booked. Please choose another seat.\n";
                    }
                } else {
                    cout << "Invalid row or column.\n";
                }
                } else {
                    cout << "Invalid movie choice.\n";
                }
                break;
            case 3:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid option. Please select a valid option.\n";
        }
    }

    return 0;
}
