#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int add_digits(int n); // Function that adds the digits from a 2 or more digit number
    
    string cc;
   
    // Checks if the input provided is null or not a number
    do
    {
        cc = get_string("Number: ");
    }
    while (strlen(cc) == 0 || atoi(cc) == 0);
    
    // Looks for numbers that are not CC valid, regardless of provider
    
    if (strlen(cc) > 16 || strlen(cc) < 13 || cc[0] - '0' <= 2 || cc[0] - '0' >= 6)
    {
        printf("INVALID\n");    
    }
    
    if (cc[0] - '0' == 5 && cc[1] - '0' >= 6)
    {
        printf("INVALID\n");
    }
    
    if (cc[0] - '0' == 3 && (cc[1] - '0' != 4 && cc[1] - '0' != 7))
    {
        printf("INVALID\n"); 
    }
    
    // Converts CC number from string to array of integers
    int cc_int[strlen(cc)];

    
    for (int i = 0; i < strlen(cc); i++)
    {
        cc_int[i] = cc[i] - '0';
    }
    
    // Starting from second to last, multiplies every other digit by 2
    // then, adds the product's digits together

    int sumResult = 0;
    
    for (int i = strlen(cc) - 2; i >= 0; i = i - 2)
    {
       
        cc_int[i] = cc_int[i] * 2;
        
        if (cc_int[i] > 9)
        {
            sumResult = sumResult + add_digits(cc_int[i]);
        }
        
        else
        {
            sumResult = sumResult + cc_int[i]; 
        }
    }
    
    // Adds together every digit that wasn't multiplied
    int sumResult2 = 0;
   
    for (int i = strlen(cc) - 1; i >= 0; i = i - 2)
    {
      
        sumResult2 = sumResult2 + cc[i] - '0';
    }
   
    // Adds the sum of the multiplied numbers with the non-multiplied numbers
    int totalSum = 0;
    totalSum = sumResult + sumResult2;
   
    // If last number of the result is not 0, then the CC is not valid
    if (totalSum % 10 != 0)
    {
        printf("INVALID\n");
       
    }
   
    // If it's valid, proceeds to check whether it is VISA, AMEX, or MASTERCARD
    else if (totalSum % 10 == 0)
    {
        if (cc[0] - '0' == 4)
       
        {
            printf("VISA\n");
        }
       
        else if (cc[0] - '0' == 3  && (cc[1] - '0' == 4 || cc[1] - '0' == 7))
       
        {
            printf("AMEX\n");
      
        }
       
        else if (cc[0] - '0' == 5 && (cc[1] - '0' >= 1 && cc[1] - '0' <= 5))
       
        {
          
            printf("MASTERCARD\n");
      
        }
    }
   
}

int add_digits(int n)
{
    int remainder, t, sum = 0;
    t = n;
    while (t != 0)
    {
        remainder = t % 10;
        sum = sum + remainder;
        t = t / 10;
    }
    return sum;
    
}

     
