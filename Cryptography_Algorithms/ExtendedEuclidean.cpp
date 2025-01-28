#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, m;

    // User input for the number and modulus
    cout << "Enter a number to find its modular inverse: ";
    cin >> a;
    cout << "Enter the modulus (m): ";
    cin >> m;

    // Initialize values
    int q, r1, r2, r, t1, t2, t;

    // Initial values for r1, r2, t1, t2
    r1 = a;
    r2 = m;
    t1 = 1;  // t1 starts as 1 (corresponding to 'a')
    t2 = 0;  // t2 starts as 0 (corresponding to 'b')

    // Print the table headers
    cout << setw(4) << "q" << " | " 
         << setw(3) << "r1" << " | " 
         << setw(3) << "r2" << " | " 
         << setw(3) << "r"  << " | " 
         << setw(3) << "t1" << " | " 
         << setw(3) << "t2" << " | " 
         << setw(3) << "t"  << endl;
    
    cout << "-----------------------------------------" << endl;

    // Loop to calculate GCD and keep track of the values
    while (r2 != 0) {
        q = r1 / r2;       // Quotient
        r = r1 % r2;       // Remainder
        t = t1 - q * t2;   // New t value

        // Print the current state in the table format
        cout << setw(4) << q << " | " 
             << setw(3) << r1 << " | " 
             << setw(3) << r2 << " | " 
             << setw(3) << r  << " | " 
             << setw(3) << t1 << " | " 
             << setw(3) << t2 << " | " 
             << setw(3) << t  << endl;

        // Update values for the next iteration
        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }

    // The GCD will be r1 when the loop ends
    int gcd = r1;

    // Check if modular inverse exists
    if (gcd != 1) {
        cout << "No modular inverse exists for " << a << " mod " << m << endl;
    } else {
        // Ensure the result is positive
        int modInverse = (t1 % m + m) % m;
        cout << "The modular inverse of " << a << " mod " << m << " is: " << modInverse << endl;
    }

    return 0;
}


// Enter a number to find its modular inverse: 3
// Enter the modulus (m): 7
//   q  | r1  | r2  | r   | t1  | t2  | t  
// -----------------------------------------
//   0  |   3 |   7 |   3 |   1 |   0 |   1
//   2  |   7 |   3 |   1 |   0 |   1 |  -2
//   3  |   3 |   1 |   0 |   1 |  -2 |   7
// The modular inverse of 3 mod 7 is: 5
