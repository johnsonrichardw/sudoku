import depth_first_search
import sudoku

def main():
    s = sudoku.sudoku()
    dfs = depth_first_search.depth_first_search(s)

    dfs.execute()


if __name__ == "__main__":
    main()

