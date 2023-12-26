# C - Basic File Process

Final code System Course - Group 3 Nguyen Duc Hieu

## Project Description

This program will get input from command like files name or directory or you can manipulate file (create, move, delete, copy).

## Installation

To run the chat application locally, follow these steps:

1. Clone the repository:
   ```bash
   $ git clone https://github.com/2H1EU8/sys-file-process-basic
   ```
2. Compile and run the program
   ```sh
   $ cd ./sys-file-process-basic
   $ gcc -o filestat file-new.c
   $ ./filestat 'input'
   ```
3. Format command to implement
   ```sh
   //Display infomation of file with flag -i
   $ ./filestat -i filename.txt
   $ ./filestat -i folder
   $ ./filestat -i * ~/. 
   $ // "*" character mean all file and "." character mean current directory
   
   //Manipulate file - with flag -m
   $ ./filestat -m create newfile.txt
   $ ./filestat -m coppy newfile.txt ~/newcopyfile.c
   $ ./filestat -m move newfile.txt ~/user/new-dir/newfile.txt
   $ ./filestat -m delete oldfile.txt
   ```

