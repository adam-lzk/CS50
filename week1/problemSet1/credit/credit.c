// Verification of the credit card number for authenticity (through the Luhn’s algorithm) and identification of belonging to a particular bank

#include <cs50.h>
#include <stdio.h>


int CalculateChecksum(long creditCardNumber)  // the Luhn’s algorithm for verifying the authenticity of a credit card
{
    int checksum = 0;

    while (creditCardNumber > 0)
    {
        checksum += creditCardNumber % 10;

        creditCardNumber /= 10;

        int digit = (creditCardNumber % 10) * 2;

        while (digit > 0)
        {
            checksum += digit % 10;
            digit /= 10;
        }

        creditCardNumber /= 10;
    }

    return checksum;
}


bool isAMEX(long creditCardNumber)  // identification of belonging to a particular bank
{
    const long creditCardNumber_copy = creditCardNumber;

    int digitCounter = 0;
    bool isSuitableStartingNumber = false;

    while (creditCardNumber > 0)
    {
        creditCardNumber /= 10;
        digitCounter++;

        if (creditCardNumber == 34 || creditCardNumber == 37)
        {
            isSuitableStartingNumber = true;
        }
    }

    if (digitCounter == 15 && isSuitableStartingNumber)
    {
        return true;
    }
    else
    {
        return false;
    }

}


bool isMASTERCARD(long creditCardNumber)
{
    const long creditCardNumber_copy = creditCardNumber;

    int digitCounter = 0;
    bool isSuitableStartingNumber = false;

    while (creditCardNumber > 0)
    {
        creditCardNumber /= 10;
        digitCounter++;

        if (creditCardNumber == 51 || creditCardNumber == 52 || creditCardNumber == 53 || creditCardNumber == 54 || creditCardNumber == 55)
        {
            isSuitableStartingNumber = true;
        }
    }

    if (digitCounter == 16 && isSuitableStartingNumber)
    {
        return true;
    }
    else
    {
        return false;
    }

}


bool isVISA(long creditCardNumber)
{
    const long creditCardNumber_copy = creditCardNumber;

    int digitCounter = 0;
    bool isSuitableStartingNumber = false;

    while (creditCardNumber > 0)
    {
        creditCardNumber /= 10;
        digitCounter++;

        if (creditCardNumber == 4)
        {
            isSuitableStartingNumber = true;
        }
    }

    if ((digitCounter == 13 || digitCounter == 16) && isSuitableStartingNumber)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main(void) 
{
    long creditCardNumber = get_long("Number: ");

    int checksum = CalculateChecksum(creditCardNumber);

    if (checksum % 10 == 0)
    {
        if (isAMEX(creditCardNumber))
        {
            printf("AMEX\n");
        }
        else if (isMASTERCARD(creditCardNumber))
        {
            printf("MASTERCARD\n");
        }
        else if (isVISA(creditCardNumber))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
