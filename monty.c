#include "monty.h"

/**
 *main- main entry of program
 * @argc: name of file
 * @argv: List of arguments
 * Return: Success otherwise failure
 */
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};

	FILE *file_stream;
	char *line_read;
	char *tokenization;
	stack_t *my_stack = NULL;
	unsigned int code_lineNumber = 0;

	size_t length = 0;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_stream = fopen(argv[1], "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line_read, &length, file_stream)) != -1)
	{
		tokenization = strtok(line_read, " \t\n");

		if (line_read[0] == '#' || line_read[0] == '\n')
		{
			continue;
		}
		code_lineNumber++;

		if (tokenization != NULL)
		{
			int op = 0;

			while (commands[op].opcode != NULL)
			{
				if (strcmp(tokenization, commands[op].opcode) == 0)
				{
					commands[op].f(&my_stack, code_lineNumber);
					break;
				}
				op++;
			}
			if (commands[op].opcode == NULL)
			{
				char *wrong = tokenization;
				unsigned int number_line = code_lineNumber;
				char *errorMessage = "L%u: unknown instruction %s\n";

				fprintf(stderr, errorMessage, number_line, wrong);
				fclose(file_stream);
				free(line_read);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line_read);
	fclose(file_stream);
	exit(EXIT_SUCCESS);
}
