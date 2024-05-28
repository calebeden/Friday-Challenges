# Friday Challenge 1 (2024-05-24) #

My function I am submitting can be found in [reverse_sentence.c](reverse_sentence.c), and the code I used to test it can be found in [main.c](main.c).

## Solution Explanation ##

My solution works by first reversing the entire input string, then going back through and re-reversing each word individually, so that the order of the words in the sentence is backwards, but the letters in each word is in the correct order.

For handling punctuation, I check whether the final character is a punctuation, and if so I do not include it in the reversing process. Additionally, by the way I detect word breaks by whitespace, punctuation marks such as commas will remain associated with the preceding word, just like the examples provided in the email prompt.

As far as capitalization goes, the examples in the email were inconsistent - "Iced cornbread is delicious!" became "Delicious is cornbread iced!" while "I like blue jets, yellow cars, and brown apples." became "apples brown and cars, yellow jets, blue like I." I decided not to alter the capitalization, since it would be impossible to tell whether something was meant to stay capitalized or not. (And as such, in my test code, I did change the cornbread example to conform to this limitation)

For the specification of "No use of external libraries allowed" I decided to write my solution in C, taking this very literally. My sentence reversing function was written with zero dependencies, including the libc runtime. If you wanted to, you could compile and run it on bare metal. (Although I did use C library functions in the test code)

## Time Complexity Analysis ##

Regarding the time complexity, my solution is O(n):

* Finding the string length is an O(n) operation, since it iterates over each character.
* Reversing the entire string is O(n), since it iterates from the ends towards the middle, swapping the (n/2) pairs once each.
* Fixing the order of the letters in each individual word is also O(n). Although it is a nested for loop, the outer loop will iterate over each character exactly once, and because of the way the inner loop is dependent on the outer loop, it will iterate over each character at most once ever - once it is handled on an iteration, it will not be touched in a future iteration.
* Therefore, the overall solution is O(n).
