#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>

void initialize(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        exit(EXIT_FAILURE);
    }


    int fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor < 0)
    {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }

    dup2(fileDescriptor, STDIN_FILENO);
    close(fileDescriptor);
}


int main(int argc, char** argv)
{
    initialize(argc, argv);

    std::string input;
    std::cin >> input;

    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;
    return 0;
}

