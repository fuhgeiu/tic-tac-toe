#include <iostream>
#include "board.hpp"
#include "player.hpp"
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

/*
 
 READ ME        CLASS GUIDE
 
    
 
 
 
 
 
 
 
 */

namespace core_data {

   namespace game {

   
class game_data {                                           // store game data

    char player_1C, player_2C;                                                               // player symbols
    
    player::player_data* player_1 = nullptr; player::player_data* player_2 = nullptr;        // player data
    const player::player_data* const_player_1 = nullptr;  const player::player_data* const_player_2 = nullptr;  // const versions

    char current_playerC;                                                   // current player symbol
    
    const player::player_data* const_current_player = nullptr;              // current player data const version
    player::player_data* current_player = nullptr;                          // current player data

    char* m_data = nullptr;                                                 // non board class dependecny
    size_t m_length;                                                        // length of board, of non board class dependency

    board::board_data* board_data_obj = nullptr;                            // board class dependency

public: // constrcutors to instantiate with the use of pointers to defined types, !can use all games modes

   game_data () = default;

   game_data (player::player_data* player1, player::player_data* player2) { player_1 = player1; player_2 = player2; }

   game_data (player::player_data* starter, player::player_data* player1, player::player_data* player2) {

      current_player = starter; player_1 = player1; player_2 = player2;
      if (current_player == nullptr) std::cout << "WARNING current player not initialized";
      if (player_1 == nullptr) std::cout << "WARNING player 1 not initialized";
      if (player_2 == nullptr) std::cout << "WARNING player 2 not initialized";
      
   }

   game_data (player::player_data* player1, player::player_data* player2, size_t board_initialize_size){

       player_1 = player1; player_2 = player2;
       board_data_obj = new board::board_data(board_initialize_size);
       if (player_1 == nullptr) std::cout << "WARNING player 1 not initialized";
       if (player_2 == nullptr) std::cout << "WARNING player 2 not initialized";
   }
    
   game_data (player::player_data* starter, player::player_data* player1, player::player_data* player2, size_t board_initialize_size){
        
       player_1 = player1; player_2 = player2; current_player = starter;
       board_data_obj = new board::board_data(board_initialize_size);
       if (current_player == nullptr) std::cout << "WARNING current player not initialized";
       if (player_1 == nullptr) std::cout << "WARNING player 1 not initialized";
       if (player_2 == nullptr) std::cout << "WARNING player 2 not initialized";
   }
    
    
public: // const constructors
    
    game_data (const player::player_data* starter, const player::player_data* player1, const player::player_data* player2, bool is_const)
    
    :   const_player_1 (player1), const_player_2(player2), const_current_player(starter) {
        
        if (const_current_player == nullptr) std::cout << "WARNING const current player not initialized";
        if (const_player_1 == nullptr) std::cout << "WARNING const player 1 not initialized";
        if (const_player_2 == nullptr) std::cout << "WARNING const player 2 not initialized";
    }
    
    game_data (const player::player_data* player1, const player::player_data* player2, size_t board_initialize_size, bool is_const)
    
    :   const_player_1 (player1), const_player_2(player2) {
        
        if (const_player_1 == nullptr) std::cout << "WARNING const player 1 not initialized";
        if (const_player_2 == nullptr) std::cout << "WARNING const player 2 not initialized";
    }
    
    game_data (const player::player_data* starter, const player::player_data* player1, const player::player_data* player2, size_t board_initialize_size, bool is_const)
    
    :   const_player_1 (player1), const_player_2(player2), const_current_player(starter) {
        
        board_data_obj = new board::board_data(board_initialize_size);
        if (const_current_player == nullptr) std::cout << "WARNING const current player not initialized";
        if (const_player_1 == nullptr) std::cout << "WARNING const player 1 not initialized";
        if (const_player_2 == nullptr) std::cout << "WARNING const player 2 not initialized";
    }
    

public:  // constructors for instantiaiton with the use of primitives !ONLY uss with classic game mode

   game_data (char starting_player) { current_playerC = starting_player; }

