# self-made hash generator

*In v.02 I completely changed my strategy for hashing algorythm, this means that v0.1 and v0.0.1 will have entirely different code.*

Program takes string input and outputs generated hash of the string.

## Installation instructions

 * Download the latest release code here ([v1.0](https://github.com/gertruda1/hash-generator/releases/tag/v1.0))
 * Install g++ compiler ([GCC](https://gcc.gnu.org/)).
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
 
### 1) Input can be string of any size.

### 2) Output is always the same size.
My hash is 256-bit size which is 64 characters.
 
![Capture](https://user-images.githubusercontent.com/57493215/96168614-a9b1a700-0f29-11eb-825d-96da05794ad3.PNG)
![Capture2](https://user-images.githubusercontent.com/57493215/96168801-f6957d80-0f29-11eb-93be-cdc1e3b2e215.PNG)

### 3) The function is deterministic. Output is not random.

### 4) Hashing is done somewhat quickly.
My hashing algorythm can hash 789 strings in 2.6 s. Not the worst results, but it could be quicker.

### 5) It is practically impossible to find an input by having only an output.

### 6) It is practically impossible to find two strings m1 and m2 that hash(m1) = hash(m2).
100 000 pairs of random strings were tested and no identical hashes were found;

### 7) Even slightly changed input causes completely different output.

First string:

![InkedCapture3_LI](https://user-images.githubusercontent.com/57493215/96176204-b38cd780-0f34-11eb-98f6-ad88df0e8877.jpg)

Hash of the first string:

![Capture4](https://user-images.githubusercontent.com/57493215/96175983-5c870280-0f34-11eb-907a-1bbdba443136.PNG)

Second string with one changed simbol:

![Capture](https://user-images.githubusercontent.com/57493215/96176618-4463b300-0f35-11eb-840d-4743afde81e8.PNG)

Hash of the second string:

![Capture2](https://user-images.githubusercontent.com/57493215/96176676-56455600-0f35-11eb-8c88-1d591dfd035f.PNG)


## Conclusion

All in all, my hashing function is good, it completes all 7 requirements, although MD5, SHA-1, SHA-256 or any other well-known hash function probably is still better.

## Releases:

[v1.0](https://github.com/gertruda1/hash-generator/releases/tag/v1.0)

[v0.2](https://github.com/gertruda1/hash-generator/releases/tag/V0.2)
