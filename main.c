#include "get_next_line.h"


// int main()
// {
//     int fd = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     int fd3 = open("file3.txt", O_RDONLY);


//     while (1)
//     {
//         char *str1 = get_next_line(fd);
//         if (str1 == NULL)
//             break;
//         printf("%s", str1);
//         free(str1);
//     }
//     printf("\n\n");
//     while (1)
//     {
//         char *str2 = get_next_line(fd2);
//         if (str2 == NULL)
//             break;
//         printf("%s", str2);
//         free(str2);
//     }
//     printf("\n\n");
//     while (1)
//     {
//         char *str3 = get_next_line(fd3);
//         if(str3 == NULL)
//             break;
//         printf("%s", str3);
//         free(str3);
//     }
// }

int main()
{
    int fd = open("file1.txt", O_RDONLY);

    while (1)
    {
        char *str1 = get_next_line(fd);
        if (str1 == NULL)
            break;
        printf("%s", str1);
        free(str1);
    }
}