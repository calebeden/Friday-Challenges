#include "reverse_sentence.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool failed = false;

#define EXPECT_STR_EQ(string1, string2)                                               \
	do {                                                                              \
		const char *const _string1 = string1;                                         \
		const char *const _string2 = string2;                                         \
		if (strcmp(_string1, _string2) != 0) {                                        \
			fprintf(stderr,                                                           \
			      "Failure at %s:%d in %s: Expected equality of \"%s\" and \"%s\"\n", \
			      __FILE__, __LINE__, __FUNCTION__, _string1, _string2);              \
			failed = true;                                                            \
		}                                                                             \
	} while (0)

/**
 * @brief Copies a null-terminated char array (such as a static string literal) to a
 * heap-allocated array.
 *
 * Similar to Rust's `String::from("")` or `"".into()`
 * (This is useful since my implementation of the challenge modifies the array in-place,
 * so we cannot directly give it a string literal)
 *
 * @param staticChars the string to copy
 * @return an owning pointer to the copied string, should be de-allocated by `free()`
 */
static inline char *string_from(const char *const staticChars) {
	char *newString = malloc((strlen(staticChars) + 1) * sizeof(*newString));
	return strcpy(newString, staticChars);
}

/**
 * @brief Tests the Friday Challenge string reverse function as described in the email
 *
 */
void test_reverse_sentence() {
	char *sentence = string_from("Iced cornbread is delicious!");
	const char *reversed = "delicious is cornbread Iced!";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("I like blue jets, yellow cars, and brown apples.");
	reversed = "apples brown and cars, yellow jets, blue like I.";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("Friday challenges are fun!");
	reversed = "fun are challenges Friday!";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("Write a function that takes in a sentence including "
	                       "punctuation, and reverses the word order.");
	reversed = "order word the reverses and punctuation, including sentence a in takes "
	           "that function a Write.";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	// Edge case testing
	sentence = string_from("");
	reversed = "";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from(" ");
	reversed = " ";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from(".");
	reversed = ".";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("a");
	reversed = "a";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);
}

/**
 * @brief Tests a few things my solution has as a superset of the email specification
 *
 * Tests sentences without trailing punctuation, words with other whitespace characters
 * between them, and words with more than one whitespace between them.
 * Theoretically, there could have a test that has a mixture of amounts and types of
 * whitespace between words, but I'm not really sure what the expected behavior for that
 * would be.
 *
 */
void test_reverse_sentence_extensions() {
	char *sentence = string_from("Test no trailing punctuation");
	const char *reversed = "punctuation trailing no Test";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("Other\twhitespace\ntest.");
	reversed = "test\nwhitespace\tOther.";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);

	sentence = string_from("Multiple  whitespace  test.");
	reversed = "test  whitespace  Multiple.";
	EXPECT_STR_EQ(reverse_sentence(sentence), reversed);
	free(sentence);
}

/**
 * @brief Runs the tests for `reverse_sentence` to ensure it works correctly.
 *
 */
int main(int argc, char **argv) {
	test_reverse_sentence();
	test_reverse_sentence_extensions();
	if (failed) {
		puts("\nTests failed!");
		exit(EXIT_FAILURE);
	} else {
		puts("\nAll tests passed!");
		exit(EXIT_SUCCESS);
	}
}
