#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "src/Core/Credential_Generator/random/random.h"
#include "src/Core/Credential_Generator/file/file.h"

char* Username_generator();
char* password_generator(int password_length);
char* Passphrase_generator(int wordcount);
char* Full_Name_generator();
static char* trim_whitespace(char* str);

int main() {
	    //Welcome the user
	    printf("Welcome to the credential generator\n");
		printf("\n Please Select a menu item\n\n");

		printf(" 1: Username Generator ");
		printf("\n 2: Password Generator ");
		printf("\n 3: Passphrase Generator ");
		printf("\n 4: Full Name Generator ");
		printf("\n 5: Random Number Generator ");
		printf("\n 6: Custom Unicode String generator ");
		printf("\n 7: Custom phrase Generator ");

		printf("\n\n Your Selection: ");

		//Take user input
		int selector_buffer = 0;

		while (selector_buffer == 0) {;
			scanf ("%d", &selector_buffer);

			if (selector_buffer >= 1 && selector_buffer <= 8) {
				break;
				
			} else {
				(selector_buffer = 0);
			}
		}

		//use switch statement to seperate menus.
		switch  (selector_buffer)
		{
		case 1:
			printf("Username_Generator");
			char* username = Username_generator("/home/anon/Personal/Code/Credential_Generator_C/Files/username_word_list_1.txt", "/home/anon/Personal/Code/Credential_Generator_C/Files/username_word_list_2.txt");
			printf ("\n%s\n", username);
			break;

		case 2:
		    printf("Password Generator");
			int password_length = 20;
			char* password = password_generator(password_length);
			printf ("\n%s\n", password);
			break;

		case 3:
			printf("Passphrase Generator");
			int passphrase_length = 5;
			char* passphrase = Passphrase_generator(passphrase_length);
			printf ("\n%s\n", passphrase);
			break;

		case 4:
			printf("Full_Name_Generator");
			char* full_name = Full_Name_generator();
			printf ("\n%s\n", full_name);
			break;

		case 5:
		    printf("Number generator");

		    int upper_limit = 10000;
			int lower_limit = 1;
			
			unsigned long long int temp_number = Generate_random_number(lower_limit, upper_limit);
			int number = temp_number;

			printf("\n%d\n", number);
			break;

		case 6:
			printf("Unicode String generator");

			UChar32 str_lower_limit = 0x21;
	        UChar32 str_upper_limit = 0x7E;
			int str_length = 20;

			char* rand_string = Generate_Random_UTF8_string(str_length, str_lower_limit, str_upper_limit);

			printf("\n%s\n", rand_string);
			break;

		case 7:
		    printf("Custom phrase generator");

			int custom_phrase_length = 5;
			char custom_file_path[512] = "/home/anon/Personal/Code/Credential_Generator_C/Files/passphrase_list.txt";

			char* phrase_buffer = Generate_Random_Phrase(custom_file_path, custom_phrase_length);
			char* phrase = trim_whitespace(phrase_buffer);

			printf("\n\n%s\n", phrase);
			break;	

		default:
			break;
		}
return 0;
}

//Whitespace trimmer
static char* trim_whitespace(char* str) {
	if (!str) return NULL;

	char* end;
	while (isspace((unsigned char)*str)) str++;
	if (*str == '\0') return str;

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;
	*(end + 1) = '\0';

	return str;
}

//Phrase generator, UTF8 string generator, Random number generator
//FORMAT: Random_phrase_1, Random_Phrase_2, Random_number
char* Username_generator(char wordlist_path_1[512], char wordlist_path_2[512]) {
	char* word1 = NULL;
	char* word2 = NULL;
	char* username = NULL;

	//Word 1
	bool path_1_validity = check_file_validity(wordlist_path_1);

	char* path_1 = NULL;
	path_1 = wordlist_path_1;

	if(wordlist_path_1 == NULL || path_1_validity == false) {
		wordlist_path_1 == "/home/anon/Personal/Code/Credential_Generator_C/Files/username_word_list.txt";
	}	

	word1 = get_random_UTF8_file_line(wordlist_path_1);
	if (!word1) return NULL;
	trim_whitespace(word1);


    //Word 2

	bool path_2_validity = check_file_validity(wordlist_path_2);

    char* path_2 = NULL;
	path_2 = wordlist_path_2;

	if (wordlist_path_2 == NULL || path_2_validity == false) {
		wordlist_path_2 == "/home/anon/Personal/Code/Credential_Generator_C/Files/username_word_list_2.txt";
	}

	word2 = get_random_UTF8_file_line(wordlist_path_2);
	if (!word2) { free(word1); return NULL; }
	trim_whitespace(word2);


    //RNG
	unsigned long long int number = Generate_random_number(0, 9999);

	//Assembly
	size_t total_len = strlen(word1) + strlen(word2) + 20;
	username = malloc(total_len);
	if (!username) { free(word1); free(word2); return NULL; }

	snprintf(username, total_len, "%s_%s_%llu", word1, word2, number);

	free(word1);
	free(word2);

	return username;
}

// UTF8 string Generator
//FORMAT: Random_String (Defined char set)
char* password_generator(int password_length) {
	UChar32 lower_limit = 0x21;
	UChar32 upper_limit = 0x7E;

	char* password = Generate_Random_UTF8_string(password_length, lower_limit, upper_limit);
	return password;
}

// Phrase generator
//FORMAT: Random_phrase
char* Passphrase_generator(int word_count) {

	char* phrase = Generate_Random_Phrase("/home/anon/Personal/Code/Credential_Generator_C/Files/passphrase_list.txt", word_count);
	if (!phrase) return NULL;

	char* trimmed = trim_whitespace(phrase);
	if (trimmed != phrase) {
		size_t len = strlen(trimmed) + 1;
		char* result = malloc(len);
		if (result) {
			memcpy(result, trimmed, len);
		}
	return phrase;
}
	return phrase;
}

// Full name generator
// FORMAT: First name Middle name Surname
char* Full_Name_generator() {
	char* first = NULL;
	char* middle = NULL;
	char* surname = NULL;
	char* full_name = NULL;

	first = get_random_UTF8_file_line("/home/anon/Personal/Code/Credential_Generator_C/Files/First_names.txt");
	if (!first) return NULL;
	trim_whitespace(first);

	middle = get_random_UTF8_file_line("/home/anon/Personal/Code/Credential_Generator_C/Files/Middle_name.txt");
	if (!middle) { free(first); return NULL; }
	trim_whitespace(middle);

	surname = get_random_UTF8_file_line("/home/anon/Personal/Code/Credential_Generator_C/Files/Surname_list.txt");
	if (!surname) { free(first); free(middle); return NULL; }
	trim_whitespace(surname);

	size_t total_len = strlen(first) + strlen(middle) + strlen(surname) + 4;
	full_name = malloc(total_len);
	if (!full_name) { free(first); free(middle); free(surname); return NULL; }

	snprintf(full_name, total_len, "%s %s %s", first, middle, surname);

	free(first);
	free(middle);
	free(surname);

	return full_name;
}
