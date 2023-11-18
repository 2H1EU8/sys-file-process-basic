#define S_IFMT 0160000 
#define S_IFDIR 0040000 

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void print_error(int error_index, int exit_code, int exit_flag, const char* custom_msg);

void create_file(const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        print_error(3, 1, 1, NULL);
    }
    else
    {
        fclose(file);
        printf("File created successfully.\n");
    }
}

void copy_file(const char* source, const char* destination)
{
    FILE* source_file = fopen(source, "rb");
    FILE* destination_file = fopen(destination, "wb");
    if (source_file == NULL || destination_file == NULL)
    {
        print_error(4, 2, 0, "Error opening files");
        if (source_file != NULL)
            fclose(source_file);
        if (destination_file != NULL)
            fclose(destination_file);
        return;
    }

    char buffer[BUFSIZ];
    size_t size;
    while ((size = fread(buffer, 1, BUFSIZ, source_file)) > 0)
    {
        fwrite(buffer, 1, size, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
    printf("File copied successfully.\n");
}

void move_file(const char* source, const char* destination)
{
    if (rename(source, destination) != 0)
    {
        print_error(5, 2, 0, NULL);
    }
    else
    {
        printf("File moved successfully.\n");
    }
}

void delete_file(const char* filename)
{
    if (remove(filename) != 0)
    {
        print_error(6, 2, 0, NULL);
    }
    else
    {
        printf("File deleted successfully.\n");
    }
}

void print_error(int error_index, int exit_code, int exit_flag, const char* custom_msg)
{
    const char* error_msg[] = {
        "Error: Invalid command.\n",
        "Error: Insufficient arguments.\n",
        "Error: File does not exist.\n",
        "Error: Failed to create file.\n",
        "Error: Failed to open files.\n",
        "Error: Failed to move file.\n",
        "Error: Failed to delete file.\n"
    };

    if (custom_msg != NULL)
        printf("%s\n", custom_msg);
    printf("%s", error_msg[error_index]);
    if (exit_flag)
        exit(exit_code);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        print_error(1, 1, 1, NULL);
    }
    else
    {
        char* command = argv[1];
        char* file1 = argv[2];
        char* file2 = argv[3];

        if (strcmp(command, "create") == 0)
        {
            if (argc != 3)
            {
                print_error(1, 1, 1, NULL);
            }
            else
            {
                create_file(file1);
            }
        }
        else if (strcmp(command, "copy") == 0)
        {
            if (argc != 4)
            {
                print_error(1, 1, 1, NULL);
            }
            else
            {
                copy_file(file1, file2);
            }
        }
        else if (strcmp(command, "move") == 0)
        {
            if (argc != 4)
            {
                print_error(1, 1, 1, NULL);
            }
            else
            {
                move_file(file1, file2);
            }
        }
        else if (strcmp(command, "delete") == 0)
        {
            if (argc != 3)
            {
                print_error(1, 1, 1, NULL);
            }
            else
            {
                delete_file(file1);
            }
        }
        else
{
    // Print file/directory information
    struct stat file_details;
    if (stat(command, &file_details) != 0)
    {
        print_error(2, 1, 1, NULL);
    }
    else
    {
        printf("Name: %s\n", command);
        
        // File type
        printf("Type: ");
        if (S_ISREG(file_details.st_mode))
            printf("File\n");
        else if (S_ISDIR(file_details.st_mode))
            printf("Directory\n");
        else if (S_ISLNK(file_details.st_mode))
            printf("Symbolic Link\n");
        else
            printf("Other\n");
        
        printf("Size: %ld bytes\n", file_details.st_size);
        
        // Permissions
        printf("Permissions: ");
        printf((file_details.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_details.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_details.st_mode & S_IXUSR) ? "x" : "-");
        printf((file_details.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_details.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_details.st_mode & S_IXGRP) ? "x" : "-");
        printf((file_details.st_mode & S_IROTH) ? "r" : "-");
        printf((file_details.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_details.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");
        
        // Last access time
        printf("Last Access: %s", ctime(&file_details.st_atime));
        printf("\n");
    }
}
    }

    return 0;
}