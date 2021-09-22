//  s184v1 - input processing/parsing snippet
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int N, M;

int main() {
    int i, sent_len;
    string sentence, pattA, pattB, wordA, wordB;
    string words[26];
    /***** Load dictionary for language A and language B from inputs *****/
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> wordA >> wordB;
        // do something to construct a dictionary for translation tasks later
        // ....
    }
    /***** carry out the translation tasks *****/
    cin >> M;
    for (i=0; i<M; i++) {
        getline(cin, sentence); // read the unprocessed "\n" character from above
        getline(cin, sentence); // this reads the actual sentence
        // parse sentence into words[]
        istringstream iss(sentence);
        sent_len = 0;
        while (iss >> words[sent_len]) {    // this is where the magic of sstream happens
            sent_len++;
        }
        // now print out words to see if we correctly parsed the sentence into words
        for (i=0; i<sent_len; i++)
            cout << words[i] << ",";
        cout << endl;

        cin >> pattA >> pattB;
        // translate words from language A to language B
        // .....
    }
    return 0;
}
