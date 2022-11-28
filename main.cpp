#include <iostream>
#include <cstring>
#include <fstream>
#define MAX_SIZE 10000

using std::cout;
using std::cin;

int main(int argc, char ** argv){
    //std::cout << "You can use the --from file or/and --tofile flags if you want to use files for input or/and output. There should be a file name after each flag.\n" ;
    const char* from_file = "-1";
    const char* to_file = "-1";

    if (argc == 1) {
        cout << "Whitoutfiles";
    }
    else if (argc % 2 == 0 || argc > 5) {
        std::cerr << "Incorrect format for flags";
        return EXIT_FAILURE;
    }
    else if (argc == 3) {
        if (std::strcmp(argv[1], "--fromfile") == 0){
            cout << "from " << argv[2] << " file";
            from_file = argv[2];
        }
        else if (std::strcmp(argv[1], "--tofile") == 0){
            cout << "to " << argv[2] << " file";
            to_file = argv[2];
        }
        else {
            std::cerr << "Incorrect format for flags";
            return EXIT_FAILURE;
        }
    }
    else if (argc == 5) {
        if (std::strcmp(argv[1], "--fromfile") == 0 and std::strcmp(argv[3], "--tofile") == 0){
            cout << "from " << argv[2] << " file";
            from_file = argv[2];
            cout << "to " << argv[4] << " file";
            to_file = argv[4];
        }
        else if (std::strcmp(argv[1], "--tofile") == 0 and std::strcmp(argv[3], "--fromfile") == 0 ){
            cout << "from " << argv[4] << " file";
            from_file = argv[4];
            cout << "to " << argv[2] << " file";
            to_file = argv[2];
        }
        else {
            std::cerr << "Incorrect format for flags";
            return EXIT_FAILURE;
        }
    }


    char token = ' ';
    int SZ = 0, dots_cnt = 0;
    char *s = new char [MAX_SIZE];
    int *periods = new int [MAX_SIZE];

    if (from_file != "-1") {
        FILE* fp;
        int j = 0;
        fp = fopen(from_file, "r");
        while ((s[j] = fgetc(fp)) != EOF) {
            j++;
        }
        s[j] = '\0';
        fclose(fp);
    }
    
    
    if (from_file == "-1") {
        std::cout << "Enter text. \nTo mark the end of input, type '@' and press Enter.\n" << std::endl;
        std::cin.getline(s, 1024, '@');
    }

    cout << '\n';
    for (int i = 0; i < std::strlen(s); ++i) {
        cout << s[i];
    }

    cout << "\nDone!";

    delete [] s;
    delete [] periods;

    return 0;
}