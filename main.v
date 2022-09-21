import os

fn main() {
	mut board := ['-', '-', '-', '-', '-', '-', '-', '-', '-']
	mut player_turn := 0
	mut game_finished := false
	for {
		if game_finished { break }
		os.system("clear")
		print_board(board)
		user := if player_turn == 0 { "Player 1" } else { "Player 2" }
		case := print_instruction(user)
		if check_case_valid(case, board) {
			board[case] = if player_turn == 0 {"x"} else {"o"} // apply the case
			if player_turn == 0 { player_turn = 1 } else { player_turn = 0 } // change turn
		} else {
			println("$user, your choice is already taken.")
		}

		if check_if_win(board) { game_finished = true }
	}

	os.system("clear")
	print_board(board)
	user := if player_turn == 1 { "Player 1" } else { "Player 2" }
	println("$user has won!")
}

fn print_board(board []string) {
	for i in 0..9 {
		c := board[i]
		print("| $c |")
		if ((i + 1) % 3) == 0 {
			print("\n")
		}
	}
}

fn print_instruction(player string) int {
	choice := os.input("$player, choose a square [1-9]: ")
	return choice.int() - 1
}

fn check_case_valid(case int, board []string) bool {
	if board[case] == "-" {
		return true
	}

	return false
}

fn check_if_win(b []string) bool {
  if b[0] != '-' {
    if b[0] == b[3] {
      if b[0] == b[6] {
        return true
	  }
	}
  }

  if b[0] != '-' {
    if b[0] == b[1] {
      if b[0] == b[2] {
        return true
	  }
	}
  }

  if b[0] != '-' {
    if b[0] == b[4] {
      if b[0] == b[8] {
        return true
	  }
	}
  }

  if b[1] != '-' {
    if b[1] == b[4] {
      if b[1] == b[8] {
        return true
	  }
	}
  }

  if b[1] != '-' {
    if b[1] == b[4] {
      if b[1] == b[7] {
        return true
	  }
	}
  }

  if b[3] != '-' {
    if b[3] == b[4] {
      if b[3] == b[5] {
        return true
	  }
	}
  }

  if b[2] != '-' {
    if b[2] == b[4] {
      if b[2] == b[6] {
        return true
	  }
	}
  }

  if b[2] != '-' {
    if b[2] == b[5] {
      if b[2] == b[8] {
        return true
	  }
	}
  }

  return false
}