#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

static void
reverse(char *string, int offset, int length)
{
	int left;
	char temp;
	int begin = 0;
	offset = offset % length;

	while (length && offset) {
		left = length - offset;
		if (offset >= left) {
			for (int i = begin; i < begin + left; i++) {
				temp = string[i];
				string[i] = string[offset + i];
				string[offset + i] = temp;
			}
			begin += left;
			offset -= left;
			length -= left;
		} else {
			for (int i = begin; i < begin + offset; i++) {
				temp = string[i];
				string[i] = string[left + i];
				string[left + i] = temp;
			}
			length = left;
		}
	}
}

static void
swap(char *string, int length)
{
	char temp;
	int end = length - 1;
	for (int i = 0; i < length/2; i++) {
		temp = string[i];
		string[i] = string[end - i];
		string[end - i] = temp;
	}
}

static void
reverse_(char *string, int offset, int length)
{
	swap(string, offset);
	swap(string + offset, length - offset);
	swap(string, length);
}

int
main()
{
	int start, end;
	char string[1000000]={"abcdefgh"};
	start = clock();
	for (int i = 0; i < 500; i++)
	reverse_(string, 4, sizeof(string) - 1);
	end = clock();
	printf("%s\n", string);
	printf("%d\n", end - start);


	char string1[1000000]={"abcdefgh"};
	start = clock();
	for (int i = 0; i < 500; i++)
	reverse(string1, 4, sizeof(string1) - 1);
	end = clock();
	printf("%s\n", string1);
	printf("%d\n", end - start);
	return 0;
}