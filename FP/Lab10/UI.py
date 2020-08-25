import numpy as ny
import sys
import math
import random
from Exception import RepoError


class Presentation:
    def __init__(self, service):
        self.__service = service

    def __board(self, row, column):
        return self.__service.create_board(row, column)

    def __print_board(self, board):
        print(ny.flip(board, 0))

    def __get_row(self, board, table_row, column):
        return self.__service.row(board, table_row, column)

    def __move(self, board, row, column, player):
        return self.__service.move(board, row, column, player)

    def __verify_win(self, board, row, column, table_row, table_column):
        return self.__service.win(board, row, column, table_row, table_column)

    def __block(self, board, table_row, table_column, x):
        return self.__service.block(board, table_row, table_column, x)

    def full_table(self, board, table_row, table_column):
        return self.__service.full_table(board, table_row, table_column)


    def util(self):
          table_row = 6
          table_column = 7
          board = self.__board(table_row, table_column)
          game_over = False
          turn = random.randint(0, 1)
          g = False
          self.__print_board(board)
          turn=0
          while game_over == False and g == False:
              g = self.full_table(board, table_row, table_column)
              if g == True and game_over == False:
                 self.__print_board(board)
                 print("Draw")
                 return
              else:
                  if turn%2==0:
                      print("Player move:")
                      column = int(input("move="))
                      try:
                          row = self.__get_row(board, table_row, column)
                          self.__move(board, row, column, 1)
                          game_over = self.__verify_win(board, row, column, table_row, table_column)
                          if game_over == True:
                              print("Player 1 won")
                              self.__print_board(board)
                              return
                          else:
                               turn += 1
                      except RepoError as re:
                          print("RepoError!")
                      self.__print_board(board)
                  else:
                      x = -1
                      x = self.__block(board, table_row, table_column, x)
                      if x != -1:
                          column = x
                      else:
                          column = random.randint(0, 6)
                      try:
                          row = self.__get_row(board, table_row, column)
                          self.__move(board, row, column, 2)
                          game_over = self.__verify_win(board, row, column, table_row, table_column)
                          if game_over == True:
                              print("Pc wins")
                              self.__print_board(board)
                              return
                          else:
                              turn += 1
                      except RepoError as re:
                          print("RepoError")
                      self.__print_board(board)

    def start(self):
      self.util()