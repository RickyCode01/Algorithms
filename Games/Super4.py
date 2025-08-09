import os
# Simulate Connect 4 game with python program: 

#1 Create a table to simulate game field:
# empty cells are marked with E(Empty) letter
# the first player cells are marked with R(Red) letter
# the second player cells are marked with Y(Yellow) letter

# define constant
COLUMNS = 6
ROWS = 5
RED = "\033[41m"
BLUE = "\033[44m"
RESETC = "\033[0m"
COLOR1 = RED + 'R' + RESETC
COLOR2 = BLUE + 'B' + RESETC

def PrintGrid(grid):
  os.system("clear")
  print(end='\n')
  print("\t  0   1   2   3   4   5   6")
  for row in range(COLUMNS):
    print("\t-----------------------------")
    print("\t| ", end='')
    for column in range(7):
      print(grid[row][column] + " |", end='')
      if column != 7:
        print(end=" ")
    print(end='\n') # new line
  print("\t-----------------------------\n")


def PlayTurn(grid, player:int):
  coln = input("digit column where insert disk(0 - 6): ")
  try:
    coln = int(coln)
    if coln >= 0 and coln <= COLUMNS:    
      for row in range(5, 0, -1):
        if grid[row][coln] == 'E':
          if player == 1:
            grid[row][coln] = COLOR1
          if player == 2:
            grid[row][coln] = COLOR2
          return [row,coln]
        if row == 0 and grid[row][coln] == 'E':
          print("column full, choose valid coln")
          return PlayTurn(grid, player)
    else:
      if coln > COLUMNS:
        print("Columnn index greater than num of colns\n")
      else:
        print("Negative index Not accepted\n")
        return PlayTurn(grid, player)
  except ValueError:
    print("Input Not accepted! column value must be between 0 and 6\n")
    return PlayTurn(grid, player)

def DebugGame(direction:str, x:int, y:int, val:str):
  print(direction + " x:" + str(x) + " y:" + str(y) + " val:" + val)

def CheckGame(grid, x:int, y:int, player:int, debug:bool):
  ''' Check all seven directions around last cell taken by player:
  if four consecutive cells of the same color are alligned in one of seven directions,
  player win'''
  color = COLOR1 if player == 1 else COLOR2
  # print(color)
  try:
    for direction in range(1, 8, 1): # (->, <-, v ->, v <-, ^ ->, ^ <-)
      if direction == 1: # RIGHT
        for step in range(1, 4, 1): # count 4 cells
          if y+step <= COLUMNS: # check index to avoid out of index error
            right = grid[x][y+step]
            if debug:
              DebugGame("Right",x, y+step, right)
            if right != color:
              break
            if step == 3 and right == color:
              return True
          else:
            break
      elif direction == 2: # LEFT
        for step in range(1, 4, 1):
          if y-step >= 0:
            left = grid[x][y-step]
            if debug:
              DebugGame("Left",x, y-step, left)
            if step == 3 and left == color:
              return True
            else:
              if left != color:
                break
          else:
            break
      elif direction == 3: # DOWN
        for step in range(1, 4, 1):
          if x+step <= ROWS:
            down = grid[x+step][y]
            if debug:
              DebugGame("Down",x+step, y, down)
            if down != color:
              break
            if step == 3 and down == color:
              return True
      elif direction == 4: # DOWN RIGHT
        for step in range(1, 4, 1):
          if x+step <= ROWS and y+step <= COLUMNS:
            downr = grid[x+step][y+step]
            if debug:
              DebugGame("Down Right",x+step, y+step, downr)
            if downr != color:
              break
            if step == 3 and downr == color:
              return True
          else:
            break
      elif direction == 5: # DOWN LEFT
        for step in range(1, 4, 1):
          if x+step <= ROWS and y-step >= 0: 
            downl = grid[x+step][y-step]
            if debug:
              DebugGame("Down Left",x+step ,y-step , downl)
            if downl != color:
              break
            if step == 3 and downl == color:
              return True
          else:
            break
      elif direction == 6: # UP RIGHT
        for step in range(1, 4, 1):
          if x-step >= 0 and y+step <= COLUMNS:
            upr = grid[x-step][y+step]
            if debug:
              DebugGame("Up Right",x-step ,y+step, upr)
            if upr != color:
              break
            if step == 3 and upr == color:
              return True
          else:
            break
      elif direction == 7: # UP LEFT
        for step in range(1, 4, 1):
          if x-step >= 0 and y-step >= 0:
            upl = grid[x-step][y-step]
            if debug:
              DebugGame("Up Left",x-step, y-step, upl)
            if upl != color:
              break
            if step == 3 and upl == color:
              return True
          else:
            break
    return False
  except IndexError:
    print("\nError -> x: " + str(x) + " y: " + str(y)) # debug

def InitPlayers():
  print(end='\n')
  player_1 = input("First player name: ") # first player name
  player_2 = input("Second player name: ") # second player name
  while(player_1 == '' or player_2 == ''):
    print("Invalid Names, Retry!")
    return InitPlayers()
  if player_1 == player_2:
    print("Players Names Must Be Different!")
    return InitPlayers()
  return [player_1, player_2]

def PrintWinner(player:str):
  frame = "\t+---------------------------+"
  text = "\t" + player + " WIN!"
  spaces = int((len(frame) - len(text))/2)
  print('\n' + frame + '\n')
  for i in range(spaces):
    print(" ", end='')
  print(text)
  for i in range(spaces):
    print(" ", end='')
  print('\n' + frame + '\n')

def Connect_4():
  # Init Game Field, Players and Variables
  players_names = InitPlayers()
  grid = [['E' for j in range(COLUMNS+1)] for i in range(ROWS+1)] # initialize grid
  end_game = False
  player = 1
  counter = 0

  # Start Game
  while(not end_game):
    PrintGrid(grid)
    counter = counter + 1 # Turn counter
    if player == 1:
      print("\tTurn " + str(counter) + " - Play " + players_names[0] +'\n')
    else:
      print("\tTurn " + str(counter) + " - Play " + players_names[1] +'\n')
    position = PlayTurn(grid, player)
    if (CheckGame(grid, position[0], position[1], player, False)):
      PrintGrid(grid)
      if player == 1:
        PrintWinner(players_names[0])
      else:
        PrintWinner(players_names[1])
      end_game = True
    else:
      player = 2 if player == 1 else 1 # change player


# PrintWinner("prova")
Connect_4()

# grid = [['E' for j in range(7)] for i in range(6)]
# print(grid)
# PrintGrid(grid)
# position = PlayTurn(grid, 1)
# print(position)
# PrintGrid(grid)
# PlayTurn(2)
# PrintGrid(grid)








