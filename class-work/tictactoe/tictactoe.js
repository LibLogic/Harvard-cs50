let board = [
    [-1, -1, 1],
    [0, 1, -1],
    [1, 1, -1]
];

function checkBoard(board) {
  let boardCount = [];
  boardCount = countBoard(board);
  let difference = boardCount[0] - boardCount[1];

  if (Math.abs(difference) > 1) {
    return 'Board Invalid';
  } else {
    return checkForWin(board);
  }

  function checkForWin(board) {
    // Check Columns for win
    let col0Total = 0, col1Total = 0, col2Total = 0;
    for (var i = 0; i < 3; i++) {
      let rowTotal = 0;
      for (var j = 0; j < 3; j++) {
        if (j === 0 ) {
          col0Total += board[i][j];
        }
        if (j === 1 ) {
          col1Total += board[i][j];
        }
        if (j === 2 ) {
          col2Total += board[i][j];
        }

        if (col0Total === -3 || col1Total === -3 || col2Total === -3) {
          return '"X" Wins Vertically';
        }
        if (col0Total === 3 || col1Total === 3 || col2Total === 3) {
          return '"O" Wins Vertically';
        }

        // Check rows for win
        rowTotal += board[i][j];
        if (rowTotal === -3) {
            return '"X"Wins Horizontally';
        }
        if (rowTotal === 3) {
            return '"O" Wins Horizontally';
        }

        // Check diagonals for win
        if (board[0][0] + board[1][1] + board[2][2] === -3 ||
            board[0][2] + board[1][1] + board[2][0] === -3) {
          return '"X" Wins Diagonally';
        }
        if (board[0][0] + board[1][1] + board[2][2] === 3 ||
            board[0][2] + board[1][1] + board[2][0] === 3) {
          return '"O" Wins Diagonally';
        }
      }
    }
    if (Math.abs(difference) == 1 && (boardCount[0] + boardCount[1]) == 9 ) {
    return "Tie";
    }
    return 'Incomplete Board';
  }


  function countBoard(board) {
    var xCount = 0, oCount = 0, zCount = 0;
    for (var k = 0; k < 3; k++) {
      for (var l = 0; l < 3; l++) {
        if (board[k][l] === 0 ) {
          zCount++;
        }
        if (board[k][l] === -1) {
          xCount++;
        }
        if (board[k][l] === 1) {
          oCount++;
        }
      }
    }
    return [xCount, oCount, zCount];
  }
}

console.log(checkBoard(board));