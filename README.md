# EE222 Final Project

This project is a single C file that reads an input file, rewrites the contents of the file, and then prints the result or writes the result to a separate file.

The input that the main file is opening and reading contains 5 different samples of sequences of genetics. Each sequence varies in length and contents, while the end of the row is determined by a new line character.

The main objective of the C code is to read all of the contents of the file. While reading the contents the program is counting the number of rows and columns inside the text file. After it determines the columns and rows in each sequence it displays first the original sequence and writes it to the new file. The code then reads the original sequence and rewrites the sequence to be the complementary of the original. This entails flipping the individual characters to their complementary character. Once it has rewritten the sequence it displays the complementary sequence to the user and writes it to the new output file.
