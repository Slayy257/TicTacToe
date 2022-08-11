#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[]);
bool check_board_choice_is_valid(char b[], int input);
bool has_a_player_win(char b[]);

int main(void) {
  bool game_finish = false;
  int player_turn = 0; // 0 == x 1 == o
  char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

  while (!game_finish) {
    system("clear");
    printBoard(board);
    printf("\n%s, choose a square [1-9]: ",
           !player_turn ? "Player 1 ( X )" : "Player 2 ( O )");
    int input;
    scanf("%d", &input);

    if (check_board_choice_is_valid(board, input)) {
      int i = input - 1;
      board[i] = !player_turn ? 'x' : 'o';
      if (player_turn == 0)
        player_turn = 1;
      else if (player_turn == 1)
        player_turn = 0;
    } else {
      printf("\n%s, your choice is already taken.\n",
             !player_turn ? "Player 1 ( X )" : "Player 2 ( O )");
    }

    if (has_a_player_win(board)) {
      game_finish = true;
    }
  }

  printBoard(board);
  printf("%s Win !\n", !player_turn ? "Player 1" : "Player 2");

  return 0;
}

void printBoard(char board[]) {
  for (int i = 0; i < 9; i++) {
    printf("| %c |", board[i]);
    if (((i + 1) % 3) == 0) {
      printf("\n");
    }
  }
}

bool check_board_choice_is_valid(char b[], int input) {
  if (b[input - 1] == '-')
    return true;

  return false;
}

bool has_a_player_win(char b[]) {
  if (b[0] != '-')
    if (b[0] == b[3])
      if (b[0] == b[6])
        return true;

  if (b[0] != '-')
    if (b[0] == b[1])
      if (b[0] == b[2])
        return true;

  if (b[0] != '-')
    if (b[0] == b[4])
      if (b[0] == b[8])
        return true;

  if (b[1] != '-')
    if (b[1] == b[4])
      if (b[1] == b[8])
        return true;

  if (b[3] != '-')
    if (b[3] == b[4])
      if (b[3] == b[5])
        return true;

  if (b[2] != '-')
    if (b[2] == b[4])
      if (b[2] == b[6])
        return true;

  if (b[2] != '-')
    if (b[2] == b[5])
      if (b[2] == b[8])
        return true;

  return false;
}