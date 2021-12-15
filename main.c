//Jeremy Klein
//EE222
//Project Phase 3
//November 12, 2020

#include <stdio.h>
#include <stdlib.h>

int count_rows(const char*);
int* count_cols(const char*);
char** content(const char*);
int** count_char(const char*);
char** complementary(const char*);
void FileWrite(const char*, const char*);
void complementaryFileWrite(const char*, const char*);

int main(void) 
  {
  const char* input = "input.txt";
  const char* output = "output.txt";
  const char* compOutput = "coutput.txt";
  int rows = count_rows(input);
  int* columns = count_cols(input);
  int* columns1 = count_cols(input);
  int* columns2 = count_cols(input);
  char** stringcontent = content(input);
  char** complement = complementary(input);
  int** count = count_char(input);
  printf("After skipping the commentary lines, there is a total of %d rows.\n", rows);
  printf("\n");
  for (int i = 1; i < rows + 1; i ++)
    {
    printf("In row %d, there are %d column(s) \n", i, *columns - 1);
    columns++;
    }
  printf("\n");
  for (int j = 0; j < rows; j ++ )
    {
    printf("These are the contents in row %d: \n", j + 1);
    for ( int k = 0; k < *columns1; k++ )
      {
      printf("%c", stringcontent[j][k]);
      }
    printf("\n");
    columns1++;
    }
  printf("\n");
  for ( int k = 0; k < rows; k ++)
    {
      printf("In row %d, there are:\n", k + 1);
      for ( int l = 0; l < 4; l ++)
        {
        printf("%d " , count[k][l]);
        if ( l == 0 )
          {
            printf("A(s),");
          }
        else if ( l == 1 )
          {
            printf("C(s),");
          }
        else if ( l == 2 )
          {
            printf("G(s),");
          }
        else if ( l == 3 )
          {
            printf("T(s),");
          }
          printf("\n");
        }
    }
  printf("\n");
  for (int m = 0; m < rows; m ++ )
    {
    printf("These are the complementary contents in row %d: \n", m + 1);
    for ( int n = 0; n < *columns2; n++ )
      {
      printf("%c", complement[m][n]);
      }
    printf("\n");
    columns2++;
    }
  FileWrite(input, output);
  complementaryFileWrite(input, compOutput);
  return 0;
  }


int count_rows(const char* filename) 
  { 
  int rows = 0; 
  FILE* fp = fopen(filename, "r"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for reading\n"); 
    exit(1); 
    } 
  // skip the comment lines and count the rows/lines
  
  while (1) 
    { 
    char ch = getc(fp); 
    //skip the comment line 
    while (ch == '#') 
    { 
    do 
      { 
      ch = getc(fp); 
      }
    while (ch != '\n'); 
    ch = getc(fp); 
    } 
  // break if end of file is reached 
  if (feof(fp) != 0) 
    { 
    break;
    } 
  //else we increase the row 
  if (ch == '\n') 
    { 
    rows++;
    } 
  }
fclose(fp); 
return rows; 
}


int* count_cols(const char* filename)
  {
  int columns = 0;
  int rows = count_rows(filename);
  int* cols = (int*)malloc(sizeof(int)*rows);
  FILE* fp = fopen(filename, "r");
  if ( ! fp )
    {
    fprintf(stderr, "can't open file for reading\n");
    exit(1);
    }
   int i = 0;
   while (1) 
    {
    columns = 0; 
    char ch = getc(fp); 
    //skip the comment line 
    while (ch == '#') 
    { 
    do 
      { 
      ch = getc(fp); 
      }
    while (ch != '\n'); 
    ch = getc(fp); 
    } 
  // break if end of file is reached 
    if (feof(fp) != 0) 
      { 
      break;
      } 
    while (ch != '\n')
      {
      columns++;
      ch = getc(fp);
      }
      cols[i] = columns;
      i++;
    }
  fclose(fp);
  return cols;
  }


char** content(const char* filename)
  {
  FILE* fp = fopen(filename, "r");
  if ( ! fp )
    {
    fprintf(stderr, "can't open file for reading\n");
    exit(1);
    }
  int rows = count_rows(filename);
  int* cols = count_cols(filename);
  char** buffer = (char**)malloc(sizeof(char*)*rows);
  //initializer
  for (int i = 0; i < rows ; i ++)
    {
      buffer[i] = (char*)malloc(sizeof(char)* cols[i]);
    }
  //grab char from input.txt and put it in buffer
  //modify the code on count rows function here
  int j = 0, k = 0;
  while (1) 
  { 
    char ch = getc(fp); 
    //skip the comment line 
    while (ch == '#') 
    { 
    do 
      { 
      ch = getc(fp); 
      }
    while (ch != '\n'); 
    ch = getc(fp); 
    } 
  // break if end of file is reached 
  if (feof(fp) != 0) 
    { 
    break;
    }
  k = 0;  
  while (ch  != '\n') 
    { 
    buffer[j][k] = ch;
    ch = getc(fp);
    k++;
    }
  j++;
  }
  fclose(fp);
  return buffer; 
  } 
    

