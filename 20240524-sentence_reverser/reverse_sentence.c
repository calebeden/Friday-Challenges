#include "reverse_sentence.h"

#define IS_PUNCT(c)                                                                    \
	(c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' \
	      || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == '-'      \
	      || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '='      \
	      || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' || c == ']'     \
	      || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}'      \
	      || c == '~')
#define IS_SPACE(c) \
	(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f')

char *reverse_sentence(char *const string) {
	if (string[0] == '\0') {
		return string;
	}

	// strlen without libc dependency
	int len = 0;
	while (string[++len] != '\0') {
	}

	// reverse the entire string, but if there is a final punctuation, leave it at the end
	len = (IS_PUNCT(string[len - 1])) ? len - 1 : len;
	for (int i = 0; i < len / 2; i++) {
		char temp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = temp;
	}

	// put each word back to being forwards
	int startOffset = 0;
	for (int i = 0; i <= len; i++) {
		// if we just finished a word (either hit a whitespace or the end of the sentence)
		if (IS_SPACE(string[i]) || i == len) {
			// then reverse the word
			for (int j = 0; j < (i - startOffset) / 2; j++) {
				char temp = string[startOffset + j];
				string[startOffset + j] = string[i - j - 1];
				string[i - j - 1] = temp;
			}
			startOffset = i + 1;
		}
	}

	return string;
}
