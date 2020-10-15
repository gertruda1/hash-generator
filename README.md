# self-made hash generator

*In v.02 I completely changed my strategy for hashing algorythm, this means that v0.1 and v0.0.1 will have entirely different code.*

Program takes string input and outputs generated hash of the string.

## Installation instructions

 * Download the latest release code here ()
 * Install g++ compiler (GCC).
 * Compile program using command line *g++ bandomisnaujo.cpp -o exe*
 * Run program *exe*.

## My hashing function implementation

My idea for this task is very simple:
 * Default string "**default_str**" of 256 bits is being defined. (*In this case i have taken a small piece from "O Fortuna" - a well-known medieval Latin poem which is a part of the collection of 24 poems known as the "Carmina Burana").*
 * A string "**str**" that we want to generate hash from is taken.
 * And these two are being mixed.
 
 
 ```c++
 for(int i = 0; i < str.length(); i++)
        {
            for(int j = 0; j < hash_length; j++)
            {
                int a = 0;
                do
                {
                    a++;
                    copy[j] = (str[i] * copy[j] + a + i * j * a + (copy[a * i % hash_length] * default_str[j]) ^ (str[a % str.length()] * copy[3])) % 128;
                } while ((copy[j] < '0' || copy[j] > '9') && (copy[j] < 'a' || copy[j] > 'f'));
            }
        }
```
Here you can see the code of the mixing part. Basically, we are playing with string's ascii values: multiplying, adding, performing bitwise xor operations. Three loops help us include more different values to the calculation that are dependent to each string. Mixing is not being done randomly and in this way user is going to get the same hash for the same text each time. The result of calculation has to be a symbol for the final hash string, so this means that result has to be ascii value, which can be 0-127 (inclusive). That is why we need to get the remainder of 128. Of course, hash is a hexadecimal value, so we have to set the range of possible values 1-9 or a-f (inclusive). And this is pretty much my hashing function implementation.


## How do we know that this algorythm works?
 
### Input can be string of any size

### Output is always the same size
My hash is 256-bit size which is 64 characters.

