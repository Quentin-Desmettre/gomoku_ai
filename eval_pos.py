from eval_shape import eval_shape

def end_of_sequence(consecutive, open_ends, is_my_turn):
    s = eval_shape(consecutive, open_ends, is_my_turn)
    return s

def analyze_rows(grid, color, is_my_turn):
    # analyze rows:
    consecutive = 0
    open_ends = 0
    score = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            # new valid char
            if grid[i][j] == color:
                consecutive += 1

            # empty char
            elif grid[i][j] == 0:
                if consecutive > 0:
                    # empty char and there is multiple valid char before
                    open_ends += 1
                    score += end_of_sequence(consecutive, open_ends, is_my_turn)
                    consecutive = 0
                    open_ends = 1
                else:
                    # empty char in a row
                    open_ends = 1

            # opponent char
            else:
                if consecutive > 0:
                    score += end_of_sequence(consecutive, open_ends, is_my_turn)
                    consecutive = 0
                    open_ends = 1
                else:
                    open_ends = 0
    return score

def analyze_columns(grid, color, is_my_turn):
    # analyze rows:
    consecutive = 0
    open_ends = 0
    score = 0

    for i in range(len(grid[0])):
        for j in range(len(grid)):
            # new valid char
            if grid[j][i] == color:
                consecutive += 1

            # empty char
            elif grid[j][i] == 0:
                if consecutive > 0:
                    # empty char and there is multiple valid char before
                    open_ends += 1
                    score += end_of_sequence(consecutive, open_ends, is_my_turn)
                    consecutive = 0
                    open_ends = 1
                else:
                    # empty char in a row
                    open_ends = 1

            # opponent char
            else:
                if consecutive > 0:
                    score += end_of_sequence(consecutive, open_ends, is_my_turn)
                    consecutive = 0
                    open_ends = 1
                else:
                    open_ends = 0
    return score

def analyze_grid_for_color(grid, color, is_my_turn):
    score = 0
    score += analyze_rows(grid, color, is_my_turn)
    score += analyze_columns(grid, color, is_my_turn)
    return score

def analyze_ia_pos(grid, is_ia_turn):
    return analyze_grid_for_color(grid, -1, is_ia_turn)

def analyze_player_pos(grid, is_ia_turn):
    return analyze_grid_for_color(grid, 1, is_ia_turn)

def analyze_gomoku(grid, is_ia_turn):

    # First: analyze the ia position
    ia_score = analyze_ia_pos(grid, is_ia_turn)
    # Second: analyze the player position
    player_score = analyze_player_pos(grid, is_ia_turn)

    #print("ia score:", ia_score)
    #print("player  :", player_score)

    return [player_score, ia_score]
    # if is ai turn, substract player_score to ia_score
    if is_ia_turn:
        return ia_score - player_score
    # else, substract ia_score to player_score
    else:
        return player_score - ia_score