   game_data (char starting_player, char player_1_symbol, char player_2_symbol) {

      current_playerC = starting_player; player_1C = player_1_symbol; player_2C = player_2_symbol;
   };
    
    
public:
// destructor for deleting game data object
   ~ game_data () {
       
       if (m_data != nullptr)               {delete[] m_data; m_data = nullptr; std::cout << "m_data deleted\n";}
       if (current_player == player_1 || current_player == player_2) {current_player = nullptr;}
       if (board_data_obj != nullptr)       {delete board_data_obj; std::cout << "board data deleted\n";}
       if (player_1 != nullptr)             {delete player_1; std::cout << "player 1 deleted\n";}
       if (const_player_1 != nullptr)       {delete const_player_1; std::cout << "player 1 deleted\n";}
       if (player_2 != nullptr)             {delete player_2; std::cout << "player 2 deleted\n";}
       if (const_player_2 != nullptr)       {delete const_player_2; std::cout << "player 2 deleted\n";}
       if (current_player != nullptr)       {delete current_player; std::cout << "current player deleted\n";}
       
       std::cout << "sucessfully deleted game\n";
   }

    
public:

   void switch_player () {                // warning! current player is nullptr by default, will not switch if not assigned properly

       if (current_player == nullptr) {std::cout << "WARNING current player is nullptr\n";}
            if (player_1 == nullptr) {std::cout << "WARNING player1 is null, canot switch\n";}
            if (player_2 == nullptr) {std::cout << "WARNING player2 is null, cannot switch\n";}
       if (current_player == player_1)  current_player = player_2;            // switch, current player becomes *player_2
            else if (current_player == player_2)  current_player = player_1;       // switch, current player becomes *player_1
   }
    
   void switch_player (bool is_const) {            // const version
        
       if (const_current_player == nullptr) {std::cout << "WARNING current player is nullptr\n";}
           if (const_player_1 == nullptr) {std::cout << "WARNING player1 is null, canot switch\n";}
           if (const_player_2 == nullptr) {std::cout << "WARNING player2 is null, cannot switch\n";}
       if (const_current_player == const_player_1)  const_current_player = const_player_1;
           else if (const_current_player == const_player_2)  const_current_player = const_player_2;
   }
    
   // do not use, improper function,
   void set_curernt_player (player::player_data* player)  {current_player = player;}      // set current player
   void set_current_player (const player::player_data* player, bool is_const) {const_current_player = player;}      // const version

   void get_set_spot ()  {
       
       current_player->display_menu(board_data_obj);
       current_player->validate(board_data_obj);
   }
    
   void get_set_spot (bool is_const) const {
        
       const_current_player->display_menu(board_data_obj);
       const_current_player->validate(board_data_obj);
   }

   const char current_player_status () {

       if (current_player == nullptr) {std::cout << "current player is null"; return '\0';}
       else {return current_player->player_symbol_is();}
   }
    
   char get_win () {return board_data_obj->won();}

   void print_board_board_data () { board_data_obj->print_board();}
    
    
public:         // members when not using a board object dependency or player dependecies, !Warning, only classic mode
    
    void switch_playerC () {                                           // switch current player, player 1 | player 2 char
        
       if (current_playerC == player_1C)  current_playerC = player_2C;
       else if (current_playerC == player_2C)  current_playerC = player_1C;
    }
    
    const char current_player_statusC () { return current_playerC; }           // return only char version
    
    void create_board_new (size_t length) {                                  // creates a new board using m_data pointer

       m_data = new char[length]; m_length = length;                               // warning! new allocated array
       for (size_t i = 0; i < length; i++) { m_data[i] = static_cast <char> ((i+1)+'0'); }      // assign numbers to each
    }
    
    void print_board_game_data () {                                    // for 3 by 3 with 1d array

         for (size_t i = 0; i < 3; i++) {
             for (size_t j = 0; j < 3; j++) {                    // print elements number of collum times

                 std::cout << m_data[i*3+j];
                 if (j < 2) std::cout << " | ";
             }
             if (i < 2) std::cout << "\n--+---+--\n";
         }
     }
    
//    char acess_data (size_t index)  { return board_data_obj->index_operator_data(index); }
    
    
public:             // test

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


};  // end of clas


}  // end of namespace game


}  // end of namespace core data

