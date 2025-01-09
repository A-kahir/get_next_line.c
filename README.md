# Get Next Line Project

## 🚀 Overview
The **Get Next Line** project at 42 School focuses on developing a function that reads a file line by line, using a file descriptor. It’s designed to help you master file input/output (I/O) operations, work with static variables, and efficiently manage memory and buffers in C programming.

## 🎯 Objectives
By completing this project, you will:
- **Understand File Descriptors**: Learn how to read data line by line from a file descriptor.
- **Work with Static Variables**: Implement static variables to maintain state across function calls.
- **Master Buffer Management**: Efficiently manage buffers when reading large files in chunks.

## 🛠️ Project Requirements
In this project, you will:
- **Implement a Function**: Create a `get_next_line` function that reads a single line from a file descriptor.
- **Handle Multiple Files**: Make sure your function can manage multiple file descriptors at once.
- **Detect EOF Properly**: Ensure the function detects the end of the file and returns `NULL` when no more lines are available.

## 📦 Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/A-kahir/get_next_line.git
    cd get_next_line
    ```

2. **Compile the project using Make:**

    ```bash
    make
    ```

3. **The `get_next_line` function is now ready to use.**

## 🔧 Usage

To use the `get_next_line` function, include the header file and call the function to read a line from a file descriptor.

```c
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);  // Open the file
    char *line;

    // Read each line
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);  // Output the line
        free(line);  // Free the allocated memory
    }

    close(fd);  // Close the file
    return 0;
}
```
📚 Resources
GitHub Repository - mcombeau/get_next_line
42 Documentation: get_next_line
Tutorial: Master File I/O Operations with 42's Get Next Line Project
GET NEXT LINE: A 42 Project to Learn How to Deal with File Descriptors and I/O of System
🎥 Video Learning
For a more visual explanation, check out the following video:

Get Next Line 42 | Part 1

