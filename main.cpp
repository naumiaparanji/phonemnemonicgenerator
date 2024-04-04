/* 
Author: Naumi Aparanji
nsaparanji@uh.edu
University of Houston
Computer Science 2026
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string NumberValid(string phoneNumber) {
  string message;
  if (phoneNumber.length() != 8){
    message = "Invalid phone number";
    return message;
  }
  if (phoneNumber.at(3) != '-') {
    message = "Invalid phone number";
  }
  for (int i = 0; i < phoneNumber.length(); ++i) {
    if (phoneNumber.at(i) == '1' || phoneNumber.at(i) == '0') {
      message = "Invalid phone number";
    }
  }
  for (int i = 0; i < 3; ++i) {
    if (!isdigit(phoneNumber.at(i))) {
      message = "Invalid phone number";
    }
  }
  for (int i = 4; i < 8; ++i) {
    if (!isdigit(phoneNumber.at(i))) {
      message = "Invalid phone number";
    }
  }
  return message;
}

string PossibleLetters(char number) {
  string output;
  if (number == '2') {
    output = "abc ";
  } else if (number == '3') {
    output = "def ";
  } else if (number == '4') {
    output = "ghi ";
  } else if (number == '5') {
    output = "jkl ";
  } else if (number == '6') {
    output = "mno ";
  } else if (number == '7') {
    output = "pqrs";
  } else if (number == '8') {
    output = "tuv ";
  } else if (number == '9') {
    output = "wxyz";
  }
  return output;
}

int main() {

  ifstream fin("ShortList.txt");
  if (!fin.is_open()) {
    cout << "File not open!" << endl;
  }
  ofstream fout("output.txt");
  if (!fout.is_open()) {
    cout << "Output file not open!" << endl;
  }

  // cout << "-------------------------------------------------------------" << endl;
  // cout << "Welcome to the Phone Number checker!" << endl;
  // cout << "-------------------------------------------------------------" << endl;
  // cout << endl;
  // cout << "Please enter a phone number to check if its valid or not: " << endl;

  string phoneNumber; 
  cout << "Please enter phone number in the format XXX-XXXX: " << endl;
  cin >> phoneNumber; 
  NumberValid(phoneNumber);
  cout << NumberValid(phoneNumber) << endl;
  
  if (NumberValid(phoneNumber) != "Invalid phone number"){

  char numbersArray[7];
  numbersArray[0] = phoneNumber.at(0);
  numbersArray[1] = phoneNumber.at(1);
  numbersArray[2] = phoneNumber.at(2);
  numbersArray[3] = phoneNumber.at(4);
  numbersArray[4] = phoneNumber.at(5);
  numbersArray[5] = phoneNumber.at(6);
  numbersArray[6] = phoneNumber.at(7);

  string word;
  vector<string> wordsThreeLetters;
  vector<string> wordsFourLetters;
  vector<string> wordsSevenLetters;

  while (fin >> word) {
    if (word.length() == 3) {
      wordsThreeLetters.push_back(word);
    } else if (word.length() == 4) {
      wordsFourLetters.push_back(word);
    } else if (word.length() == 7) {
      wordsSevenLetters.push_back(word);
    }
  }


    vector<string> threeWords;
    vector<string> fourWords;
    vector<string> sevenWords;
    
    for (int i=0; i< wordsThreeLetters.size(); i++){
    if ((wordsThreeLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(0) 
      || (wordsThreeLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(1) 
      || (wordsThreeLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(2)
      || (wordsThreeLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(3)){
        if ((wordsThreeLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(0) 
          || (wordsThreeLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(1)
          || (wordsThreeLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(2)
          || (wordsThreeLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(3)){
          if ((wordsThreeLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(0) 
            || (wordsThreeLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(1)
            || (wordsThreeLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(2)
            || (wordsThreeLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(3)){
            threeWords.push_back(wordsThreeLetters.at(i));
          }
        }
    }
  }

    for (int i=0; i< wordsFourLetters.size(); i++){
    if ((wordsFourLetters.at(i)).at(0) == PossibleLetters(numbersArray[3]).at(0) 
      || (wordsFourLetters.at(i)).at(0) == PossibleLetters(numbersArray[3]).at(1) 
      || (wordsFourLetters.at(i)).at(0) == PossibleLetters(numbersArray[3]).at(2)
      || (wordsFourLetters.at(i)).at(0) == PossibleLetters(numbersArray[3]).at(3)){
        if ((wordsFourLetters.at(i)).at(1) == PossibleLetters(numbersArray[4]).at(0) 
          || (wordsFourLetters.at(i)).at(1) == PossibleLetters(numbersArray[4]).at(1)
          || (wordsFourLetters.at(i)).at(1) == PossibleLetters(numbersArray[4]).at(2)
          || (wordsFourLetters.at(i)).at(1) == PossibleLetters(numbersArray[4]).at(3)){
          if ((wordsFourLetters.at(i)).at(2) == PossibleLetters(numbersArray[5]).at(0) 
            || (wordsFourLetters.at(i)).at(2) == PossibleLetters(numbersArray[5]).at(1)
            || (wordsFourLetters.at(i)).at(2) == PossibleLetters(numbersArray[5]).at(2)
            || (wordsFourLetters.at(i)).at(2) == PossibleLetters(numbersArray[5]).at(3)){
            if ((wordsFourLetters.at(i)).at(3) == PossibleLetters(numbersArray[6]).at(0) 
              || (wordsFourLetters.at(i)).at(3) == PossibleLetters(numbersArray[6]).at(1)
              || (wordsFourLetters.at(i)).at(3) == PossibleLetters(numbersArray[6]).at(2)
              || (wordsFourLetters.at(i)).at(3) == PossibleLetters(numbersArray[6]).at(3)){
                 fourWords.push_back(wordsFourLetters.at(i));
            }
          }
        }
    }
  }
        for (int i=0; i<threeWords.size();++i){
          for (int j=0; j <fourWords.size(); ++j){
            fout << threeWords.at(i) << " " << fourWords.at(j) << endl;
          }
        }

      for (int i=0; i< wordsSevenLetters.size(); i++){
    if ((wordsSevenLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(0) 
      || (wordsSevenLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(1) 
      || (wordsSevenLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(2)
      || (wordsSevenLetters.at(i)).at(0) == PossibleLetters(numbersArray[0]).at(3)){
        if ((wordsSevenLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(0) 
          || (wordsSevenLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(1)
          || (wordsSevenLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(2)
          || (wordsSevenLetters.at(i)).at(1) == PossibleLetters(numbersArray[1]).at(3)){
          if ((wordsSevenLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(0) 
            || (wordsSevenLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(1)
            || (wordsSevenLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(2)
            || (wordsSevenLetters.at(i)).at(2) == PossibleLetters(numbersArray[2]).at(3)){
            if ((wordsSevenLetters.at(i)).at(3) == PossibleLetters(numbersArray[3]).at(0) 
              || (wordsSevenLetters.at(i)).at(3) == PossibleLetters(numbersArray[3]).at(1)
              || (wordsSevenLetters.at(i)).at(3) == PossibleLetters(numbersArray[3]).at(2)
              || (wordsSevenLetters.at(i)).at(3) == PossibleLetters(numbersArray[3]).at(3)){
              if ((wordsSevenLetters.at(i)).at(4) == PossibleLetters(numbersArray[4]).at(0) 
              || (wordsSevenLetters.at(i)).at(4) == PossibleLetters(numbersArray[4]).at(1)
              || (wordsSevenLetters.at(i)).at(4) == PossibleLetters(numbersArray[4]).at(2)
              || (wordsSevenLetters.at(i)).at(4) == PossibleLetters(numbersArray[4]).at(3)){
                if ((wordsSevenLetters.at(i)).at(5) == PossibleLetters(numbersArray[5]).at(0) 
              || (wordsSevenLetters.at(i)).at(5) == PossibleLetters(numbersArray[5]).at(1)
              || (wordsSevenLetters.at(i)).at(5) == PossibleLetters(numbersArray[5]).at(2)
              || (wordsSevenLetters.at(i)).at(5) == PossibleLetters(numbersArray[5]).at(3)){
                  if ((wordsSevenLetters.at(i)).at(6) == PossibleLetters(numbersArray[6]).at(0) 
              || (wordsSevenLetters.at(i)).at(6) == PossibleLetters(numbersArray[6]).at(1)
              || (wordsSevenLetters.at(i)).at(6) == PossibleLetters(numbersArray[6]).at(2)
              || (wordsSevenLetters.at(i)).at(6) == PossibleLetters(numbersArray[6]).at(3)){
                    sevenWords.push_back(wordsSevenLetters.at(i));
                  }
                }
              }
            }
          }
        }
    }
  }
    for (int i=0; i<sevenWords.size(); ++i){
      fout << sevenWords.at(i) << endl;
    }
    if ((threeWords.empty() || fourWords.empty()) && sevenWords.empty()){
      fout << "No results!" << endl;
    }
  cout << "Please check the output file for the results!" << endl;
  }
  fin.close();
  fout.close();
  return 0;
}
