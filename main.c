#include "get_next_line.h"

// int main()
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     // int fd2 = open("file2.txt", O_RDONLY);
//     // int fd3 = open("file3.txt", O_RDONLY);

//     char *str1 = get_next_line(fd1);
//     // char *str2 = get_next_line(fd2);
//     // char *str3 = get_next_line(fd3);

//     printf("%s", str1);
//     // printf("%s", str2);
//     // printf("%s", str3);

//     free(str1);
//     // free(str2);
//     // free(str3);

// }

// int main()
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     int fd3 = open("file3.txt", O_RDONLY);

//     while (1)
//     {
//         char *str1 = get_next_line(fd1);
//         printf("%s", str1);
//         if (str1 == NULL)
//         {
//             break;
//         }
//         free(str1);
//     }
//     printf("\n\n");
//     while (1)
//     {
//         char *str2 = get_next_line(fd2);
//         printf("%s", str2);
//         if (str2 == NULL)
//         {
//             break;
//         }
//         free(str2);
//     }
//     printf("\n\n");
//     while (1)
//     {
//         char *str3 = get_next_line(fd3);
//         printf("%s", str3);
//         if (str3 == NULL)
//         {
//             break;
//         }
//         free(str3);
//     }
// }