#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>

//datatype defined above main because it is used in main.
bool check_valid_key(string s);

//command line arguments.
int main(int argc, string argv[])
{
    //this line of code ensures that there are are 2 words and makes sure that the second word is  a valid key.
    if(argc != 2 || !check_valid_key(argv[1]))
    {
        //If they dont follow the criteria, the computer prints that and prompts user for the input again.
        printf("./caeser key\n");
        return 1;
    }
    //a variable key stores alphabets converted into integers. the atoi(alphabet to integer) function does that. It converts the second word after the ./caeser.
    int key = atoi(argv[1]);
    
    string plaintext = get_string("Plaintext: ");
    
    printf("Ciphertext: ");
    
    //iterating the plaintext
    for(int i = 0, len = strlen(plaintext); i<len; i++)
    {
        //c variable stores all the values inputted in plaintext.
        char c = plaintext[i];
        //this line makes sure that whatever is inputted in plaintext(stored in c variable) is an alphabet.
        if(isalpha(c))
        {
            //m stores A
            char m = 'A';
            if(islower(c))
            {
                // this line makes sure that even if A is typed in lowercase, it is stored in m.
                m = 'a';
            }
            //this line prints the ciphertext which is basically the plaintext encrypted based on the value of argv[1]. 
            //we are turning ASCII character to numbers more easy to understand because in ASCII A is typically 65. so we are converting 65 to 1 for A and all the other letters.
            printf("%c", (c - m + key)%26 +m);
        }
        else
        {
            //If the particular character is not an alphabet (,/ ./ !/ ?) then the code makes sure that they are printed as it is.
            //Because these special characters are also ASCI characters and moving them by a particular number will result in another character 
            //which the reciever wont be able to decrypt because it will be following the ASCII chart.
            printf("%c", c);
        }
    }
    printf("\n");
    
}
//Designed a datatype which is used in code. Becuase typing this everytime can be a lengthy task.
bool check_valid_key(string s)
{
    for(int i = 0, len = strlen(s); i<len; i++)
    //If the Argv[1] is not a digit(number) then the computer prints false. If it is then it prints true and continues with the whole program
        if(!isdigit(s[i]))
            return false;
        return true;
}

