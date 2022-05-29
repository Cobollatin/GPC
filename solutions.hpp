#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <utility>
#include <deque>

#if UPPERCASE_VS_LOWERCASE
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

#if PALINDROME_PHILIA
void solve(){
    std::string word;
    std::cin >> word;
    size_t counter{0};
    for(size_t i{0}; i < word.length() / 2; i++){
        if(word[i] != word[word.length() - 1 - i]){
            counter++;
        }
    }
    std::cout << counter;
}
#endif

#if Bingo
void solve(){
    int N{-1}, B{- 1};
    while(std::cin >> N >> B){
        if(N == 0 && B == 0)
            break;
        std::vector<int> numbers(B);
        std::vector<bool> used(N);
        bool bingo{true};
        for(size_t i{0}; i < B; i++){
            std::cin >> numbers[i];
            used[numbers[i]] = true;
            for(size_t j{0}; j < i; j++){
                used[std::abs(numbers[j] - numbers[i])] = true;
            }
        }
        for(size_t i{0}; i < N; i++){
            if(!used[i]){
                bingo = false;
                break;
            }
        }
        std::cout << (bingo ? "Y" : "N") << std::endl;
    }
}
#endif

#if FLOWERS_FLOURISH_FROM_FRANCE
void solve(){
    std::string sentence;
    while(getline(std::cin, sentence)){
        if(sentence == "*")
            break;
        std::stringstream ss(sentence);
        getline(ss, sentence, ' ');
        char first_letter = std::tolower(sentence[0]);
        bool isTautogram{true};
        while(getline(ss, sentence, ' ')){
            if(std::tolower(sentence[0]) != first_letter)
            {
                isTautogram = false;
                break;
            }
        }
        std::cout << (isTautogram ? 'Y' : 'N') << '\n';
    }

}
#endif

#if OJUMPS
void solve(){
    size_t a{0};
    std::cin >> a;
    constexpr int max_jump{1 + 2 + 3};
    constexpr int mid_jump{1 + 2};
    constexpr int min_jump{1};

    if(a >= max_jump)
        a %= max_jump;

    if(a == 0 || a == mid_jump || a == min_jump)
    {
        std::cout << "yes" << std::endl;
        return;
    }
    std::cout << "no" << std::endl;
}
#endif  

#if FANCY_QUOTES
void solve(){
    size_t T{0};
    std::cin >> T;
    std::cin.ignore();
    for(size_t i = 0; i < T; i++){
        std::string quote;
        std::getline(std::cin, quote);
        bool fancy{false};
        for(size_t i = 0; i < quote.length() - 2; i++) {
            if((quote[i] == 'n' && quote[i + 1] == 'o' && quote[i + 2] == 't') && (i + 3 == quote.length() || quote[i + 3] == ' ') && (quote[i - 1] == ' ' || i == 0))
            {
                fancy = true;
                break;
            }
        }
        if(fancy)
        {
            std::cout << "Real fancy" << std::endl;
            continue;
        }
        std::cout << "regularly fancy" << std::endl;
    }
}
#endif

#if ROT_N
void solve(){
    size_t N{0};
    std::cin >> N;
    std::string S;
    std::cin >> S;
    for(char& c : S){
        c = (c - 'A' + N) % 26 + 'A';
    }
    std::cout << S;
}
#endif

#if CHEF_AND_SUBARRAY
void solve(){
    size_t N{0};
    std::cin >> N;
    std::vector<int> A(N);
    for(size_t i{0}; i < N; i++){
        std::cin >> A[i];
    }
    size_t counter{0};
    size_t best_counter{0};
    for(const int& a : A){
        if(a == 0)
        {
            if(best_counter < counter)
                best_counter = counter;
            counter = 0;
            continue;
        }
        counter++;
    }
    if(best_counter < counter)
        best_counter = counter;
    std::cout << best_counter;
}
#endif

#if COUNT_SUBSTRING
void solve(){
    size_t T{0};
    std::cin >> T;
    for(size_t i = 0; i < T ; ++i){
        size_t N{0};
        std::cin >> N;
        std::string S;
        std::cin >> S;
        size_t counter{0};
        for(const char& c : S)        {
            counter += c == '1';
        }
        std::cout << counter * (counter + 1) / 2 << '\n';
    }
}
#endif

#if SUMMING_THE_N_SERIES
void solve(){
    size_t t{0};
    std::cin >> t;
    for(size_t i = 0; i < t ;++i){
        unsigned long long n{0};
        std::cin >> n;
        std::cout << (((n % 1000000007ul) * (n % 1000000007ul)) % 1000000007ul) << '\n';
    }
}
#endif

#if HRML_PARSER
void solve(){
    size_t N{0};
    size_t Q{0};
    std::cin >> N >> Q;
    std::vector<std::string> stack(N);
    std::string line;
    std::cin.ignore();
    for(size_t i{0}; i < N; i++){
        std::getline(std::cin, line);
        //line[1] == '/' ? stack.pop_back() : (void)stack.emplace_back(line.substr(1, line.find(' ')));
        stack.emplace_back(line);
    }

    std::deque<std::string> queries(Q);
    for(size_t i{0}; i < Q; i++){
        std::getline(std::cin, line);
        queries[i] = line;
    }

    while(!queries.empty()){
        std::stringstream ss(queries.front());
        std::vector<std::string> tags;
        while(std::getline(ss, line, '.')){
            tags.emplace_back(line);
        }

        size_t valuePos = tags.back().find("~");
        std::string value = tags.back().substr(valuePos + 1);
        tags.back().erase(valuePos);

        bool found{false};
        size_t tagPosition{0};
        for(size_t i{0}; i < stack.size(); i++){
            if(tagPosition == tags.size())
                break;
            if(stack[i].find('/') != std::string::npos){
                continue;
            }
            if(stack[i].find(tags[tagPosition]) != std::string::npos){
                tagPosition++;
                if(tagPosition == tags.size()){
                    if(stack[i].find(value) != std::string::npos){
                        found = true;
                        break;
                    }
                }
            }
            else{
                tagPosition = 0;
            }
        }

        std::cout << (found ? value : "Not Found!") << '\n';

        queries.pop_front();
    }
}
#endif