bool variable_declaration_check(std::fstream& file_code,std::fstream& file_error); // check for duplicate declarations
bool variable_initialization_check(std::fstream& file_code,std::fstream& file_error);  // check whether all variables are declared or not ? 
bool function_check(std::fstream& file_token,std::fstream& file_error);
bool array_declaration_check(std::fstream& file_code); //check whether the declaration of array is valid of not
