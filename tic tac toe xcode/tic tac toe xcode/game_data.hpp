#include <iostream>
#include "board.hpp"
/*
    Class
    A) class, store game session data

    Constructors
    1) core::data (starting player, player 1 symbol, player 2 symbol)
    2) core::data (starting player,)
 
    3) core:data::game (starter*, player*, player*)
    4) core::data::game (player*, player*, size_t)

    Member Functions
    1)core::data.switch_player () return void
    2)core::data.current_player () return char, current player symbol
    3)core::data

    ____________________________________________________________________________________________________________
    A) class to store game data
    1) cosntructor to store player data inside on the game_data object, as pirmitives and non user defined data types
    3) (starting player*, player1*, player2*) must pass pointers instantiated by the player class
    4)
 */

namespace core_data {

    namespace player {

//class player_data {                                         // store player data
//
//    char player_symbol;
//
//public:
//
//    player_data () = default;
//    player_data(char symbol) { player_symbol = symbol; }
//
//    char player_symbol_is () { return player_symbol; }
//}; // end of class
    
class player_data {
        
public:
    virtual const char player_symbol_is () = 0;
}; // end of class
    
    
class human : public player_data {
    
    char player_symbol;

public:
        
    human () = default;
    human (char symbol) { player_symbol = symbol; }

    const char player_symbol_is () { return player_symbol; }
}; // end of human class
    
class computer : public player_data {
        
    char player_symbol = 'c';
    
public:
    
    computer () = default;
        
}; // end of class
    

} // end of namespace player




   namespace game {

class game_data {                                           // store game data

    char player_1C, player_2C;                                              // player symbols
    player::player_data* player_1 = nullptr; player::player_data* player_2 = nullptr;       // player data

    char current_playerC;                            // current player symbol
    player::player_data* current_player = nullptr;           // current player data

    // pointer to container to store board data
    char* m_data = nullptr;                               // warning! nullptr cannnot be deallocated by delete operator
    size_t m_length;

    board::board_data* board_data_obj = nullptr;

public:

// constructers
   game_data () = default;

   game_data (player::player_data *player1, player::player_data *player2) { player_1 = player1; player_2 = player2; }

   game_data (player::player_data *starter,player::player_data *player1, player::player_data *player2) {

      current_player = starter; player_1 = player1; player_2 = player2;
   }

   game_data (player::player_data *player1, player::player_data *player2, size_t board_initialize_size){

       player_1 = player1; player_2 = player2;
       auto *board_data_instantiate = new board::board_data(board_initialize_size);
       board_data_obj = board_data_instantiate;
   }

public:

   game_data (char starting_player) { current_playerC = starting_player; }

   game_data (char starting_player, char player_1_symbol, char player_2_symbol) {

      current_playerC = starting_player; player_1C = player_1_symbol; player_2C = player_2_symbol;
   };

   ~ game_data () {
       if (m_data != nullptr) {delete[] m_data; m_data = nullptr;}     // warning! undefined behavior when m_data is a nullptr and destructor called
       if (board_data_obj != nullptr) {delete board_data_obj; board_data_obj = nullptr;}  // warning!
   }

public:

   void switch_playerC () {                                           // switch current player, player 1 | player 2 char

      if (current_playerC == player_1C)  current_playerC = player_2C;
      else if (current_playerC == player_2C)  current_playerC = player_1C;
   }

   void switch_player () {                // warning! current player is nullptr by default, will not switch if unchanged

      if (current_player == player_1)  current_player = player_2;            // switch, current player becomes *player_2
      else if (current_player == player_2)  current_player = player_1;       // switch, current player becomes *player_1
   }

   void set_curernt_player (player::player_data *player)  { current_player = player; }      // set current player

   void create_board_new (size_t length) {                                  // creates a new board using m_data pointer

      m_data = new char[length]; m_length = length;                               // warning! new allocated array
      for (size_t i = 0; i < length; i++) { m_data[i] = static_cast <char> ((i+1)+'0'); }      // assign numbers to each
   }

   void get_set_spot ()  {

       board_data_obj->get_spot_validated(current_player->player_symbol_is(),player_1->player_symbol_is(),player_2->player_symbol_is());
   }

   char const current_player_statusC () { return current_playerC; }           // return only char version

   char const current_player_status () {

       if (current_player == nullptr) {std::cout << "current player is null"; return '\0';}
         else return current_player->player_symbol_is();
   }
    
    char get_win () {return board_data_obj->won();}

    void print_board_board_data () { board_data_obj->print_board(); }

    void print_board_game_data () {                                    // for 3 by 3 with 1d array

        for (size_t i = 0; i < 3; i++) {

            for (size_t j = 0; j < 3; j++) {                    // print elements number of collum times

                std::cout << m_data[i*3+j];
                if (j < 2) std::cout << " | ";
            }
            if (i < 2) std::cout << "\n--+---+--\n";
        }
    }

    bool test_board_contianer () {

        bool is_correct = true;
        char expected[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        for (int i = 0; i < m_length; ++i) {
            if (m_data[i] != expected[i]) {
                std::cout << "Error at index " << i << ": expected " << expected[i] << ", got " << m_data[i] << std::endl;
                is_correct = false;
            }
        }
        return is_correct;
    }

    char acess_data (size_t index)  { return board_data_obj->index_operator_data(index); }



};  // end of clas


}  // end of namespace game



}  // end of namespace core data

