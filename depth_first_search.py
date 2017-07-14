import sudoku
import random

class depth_first_search():
    def __init__(self,s_board):
        self.stack = []
        self.stack.append(s_board)

    def execute(self):
        iteration = 0
        while True:
            #if iteration % 100 == 0:
            #    print("iteration: " + str(iteration));
            iteration += 1
            if len(self.stack) == 0:
                print("stack is empty, no solution found")
                return

            curr_board = self.stack.pop()

            x,y = curr_board.next_open_cell()

            vals = sudoku.valid_value
            random.shuffle(vals)

            for v in vals:
                new_board = curr_board.copy()
                new_board.set_value(v,x,y)
                if new_board.check_rules(x,y) == True:
                    if new_board.solution_check() == True:
                        print("Solution Found in " + str(iteration) + " iterations:")
                        new_board.print_board()
                        return
                    self.stack.append(new_board)

