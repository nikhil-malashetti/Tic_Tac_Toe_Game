#include <stdio.h>

#include <string.h>

int check_grid(char mat[3][3]);

int check_no_possible_win(char mat[3][3]);

void print_grid(char mat[3][3]);

int main()
{
	char mat[3][3];
	char player_1[20], player_2[20];
	int choice;

	printf("***************** Welcome to Tic Tac Toe ***************\n");

	while (1)
	{
		printf("\nGame Menu\n");
		printf("1. Play Game\n2. Rules of Game\n3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				{
					// Initialize the grid
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
							mat[i][j] = ' ';
					}

					// Get player names
					while (1)
					{
						printf("Enter Player 1 name: ");
						scanf(" %[^\n]", player_1);
						printf("Enter Player 2 name: ");
						scanf(" %[^\n]", player_2);
						if (strcmp(player_1, player_2) == 0)
							printf("Both players cannot have the same name! Try again.\n");
						else
							break;
					}

					int count = 0, win = 0;
					int r, c;

					print_grid(mat);

					// Gameplay loop
					while (count < 9 && win == 0)
					{
						// Player 1 turn
						while (1)
						{
							printf("\n%s's turn (X). Enter row (0-2) and column (0-2): ", player_1);
							scanf("%d %d", &r, &c);

							if (r >= 0 && r < 3 && c >= 0 && c < 3 && mat[r][c] == ' ')
							{
								mat[r][c] = 'X';
								break;
							}
							else
								printf("Invalid move! Try again.\n");
						}

						print_grid(mat);
						count++;

						if (check_grid(mat) == 1)
						{
							printf("\n%s won the game!!!\n", player_1);
							win = 1;
							break;
						}

						if (check_no_possible_win(mat))
						{
							printf("\nNo more possible winning combinations! It's a Draw!\n");
							break;
						}

						if (count == 9)
							break;

						// Player 2 turn
						while (1)
						{
							printf("\n%s's turn (O). Enter row (0-2) and column (0-2): ", player_2);
							scanf("%d %d", &r, &c);

							if (r >= 0 && r < 3 && c >= 0 && c < 3 && mat[r][c] == ' ')
							{
								mat[r][c] = 'O';
								break;
							}
							else
								printf("Invalid move! Try again.\n");
						}

						print_grid(mat);
						count++;

						if (check_grid(mat) == 2)
						{
							printf("\n%s won the game!!!\n", player_2);
							win = 1;
							break;
						}

						if (check_no_possible_win(mat))
						{
							printf("\nNo more possible winning combinations! It's a Draw!\n");
							break;
						}
					}

					if (win == 0 && !check_no_possible_win(mat) && count >= 9)
						printf("\nIt's a Draw!\n");

					break;
				}

			case 2:
				printf("\nRules of Tic Tac Toe:\n");
				printf("1. The game is played on a 3x3 grid.\n");
				printf("2. Player 1 is 'X' and Player 2 is 'O'.\n");
				printf("3. Players take turns placing their marks.\n");
				printf("4. The first to get 3 in a row (row, column, or diagonal) wins.\n");
				printf("5. If all 9 cells are filled or no possible win remains, the game is a draw.\n");
				break;

			case 3:
				printf("Exiting the game. Goodbye!\n");
				return 0;

			default:
				printf("Invalid choice! Please try again.\n");
		}
	}
}

void print_grid(char mat[3][3])
{
	printf("\n+-+-+-+\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("|%c", mat[i][j]);
		printf("|\n+-+-+-+\n");
	}
}

int check_grid(char mat[3][3])
{
	// Check rows
	for (int i = 0; i < 3; i++)
	{
		if (mat[i][0] != ' ' && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2])
			return (mat[i][0] == 'X') ? 1 : 2;
	}

	// Check columns
	for (int j = 0; j < 3; j++)
	{
		if (mat[0][j] != ' ' && mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j])
			return (mat[0][j] == 'X') ? 1 : 2;
	}

	// Check diagonals
	if (mat[0][0] != ' ' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
		return (mat[0][0] == 'X') ? 1 : 2;

	if (mat[0][2] != ' ' && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
		return (mat[0][2] == 'X') ? 1 : 2;

	return 0;
}

// Checks if any winning line is still possible
int check_no_possible_win(char mat[3][3])
{
	// Check each row, column, and diagonal
	int i, j;
	int possible = 0;

	// Check rows
	for (i = 0; i < 3; i++)
	{
		int hasX = 0, hasO = 0;
		for (j = 0; j < 3; j++)
		{
			if (mat[i][j] == 'X') hasX = 1;
			if (mat[i][j] == 'O') hasO = 1;
		}
		if (!(hasX && hasO))
			possible = 1; // at least one row is still winnable
	}

	// Check columns
	for (j = 0; j < 3; j++)
	{
		int hasX = 0, hasO = 0;
		for (i = 0; i < 3; i++)
		{
			if (mat[i][j] == 'X') hasX = 1;
			if (mat[i][j] == 'O') hasO = 1;
		}
		if (!(hasX && hasO))
			possible = 1;
	}

	// Check diagonals
	int hasX = 0, hasO = 0;
	for (i = 0; i < 3; i++)
	{
		if (mat[i][i] == 'X') hasX = 1;
		if (mat[i][i] == 'O') hasO = 1;
	}
	if (!(hasX && hasO))
		possible = 1;

	hasX = hasO = 0;
	for (i = 0; i < 3; i++)
	{
		if (mat[i][2 - i] == 'X') hasX = 1;
		if (mat[i][2 - i] == 'O') hasO = 1;
	}
	if (!(hasX && hasO))
		possible = 1;

	return (possible == 0); // if no possible win left
}

