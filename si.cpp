#include <iostream>
#include "word.h"

using namespace std;

string make_outfile(string namefile);

int main(int argc, char* argv[])
{
        Word word;


        if (argc < 2) {
                cerr << "Usage: si origin.si [destination.cpp]" << endl;
                exit(EXIT_FAILURE);
        }
        else if (argc == 2) {
                ifstream inputFile(argv[1]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        string outfile = make_outfile(argv[1]);
                        word.set_out(outfile);
                }
        }
        else if (argc > 2) {
                ifstream inputFile(argv[1]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        word.set_out(argv[2]);
                }

        }

        word.set_in(argv[1]);
        word.write();

        word.close_files();
}

/* if no destination file is provided, this will take the
 * first argument and turn its contents in to the name
 * of the destination file in .cpp format
 */
string make_outfile(string namefile)
{
        string name = "";
        for (int i = 0; i < (int)namefile.length(); i++) {
                if (namefile[i] == '.') {
                        name = namefile.substr(0,i);
                        name += ".cpp";
                        break;
                }
        }
        if (name == "") {
                cerr << "No .si file found\n";
                exit(EXIT_FAILURE);
        }
        return name;
}
