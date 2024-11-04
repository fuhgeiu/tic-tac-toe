#include <iostream>
#include "stream.hpp"

namespace core_data {
// class to disaply board data, with user defined settings and
    namespace board {

class board_data {

    char* m_data = nullptr;                                         // warning! nullptr, do not call destructor
    size_t m_length;
    size_t Range_upper, Range_lower;
    strm::condition *Condition = nullptr;                           // warning! nullptr, do not call destructor
    
                                                                    
public:

   board_data () = default;

   board_data (size_t cont_size) { m_length = cont_size; create_board_data_container(cont_size);    // instantiate condition
       auto *cond =  new strm::range(static_cast<int>(cont_size+1),-1); Condition = cond;
       Range_upper = cont_size;  Range_lower = 1;
   }

    ~ board_data () {                                                               // warning! undefined if m_data is a nullptr
       if (m_data != nullptr) delete m_data;
       if (Condition != nullptr) delete Condition;                                  // virtual destructor called
   }
    
   void create_board_data_container (size_t length) {                             // to create container for data

      m_data = new char[length]; m_length = length;                               // warning! new allocated array

      for (size_t i = 0; i < length; i++) { m_data[i] = static_cast <char> ((i+1)+'0'); }    // assign numbers to each
      auto *cond =  new strm::range(static_cast<int>(length+1),0); Condition = cond;
   }

   void print_board () {                                    // for 3 by 3 with 1d array

       for (size_t i = 0; i < 3; i++) {

           for (size_t j = 0; j < 3; j++) {                    // print elements number of collum times

               std::cout << m_data[i*3+j];  if (j < 2) std::cout << " | ";
           }
           if (i < 2) std::cout << "\n--+---+--\n";
       }
   }
    
    
public:
    
   const size_t& range_upper () const {return Range_upper;}
    
   const size_t& range_lower () const {return Range_lower;}

   void range ()  { Condition->output_range(); }                                   // prints out range from *range_spot

   void temp (char current_player,char player1, char player2) {        // to check if selected spot is open

       size_t spot = strm::get(std::cin, Condition);                        // stream member to get a int tha is within range

       while (m_data[spot-1] == player1 || m_data[spot-1] == player2) {   // itterate to check if spot is equal to player character

           std::cout << "spot is taken\n";
           spot = strm::get(std::cin, Condition);                             // call stream member to get new spot
       }
       m_data[static_cast<size_t> (spot)-1] = current_player;                  // warning! size_t size is bigger than int
   }
    
   const bool range_validation (size_t i) const {
        
       return Condition->pass_condition(i);                                            // implicit conversion, ok to loose precision
   }
    
   bool alchemist_special_availible () {
       
       size_t turns_taken = 0;
       for (size_t i = 0; i < m_length; i++) {if (m_data[i] < 10) {turns_taken++;}}
    
       if (turns_taken > 2) return true;
       else return false;
   }
    
   bool palidin_special_availible () {
        
       size_t turns_taken = 0;
       for (size_t i = 0; i < m_length; i++) {if (m_data[i] < 10) {turns_taken++;}}
    
       if (turns_taken > 0) return true;
       else return false;
   }
    
   bool compare_symbols (const char symbol, size_t spot) {
        
       if (m_data[spot] == symbol) {return true;} else return false;
   }
    
   void swap_marks (size_t spot1, size_t spot2) {
        
       m_data[spot1] = m_data[spot2];
       m_data[spot2] = m_data[spot1];
   }
    
    
    
public:

   void set_board_data (size_t spot, char current_player) {
        
       if (current_player == '\n') {std::cout << "WARNING current player is a null character";}
       m_data[spot-1] = current_player;
   }
    
   // to get a win , THIS IS TEMPORARY
   char won() {

       if ((m_data[0] == m_data[1]) && m_data[1] == m_data[2]) return m_data[0];
       else if ((m_data[3] == m_data[4]) && m_data[3] == m_data[5]) return m_data[4];
       else if ((m_data[6] == m_data[7]) && m_data[7] == m_data[8]) return m_data[6];
       
       else if ((m_data[0] == m_data[3]) && m_data[3] == m_data[6]) return m_data[3];
       else if ((m_data[1] == m_data[4]) && m_data[4] == m_data[7]) return m_data[4];
       else if ((m_data[2] == m_data[5]) && m_data[5] == m_data[8]) return m_data[4];

       else if ((m_data[0] == m_data[4]) && m_data[4] == m_data[8]) return m_data[4];
       else if ((m_data[2] == m_data[4]) && m_data[4] == m_data[6]) return m_data[4];
       else return '\0';
       
   }

   // only for test
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

}; // end of class board
} // end of namespace board


} // end of namespace core_data


