#include <iostream>
#include <algorithm>
#include <string>

#ifdef UPPERCASE_VS_LOWERCASE
void solve(){
    std::string word;
    std::cin >> word;
    size_t counter{0};
    for(auto& c : word){
        if(std::isupper(c))
        {
            c = std::tolower(c);
            counter++;
        }
    }
    if(counter > word.length() / 2)
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    std::cout << word << std::endl;
}
#endif

#ifdef Some_other_snippet
void solve(){

}
#endif