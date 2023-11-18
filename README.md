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
   $ gcc -o filestat filestat.c
   $ ./filestat 'input'
   ```
3. Format command to implement
   ```sh
   //Display infomation of file
   $ ./filestat filename.txt
   $ ./filestat folder
   
   //Manipulate file
   $ ./filestat create newfile.txt
   $ ./filestat coppy newfile.txt ~/newcopyfile.c
   $ ./filestat move newfile.txt ~/user/new-dir/newfile.txt
   $ ./filestat delete oldfile.txt
   ```

