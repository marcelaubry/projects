// Copyright 2019 Nikolas Smith niksmith@bu.edu
// Copyright 2019 Marcel Aubry aubryma@bu.edu

#include <iostream>
#include <string>
#include <vector>
#include "movedef.h"

using std::cout;
using std::string;
using std::vector;

char tttresult(string tttboard) {
  // if statement checks that board is a valid length
  if (tttboard.size() == 9) {
    char cur;
    int X = 0, O = 0;
    string w = "########";
    // for loop creates strings of how many x's and o's there are
    for (int i = 0; i < tttboard.size(); i++) {
      cur = tttboard[i];
      if (cur == 'x')
        X++;
      else if (cur == 'o')
        O++;
      else if (cur == '#')
      {}
      else
        return 'e';
    }
    // if statement checks that there is a valid number of moves
    if (((X - O) != 1) && ((X - O) != 0))
      return 'i';

    // Create variables to check for wins in columns or rows
    char r1, r2, r3, c1, c2, c3;
    string md = "", od = "";
    // for loop
    for (int i = 0; i < 3; i++) {
      r1 = tttboard[i];
      r2 = tttboard[3 + i];
      r3 = tttboard[6 + i];
      // if statement checks on each column whether or not
      // there's three in a row
      if (r1 == 'x' and r2 == 'x' and r3 == 'x')
        w[i] = 'x';
      else if (r1 == 'o' and r2 == 'o' and r3 == 'o')
        w[i] = 'o';
      c1 = tttboard[i * 3];
      c2 = tttboard[1 + i * 3];
      c3 = tttboard[2 + i * 3];
      // if statement checks each row whether or not there's
      // three in a row
      if (c1 == 'x' and c2 == 'x' and c3 == 'x')
        w[i + 3] = 'x';
      else if (c1 == 'o' and c2 == 'o' and c3 == 'o')
        w[i + 3] = 'o';
      md = md + tttboard[i * 4];
      od = od + tttboard[2 + i * 2];
    }
    // if statement checks on each diagonal whether or not
    // there's three in a row
    if (md == "xxx")
      w[6] = 'x';
    else if (md == "ooo")
      w[6] = 'o';
    if (od == "xxx")
      w[7] = 'x';
    else if (od == "ooo")
      w[7] = 'o';
    char loc;
    // for loop checks if a winner had the right amount of moves
    for (int i = 0; i < 8; i++) {
      if (w[i] == 'x') {
        if ((X - O) != 1)
          return 'i';
      } else if (w[i] == 'o') {
        if ((X - O) != 0)
          return 'i';
      }
    }
    // for loop checks if there are multiple winners
    for (int i = 0; i < 8; i++) {
      loc = w[i];
      if (loc == 'x' or loc == 'o') {
        // once the loop finds a winner, it checks if there are
        // any others
        for (int j = i + 1; j < 8; j++) {
          if (w[j] != '#') {
            if (w[j] != loc)
              return 'i';
            else
              return loc;
          }
        }
        return loc;
      }
    }
    // for loop checks if there are any unplayed spaces
    for (int i = 0; i < tttboard.size(); i++) {
      if (tttboard[i] == '#')
        return 'c';
    }
    // if board has no unplayed spaces it is a tie
    return 't';
  } else {
    return 'e';
  }
}

char tttresult(vector<Move> board) {
  int ind = 0,
      L = board.size();
  string str = "";
  for (int i = 0; i < 9; i++)
    str = str + "#";
  if (L <= 9) {
    for (int i = 0; i < L; i ++) {
      ind = board[i].c + board[i].r * 3;
      if (str[ind] == '#')
        str[ind] = board[i].player;
      else
        return 'e';
    }
    char res;
    res = tttresult(str);
    return res;
  } else {
    return 'e';
  }
}

vector<string> get_all_boards() {
  vector<string> boards;
  int rem = 0, bin = 0;
  vector<int> rb(9);
  vector<string> allb(19683);
  string cur = "000000000";
  for (int i = 0; i < 19683; i++) {
    for (int j = 0; j < 9; j++) {
      int pow = 1;
      for (int k = 0; k < j; k++)
        pow = pow * 3;
      rem = i % pow;
      bin = (i - rem) / pow;
      rb[j] = bin % 3;
      if (rb[j] == 0)
        cur[j] = 'x';
      else if (rb[j] == 1)
        cur[j] = 'o';
      else
        cur[j] = '#';
    }
    allb[i] = cur;
  }
  return allb;
}

// This version of main interactively
// tests either:
//
//  string tttresult "s"
//  vector tttresult "v"
// or
//  get_all_boards "a"
//
// MAIN

int main() {
  // int n;
  // std::string board;
  // Move m;
  // std::vector<Move> moves;
  // std::vector<std::string> boards;
  // std::string asktype;
  // vector<string> allb = get_all_boards();
  // int cx = 0, co = 0, ct = 0, ci = 0, cc = 0, L = allb.size();

  // for (int i = 0; i < L; i++) {
  //   if (tttresult(allb[i]) == 'x')
  //     cx++;
  //   else if (tttresult(allb[i]) == 'o')
  //     co++;
  //   else if (tttresult(allb[i]) == 't')
  //     ct++;
  //   else if (tttresult(allb[i]) == 'i')
  //     ci++;
  //   else if (tttresult(allb[i]) == 'c')
  //     cc++;
  // }

  // cout << 'x' << ' ' << cx << '\n';
  // cout << 'o' << ' ' << co << '\n';
  // cout << 't' << ' ' << ct << '\n';
  // cout << 'i' << ' ' << ci << '\n';
  // cout << 'c' << ' ' << cc << '\n';

  // return 0;
}
