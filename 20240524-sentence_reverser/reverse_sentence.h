#ifndef REVERSE_SENTENCE_H
#define REVERSE_SENTENCE_H

/**
 * @brief A function that takes in a sentence including punctuation, and reverses the word
 * order.
 *
 * Keeps the trailing punctuation the same, if any.
 * Modifies the string in-place in O(n) time and O(1) auxiliary space.
 *
 * @param string the null-terminated mutable string to be reversed in-place. Each word in
 * the sentence SHOULD be separated by a single space, since this is not well defined in
 * the specification what should happen if it is not.
 * @return the input `string` pointer, as it is modified in-place
 */
char *reverse_sentence(char *string);

#endif
