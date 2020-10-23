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
100 000 pairs of random strings were tested and no identical hashes were found (Collision test 1).

### 7) Even slightly changed input causes completely different output.

First string:

![InkedCapture3_LI](https://user-images.githubusercontent.com/57493215/96176204-b38cd780-0f34-11eb-98f6-ad88df0e8877.jpg)

Hash of the first string:

![Capture4](https://user-images.githubusercontent.com/57493215/96175983-5c870280-0f34-11eb-907a-1bbdba443136.PNG)

Second string with one changed simbol:

![Capture](https://user-images.githubusercontent.com/57493215/96176618-4463b300-0f35-11eb-840d-4743afde81e8.PNG)

Hash of the second string:

![Capture2](https://user-images.githubusercontent.com/57493215/96176676-56455600-0f35-11eb-8c88-1d591dfd035f.PNG)


## Collision tests

**Test 1**

In this test we take 100 000 pairs of same sized strings (10, 100, 500, 1000 symbols, 25 000 pairs of each), hash them and check if these hashes are not the same.
Results:

 * ![Capture](https://user-images.githubusercontent.com/57493215/96237416-f3d86e00-0fa5-11eb-9896-ed79cfba8d1e.PNG)
 * ![Capture2](https://user-images.githubusercontent.com/57493215/96252300-6a7f6680-0fba-11eb-8e64-60e39476d7e7.PNG)
 * ![Capture3](https://user-images.githubusercontent.com/57493215/96252853-4a03dc00-0fbb-11eb-8b1d-92e6ac05a92f.PNG)
 * ![Capture1000](https://user-images.githubusercontent.com/57493215/96255673-ffd12980-0fbf-11eb-9af4-e4fba7f043f1.PNG)
 
  There were 0 identical hashes.
 
 **Test 2**
 
 In this test we take another 100 000 pairs of strings and hash them just like in the test 1. However, this time two strings are very similar, they differ by only one character. The program calculates the percentage of difference of these two hashes in terms of both bits and hexes.
 Results:
 
  * ![10](https://user-images.githubusercontent.com/57493215/96919514-8d2ae700-14b4-11eb-93b4-6e0b5356f539.PNG)
  * ![100](https://user-images.githubusercontent.com/57493215/96919543-974ce580-14b4-11eb-8891-5e61c8faafa0.PNG)
  * ![Capture](https://user-images.githubusercontent.com/57493215/96919580-a469d480-14b4-11eb-8e94-9ee237d6d9dd.PNG)
  * ![2palyginimas1000](https://user-images.githubusercontent.com/57493215/96919613-ae8bd300-14b4-11eb-90df-0e1cab401186.PNG)
  
The average similarity of the hashes is 50% in terms of bits and 93.73% in terms of hexes.

Test 1 and test 2 prove that my hashing algorythm meets 6<sup>th</sup> and 7<sup>th</sup> requirements.

## Conclusion

All in all, my hashing function is good, it complies with all 7 requirements, although MD5, SHA-1, SHA-256 or any other well-known hash function probably is still better.

## Releases:

[v1.0](https://github.com/gertruda1/hash-generator/releases/tag/v1.0)

[v0.2](https://github.com/gertruda1/hash-generator/releases/tag/V0.2)
