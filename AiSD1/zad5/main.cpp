#include <iostream>
using namespace std;

int main() {
    int task;
    cin >> task;
    switch(task){
        case 1:{
            int value;
            bool one_present = false;
            cin >> value;
            
            for(unsigned int mask = 0x80000000; mask; mask >>= 1){
                if(value & mask) {
                    //jedynka
                    one_present = true;
                    cout << 1;
                }
                else {
                    //zero
                    if(one_present){
                        cout << 0; 
                    }
                }
            }
            break;
        }
        case 2:{
            unsigned int n;
            int mask = 1, count = 0, start = -1;
            cin >> n;

            while ((n & mask) == 0) {
                mask <<= 1;
            }

            unsigned int rightMostBitMask = 1 << 31;
            while ((n & rightMostBitMask) == 0) {
                rightMostBitMask >>= 1;
            }

            while (mask != rightMostBitMask) {
                mask <<= 1;
                if ((n & mask) != 0) {
                    if (start != -1) {
                        count += mask - start - 1;
                    }
                    start = mask;
                }
            }

            if (start != -1 && mask == rightMostBitMask) {
                count += 1;
            }

            cout << count << endl;

            break;
        }
        case 3:{
            unsigned int num;
            cin >> num;

            unsigned int rev = 0;
            unsigned int n = num;
            while (n != 0) {
                rev <<= 1;
                if (n & 1) {
                    rev |= 1;
                }
                n >>= 1;
            }

            cout << (rev == num);

            break;
        }
        default:{
            cout << "Wrong task number";
            break;
        }
    }
}