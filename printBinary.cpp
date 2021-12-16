/**
 * Author: Vincent X
 * Date:   2021-12-16
 * 
 * Prints every binary number that has
 * exactly the given number of digits.
 */

#include <iostream>

using namespace std;

/* Splits into 2 calls (thus 2 prefices) every function call
 * Calls accumulate 0s and 1s in every prefix separately! 
 * Prefix is like a time machine / accumulator.
 * When digits == 2:
 *                 ""
 *               /   \
 *             "0"    "1"
 *             / \    /  \
 *           "0" "1" "0" "1" 
 * 
 * At the bottom calls, we got 4 prefices:
 * In the order:  "00"  "01"  "10"  "11"
 * 
 * Another view:
 * printBinary(2, "")
 *      printBinary(1, "0")
 *          printBinary(0, "00")
 *          printBinary(0, "01")
 *      printBinary(1, "1")
 *          printBinary(0, "10")
 *          printBinary(0, "11")
 */           

void printBinary(int digits, string prefix = "") {
    if (digits == 0) {
        cout << prefix << endl;     
    } else {    
        printBinary(digits - 1, prefix + "0");       
        printBinary(digits - 1, prefix + "1");
    }
}

int main() {

    printBinary(3);
      
    return 0;
}