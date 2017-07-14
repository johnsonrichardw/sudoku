
BOARD_SIZE = 9
valid_value = [x for x in range(1,BOARD_SIZE+1)]

class sudoku():
    def __init__(self):
        #Initialize board
        self.board = [[0 for y in range(BOARD_SIZE)] for x in range(BOARD_SIZE)]

    def set_value(self,val,x,y):
        if val not in valid_value:
            raise ValueError('Value (' + val + ') is not a valid value (' + valid_value + ')')
        self.board[x][y] = val

    def check_rules(self,x,y):
        return self.rows_valid(x,y) and self.columns_valid(x,y) and self.ninths_valid(x,y)

    def rows_valid(self,x,y):
        used = [False for i in range(BOARD_SIZE+1)]
        for i in used:
            used[i] = False
        for c_x in range(BOARD_SIZE):
            if self.board[c_x][y] != 0 and used[self.board[c_x][y]] == True:
                return False
            used[self.board[c_x][y]] = True
        return True
                
    def columns_valid(self,x,y):
        used = [False for i in range(BOARD_SIZE+1)]
        for i in used:
            used[i] = False
        for c_y in range(BOARD_SIZE):
            if self.board[x][c_y] != 0 and used[self.board[x][c_y]] == True:
                return False
            used[self.board[x][c_y]] = True
        return True

    def ninths_valid(self,x,y):
        used = [False for i in range(BOARD_SIZE+1)]
        n_x = int(x/3)
        n_y = int(y/3)
        for i in used:
            used[i] = False
        for c_x in range(int(BOARD_SIZE/3)):
            for c_y in range(int(BOARD_SIZE/3)):
                a_x = c_x + n_x * 3
                a_y = c_y + n_y * 3
                if self.board[a_x][a_y] != 0 and used[self.board[a_x][a_y]] == True:
                    return False
                used[self.board[a_x][a_y]] = True
        return True

    def next_open_cell(self):
        for x in range(BOARD_SIZE):
            for y in range(BOARD_SIZE):
                if self.board[x][y] == 0:
                    return x,y
        return 0,0

    def solution_check(self):
        for x in range(BOARD_SIZE):
            for y in range(BOARD_SIZE):
                if self.board[x][y] == 0:
                    return False

        return True

    def copy(self):
        c = sudoku()
        for x in range(BOARD_SIZE):
            for y in range(BOARD_SIZE):
                c.board[x][y] = self.board[x][y]
        return c


    def print_board(self):
        hline = '+---+---+---+'
        line = ''
        for y in range(BOARD_SIZE):
            if y % 3 == 0:
                print(hline)
            line = ''
            for x in range(BOARD_SIZE):
                if x % 3 == 0:
                    line += '|'
                line += str(self.board[x][y])
            line += '|'
            print(line)
        print(hline)