int** count_char(const char* filename)
  {
  int rows = count_rows(filename);
  int* cols = count_cols(filename);
  int** result = (int**)malloc(sizeof(int*)*rows);
  for( int i = 0; i < rows; i ++)
    {
      result[i] = (int*)malloc(sizeof(int)* 4);
    }
  //initializing array
  for ( int k = 0; k < rows; k++)
    {
    for ( int l = 0; l < 4; l ++)
      {
      result[k][l] = 0;
      }
    }
  FILE* fp = fopen(filename, "r"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for reading\n"); 
    exit(1); 
    } 
  // skip the comment lines and count the rows/lines
  int j = 0;
  while (1) 
    { 
    char ch = getc(fp); 
    //skip the comment line 
    while (ch == '#') 
    { 
    do 
      { 
      ch = getc(fp); 
      }
    while (ch != '\n'); 
    ch = getc(fp); 
    } 
    // break if end of file is reached 
    if (feof(fp) != 0) 
    { 
    break;
    } 
    while ( ch != '\n')
      {
      if ( ch == 'A')
        {
        result[j][0] ++;
        }
      else if ( ch == 'C')
        {
        result[j][1] ++;
        }
      else if ( ch == 'G')
        {
        result[j][2] ++;
        }
      else if ( ch == 'T')
        {
        result[j][3] ++;
        }
      ch = getc(fp);
      }
    j++;
    }
printf("\n");
printf("%d", result[0][0]);
printf("\n");


fclose(fp); 
return result;
}

char** complementary(const char* filename)
  {
  FILE* fp = fopen(filename, "r");
  if ( ! fp )
    {
    fprintf(stderr, "can't open file for reading\n");
    exit(1);
    }
  int rows = count_rows(filename);
  int* cols = count_cols(filename);
  char** buffer = (char**)malloc(sizeof(char*)*rows);
  //initializer
  for (int i = 0; i < rows ; i ++)
    {
      buffer[i] = (char*)malloc(sizeof(char)* cols[i]);
    }
  //grab char from input.txt and put it in buffer
  //modify the code on count rows function here
  int j = 0, k = 0;
  while (1) 
  { 
    char ch = getc(fp); 
    //skip the comment line 
    while (ch == '#') 
    { 
    do 
      { 
      ch = getc(fp); 
      }
    while (ch != '\n'); 
    ch = getc(fp); 
    } 
  // break if end of file is reached 
  if (feof(fp) != 0) 
    { 
    break;
    }
  k = 0;  
  while (ch  != '\n') 
    { 
    if ( ch == 'A')
      {
      buffer[j][k] = 'T';
      }
    else if ( ch == 'C')
      {
      buffer[j][k] = 'G';
      }
    else if ( ch == 'G')
      {
      buffer[j][k] = 'C';
      }
    else if ( ch == 'T')
      {
      buffer[j][k] = 'A';
      }
    ch = getc(fp);
    k++;
    }
  j++;
  }
  fclose(fp);
  return buffer; 
  }

void FileWrite(const char* input, const char* output)
  {
  int rows = count_rows(input);
  int* cols = count_cols(input);
  char** stringContent = content(input);
  char** compString = complementary(input);
  FILE* fp = fopen(output, "w"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for writing\n"); 
    exit(1); 
    } 
  FILE* fp1 = fopen(input, "r"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for writing\n"); 
    exit(1); 
    }

  for (int i = 0; i < rows; i++)
    {
      fputs("Original Sequence: \n", fp);
      for ( int j = 0; j < *cols; j ++ )
        {
        fputc(stringContent[i][j], fp);
        }
      fputs("\n", fp);
      fputs("Complementary sequence: \n", fp);
      for ( int k = 0; k < *cols - 1; k ++)
        {
        fputc(compString[i][k], fp);
        }
      cols++;
      fputs("\n", fp);
    }
  fclose(fp);
  fclose(fp1);
  }

void complementaryFileWrite(const char* input, const char* output)
  {
  int rows = count_rows(input);
  int* cols = count_cols(input);
  char** compString = complementary(input);
  FILE* fp = fopen(output, "w"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for writing\n"); 
    exit(1); 
    } 
  FILE* fp1 = fopen(input, "r"); 
  //if we can't open the file, print an error message 
  //use stderr file stream to output all the errors 
  if (!fp) 
    { 
    fprintf(stderr, "Can't open file for writing\n"); 
    exit(1); 
    }
  fputs("#########################This is input file###################\n", fp);
  fputs("#########################This is Sequence 1###################\n", fp);
  for (int i = 0; i < rows; i++)
    {
      for ( int j = 0; j < *cols - 1; j ++ )
        {
        fputc(compString[i][j], fp);
        }
      fputc('\n', fp);
      if ( i == 0 )
        {
        fputs("########################This is Sequence 2#####################\n", fp);
        }
      else if ( i == 1 )
        {
        fputs("########################This is Sequence 3#####################\n",fp);
        fputs("#######################Sequence3 = Sequence2 + Sequence1##################\n",fp);
        }
      else if ( i == 2 )
        {
        fputs("########################This is Sequence 4#####################\n",fp);
        }
      else if ( i == 3 )
        {
        fputs("########################This is Sequence 5#####################\n",fp);
        fputs("#######################Sequence 5 is the shortest sequence in the file########################\n",fp);
        }
      cols++;
    }
  fputs("##############################################################################################\n", fp);
  fputs("#############################11/12/2020########################\n", fp);
  fclose(fp);
  fclose(fp1);
  }