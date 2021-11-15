#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int i, j;
    bitset<8> a, b;	    // for storing 8 bits
    a = 25;
    b = 45;
    cout << "a     = " << a << endl;	// 00011001
    cout << "b     = " << b << endl;	// 00101101
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "bit 3 of b is: " << b[3] << endl;

    bitset<10> catalog[8];
    catalog[0] = 0b1010010011;
    catalog[1] = 0b0000011011;
    catalog[2] = 0b0001111110;
    catalog[3] = 0b0000010011;
    catalog[4] = 0b1000010010;
    catalog[5] = 0b1101110110;
    catalog[6] = 0b0101011010;
    catalog[7] = 0b0011011111;

    printf("                    shows/movies\n");
    printf("                     9876543210\n");
    printf("                     ----------\n");

    for (i=0; i<8; i++) {
        cout << "streaming service " << i << ": " << catalog[i] << endl;
    }

    bitset<10> ans;
    ans.set();	// set all 10 bits to 1
    for (i=0; i<8; i++) {
        ans = ans & catalog[i];
    }
    printf("                     ----------\n");
    cout << "& result             " << ans << endl;

    ans = catalog[3] | catalog[6] | catalog[7];
    cout << "3 | 6 | 7 result     " << ans << endl;

    ans = catalog[3] | catalog[5] | catalog[7];
    cout << "3 | 5 | 7 result     " << ans << endl << endl;

    bitset<8> transpose[10];
    for (i=0; i<8; i++)
        for (j=0; j<10; j++)
            transpose[j][i] = catalog[i][j];

    printf("           streaming service\n");
    printf("           76543210\n");
    printf("           --------\n");
    for (i=0; i<10; i++) {
        cout << "movies " << i << ":  ";
        cout << transpose[i] << endl;
    }
    bitset<8> ans2 = transpose[4] & transpose[5] & transpose[6];
    printf("           --------\n");
    cout << "4 & 5 & 6: " << ans2 << endl;


    bitset<31> catalog2[10];
    catalog2[0] = 0b1010010011011000111001010101110;
    catalog2[1] = 0b0000011011110101100110100001010;
    catalog2[2] = 0b0001101110010110111110000000011;
    catalog2[3] = 0b0000000011100010110110011010110;
    catalog2[4] = 0b1000010000101100000001010110011;
    catalog2[5] = 0b1101110110101111001000000010001;
    catalog2[6] = 0b0101001010110011011011100010101;
    catalog2[7] = 0b0011011101100101101101101101011;
    catalog2[8] = 0b1101101101011101000111010100010;
    catalog2[9] = 0b0100011101000011000010001000111;

    return 0;
}
