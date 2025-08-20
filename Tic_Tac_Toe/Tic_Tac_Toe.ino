#include <Adafruit_NeoPixel.h>

const int colCount = 3, colSize = 3;
const int colPins[3] = {11, 12, 13};
Adafruit_NeoPixel col1(colSize, colPins[0], NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel col2(colSize, colPins[1], NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel col3(colSize, colPins[2], NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel cols[3] = {col1, col2, col3};

const int buttonCount = 9;
const int buttons[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

const int R_VAL = 0, G_VAL = 1, B_VAL = 2;
const int colors[3][3] = {
    // color for each player
    {155, 155,   0},   // no player is blk
    {255,   0,   0}, // player 1 is red
    {  0,   0, 255}  // player 2 is blue
};
const int symbol[3] = {
    // symbol for each player
    '-', // no player is '-'
    'X', // player 1 is 'X'
    'O'  // player 2 is 'O'
};
int board[3][3];

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < colCount; i++)
  {
    cols[i].begin();
    cols[i].setBrightness(60);
  }
  for (int i = 0; i < buttonCount; i++)
  {
    pinMode(buttons[i], INPUT);
  }

  resetBoard();
  displayBoard();
  printBoard();

  bool loop_back = true;
  while (loop_back)
  {
    int player_move = buttonInput();
    int x = player_move / 3;
    int y = player_move % 3;
    printf("Player moves = (%d, %d)\n", x, y);
    board[x][y] = 1;
    displayBoard();
    printBoard();
    if (currentState() == 1)
    {
      displayBoard();
      printf("Player 1 won the game\n");
      loop_back = false;
      break;
    }
    if (currentState() == 0)
    {
      displayBoard();
      printf("It's a Draw\n");
      loop_back = false;
      break;
    }
    int move = bestMoveBy_AI();
    x = move / 3;
    y = move % 3;
    printf("AI moves = (%d, %d)\n", x, y);
    board[x][y] = 2;
    displayBoard();
    printBoard();

    if (currentState() == 2)
    {
      displayBoard();
      printf("AI has won the game\n");
      loop_back = false;
      break;
    }
    delay(100);
  }
}

void resetBoard()
{
  for (int i = 0; i < colCount; i++)
  {
    for (int j = 0; j < colSize; j++)
    {
      board[i][j] = 0;
    }
  }
  displayBoard();
}

void displayBoard()
{
  for (int i = 0; i < colCount; i++)
  {
    for (int j = 0; j < colSize; j++)
    {
      int player = board[i][j];
      cols[i].setPixelColor(j, cols[i].Color(colors[player][R_VAL], colors[player][G_VAL], colors[player][B_VAL]));
    }
    cols[i].show();
  }
}

void printBoard()
{
  Serial.print("\n+---+---+---+\n");
  for (int i = 3; i > 0; i--)
  {
    for (int j = 0; j < 3; j++)
    {
      Serial.print("| ");
      // Serial.print(symbol[board[i][j]]);
      Serial.print(board[j][i-1]);
      Serial.print(" ");
    }
    Serial.print("|\n+---+---+---+\n");
  }
}

int buttonInput()
{
  while (true)
  {
    for (int i = 0; i < buttonCount; i++)
    {
      if (digitalRead(buttons[i]) == HIGH && board[i / 3][i % 3] == 0)
      {
        return i;
      }
    }
    delay(10);
    displayBoard();
  }
}

char currentState()
{
  // This functions returns an int:
  // -1 if the game has not ended yet
  // 0 if it's a Draw
  // 1 if player 1 has won
  // 2 if player 2 has won

  // checking rows and columns
  for (int i = 0; i < 3; i++)
  {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) ||
        (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0))
    {
      return board[i][i]; // either 1 || 2
    }
  }
  // checking diagonals
  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != 0))
  {
    return board[1][1]; // either 1 || 2
  }

  // checking for empty cells
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == 0)
      {
        return -1; // to denote Non-terminal state
      }
    }
  }
  return 0; // to denote a Draw
}

int stateScore(int target)
{
  int state = currentState();

  // if the game has ended : return the current score
  if (state == 0) // Draw
    return 0;
  if (state == 1) // Player 1
    return +1;
  if (state == 2) // Player 2
    return -1;

  // if the game hasn't ended yet : evaluate the heuristic score
  if (target == -1) // player wants to minimise the score
  {
    int bestScore = +1;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[i][j] == 0)
        {
          board[i][j] = 2;
          int thisScore = stateScore(+1);
          bestScore = (thisScore < bestScore) ? thisScore : bestScore; // take min
          board[i][j] = 0;
        }
      }
    }
    return bestScore;
  }

  if (target == +1) // player wants to maximise the score
  {
    int bestScore = -1;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[i][j] == 0)
        {
          board[i][j] = 1;
          int thisScore = stateScore(-1);
          bestScore = (thisScore > bestScore) ? thisScore : bestScore; // take max
          board[i][j] = 0;
        }
      }
    }
    return bestScore;
  }
}

int bestMoveBy_AI()
{
  int x = 0, y = 0;
  int bestScore = +1;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == 0)
      {
        board[i][j] = 2;
        int thisScore = stateScore(+1);
        if (thisScore <= bestScore)
        {
          bestScore = thisScore;
          x = i;
          y = j;
        }
        board[i][j] = 0;
      }
    }
  }
  displayBoard();
  return 3 * x + y;
}

void loop()
{
  displayBoard();
  delay(1000);
}
