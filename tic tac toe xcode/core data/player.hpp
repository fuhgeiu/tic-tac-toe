


namespace core_data {


    namespace player {

// interface for players, include methods of validation and of gettign character symbol
class player_data {
    
public:

    virtual ~player_data () = default;

    virtual char& player_symbol_is () = 0;                       // refernce to char player symbol    mutable player_symbol
    
    virtual const char& player_symbol_is () const = 0;           // return a const refernce to char player symbol non mutable
    
    virtual void display_menu (core_data::board::board_data*) const = 0;           // prompt the charter types rules and abilities
    
    virtual void validate (core_data::board::board_data*) const = 0;             // to get a valid spot
    
}; // end of class


class human : public player_data {

    char player_symbol;

public:
    
    human () = default;
    human (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {}
        
    void validate (core_data::board::board_data* board) const override {
        
        size_t board_spot;
        bool exit_loop = false;
        
        while (true) {
            
            std::cout << "Enter a number " << board->range_lower()  << " - " << board->range_upper()  << std::endl;
            
            std::cout << "spot {";
            std::cin >> board_spot;
            if (std::cin.fail()) {
                std::cout << "invalid input\n"; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            if (board->range_validation(board_spot) != true) {std::cout << "out of range\n";continue;}
                
            if (board->is_empty(board_spot) == false) {std::cout << "spot is taken\n";}
                else exit_loop = true; break;
            
            if (exit_loop) break;
        }
        std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        board->set_board_data(board_spot, player_symbol);
    } // end of validate
    
}; // end of human class

    
class computer : public player_data {
    
    char player_symbol = 'c';

public:

    computer () = default;
    computer (char symbol) {player_symbol = symbol;}

    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {std::cout << "computer is playing";}
    
    void validate (core_data::board::board_data* board) const override {return ;}
    
}; // end of class computer

    
class alchemist : public player_data {
    
    char player_symbol;
        
public:
    
    alchemist () = default;
    alchemist (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {
        
        std::cout << "Alchemist ----<>(( ( \n";
        if (board->alchemist_special_availible()) std::cout << "normal move (0) \nspecial ability availbile, swap marks (1)\n";
    }
    
    void validate (core_data::board::board_data* board) const override {
        
        size_t mode = 0;
        size_t swap1, swap2;
        
        if (board->alchemist_special_availible()) {             // if enough spots on board to use special ability
            
            std::cout << "enter a mode :";
            
            while (true) {                                      // to get mode
                
                std::cin >> mode;
                
                if (std::cin.fail()) {
                    
                    std::cout << "invalid input\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else break;
            }
        }
        
        if (mode == 1) {
            
            std::cout << "enter 1st mark to swap \n";
            
            while (true) {
                std::cin >> swap1;

                if (std::cin.fail() || (board->range_validation(swap1) == false)) {
                    std::cout << "Invalid input\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                
                if (board->is_empty(swap1)) {std::cout << "cannot swap with blank space\n"; continue;}
                    
                break;
            }

            while (true) {
                
                std::cout << "Enter 2nd mark to swap: ";
                std::cin >> swap2;

                if (std::cin.fail() || (board->range_validation(swap2) == false)) {
                    std::cout << "Invalid input\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                
                if (board->is_empty(swap2)) {std::cout << "cannot swap with blank space\n"; continue;}
                
                if (board->compare_symbols(player_symbol, swap2)) {
                    std::cout << "Cannot swap spots with identical symbols\n";
                }
                break;
            }
            board->swap_marks(swap1,swap2);
        }
        
        if (mode == 0) {
            
            size_t board_spot;
            bool exit_loop = false;
            
            while (true) {
                
                std::cout << "Enter a number " << board->range_lower()  << " - " << board->range_upper()  << std::endl;
                
                std::cout << "spot {";
                std::cin >> board_spot;
                if (std::cin.fail()) {
                    std::cout << "invalid input\n"; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                
                if (board->range_validation(board_spot) != true) {std::cout << "out of range\n";continue;}
                    
                if (board->is_empty(board_spot) == false) {std::cout << "spot is taken\n";}
                    else exit_loop = true; break;
                
                if (exit_loop) break;
            }
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            board->set_board_data(board_spot, player_symbol);
        } // end of validate
    }
    
}; // end of class alchamest
    
    
class paladin : public player_data {
        
    char player_symbol;
    
public:
    
    paladin () = default;
    paladin (char symbol) {player_symbol = symbol;}
    
    char& player_symbol_is () override {return player_symbol;}
    
    const char& player_symbol_is () const override {return player_symbol;}
    
    void display_menu (core_data::board::board_data* board) const override {
        
        std::cout << "Palidin <><<<+-- \n";
        if (board->palidin_special_availible()) std::cout << "normal move (0) \nspecial move availible (1)\n";
    }
 
    void validate (core_data::board::board_data* board) const override {
        
        size_t mode = 0, special_spot1, special_spot2;
        
        if (board->palidin_special_availible()) {
            
            std::cout << "enter a mode\n";
            
            while (true) {
                
                std::cin >> mode;
                
                if (std::cin.fail() || mode > 1) {
                    
                    std::cout << "invalid input\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); break;}
            }
        }

        if (mode == 1) {                                        // if special mode
                        
            while (true) {
                            
                std::cout << "choose a spot to shift to an adjacent spot\n";
                            
                std::cin >> special_spot1;                                          // spot to move
                            
                if (std::cin.fail()) {                                              // valid type
                                
                    std::cout << "invalid input\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;    // reprompt if not correct type
                }
                            
                if (board->is_empty(special_spot1)) {std::cout << "cannot move an empty spot\n";}  // spot must not be empty
                    else break;
                }  // while spot move
                    
            while (true) {                          // choose adjacent spot
                
                board->show_adjacent_spots(special_spot1);          // show adjacnet spots
            
                std::cout << "\nchoose an adjacent spot\n" << special_spot1 << "-->";
                        
                std::cin >> special_spot2;
                if (std::cin.fail()) {
                            
                    std::cout << "invalid input\n";
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if (board->adjacent_check(special_spot2) == false) {std::cout << "must be an adjacent spot\n";}
                    else break;
            }
                    // make changes to board, changes the second spot into the player symbol, change first spot to number
            board->shift_symbol(special_spot1, special_spot2);
                
            } // if special move
        
        if (mode == 0) {
            
            size_t board_spot;
            bool exit_loop = false;
            
            while (true) {
                
                std::cout << "Enter a number " << board->range_lower()  << " - " << board->range_upper()  << std::endl;
                
                std::cout << "spot {";
                std::cin >> board_spot;
                if (std::cin.fail()) {
                    std::cout << "invalid input\n"; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                
                if (board->range_validation(board_spot) != true) {std::cout << "out of range\n";continue;}
                    
                if (board->is_empty(board_spot) == false) {std::cout << "spot is taken\n";}
                    else exit_loop = true; break;
                
                if (exit_loop) break;
            }
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            board->set_board_data(board_spot, player_symbol);
        }
    } // Validate
        
}; // end of class paladin

    } // end of namespace player

} // namespace core_data

