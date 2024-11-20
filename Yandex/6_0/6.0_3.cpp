#include "6.0_3.h"
namespace SixthAlgoritms_3 {
    int taskA() {
        std::stack<char> stack;
        std::string str;
        std::cin >> str;
        char ch, previous;
        for (const char &ch: str) {
            if (ch == '[' || ch == '(' || ch == '{')
                stack.push(ch);
            else {
                if (!stack.empty()) {
                    previous = stack.top();
                    if (ch == ')' && previous == '(')
                        stack.pop();
                    else if (ch == ']' && previous == '[')
                        stack.pop();
                    else if (ch == '}' && previous == '{')
                        stack.pop();
                    else
                        break;
                } else {
                    std::cout << "no";
                    return 0;
                }
            }
        }

        if (stack.empty())
            std::cout << "yes";
        else
            std::cout << "no";

        return 0;
    }

    int taskB() {
        unsigned n, num;
        std::cin >> n;
        std::vector<int> ans(n, -1);
        std::stack<std::pair<unsigned, unsigned>> nums;
        std::pair<unsigned, unsigned> num_and_index;
        for (int i = 0; i < n; ++i) {
            std::cin >> num_and_index.first;
            num_and_index.second = i;
            while (!nums.empty() && nums.top().first > num_and_index.first) {
                ans[nums.top().second] = num_and_index.second;
                nums.pop();
            }
            nums.push(num_and_index);
        }

        for (const auto &el: ans) {
            std::cout << el << " ";
        }

        return 0;

    }

    int taskC() {
        int n, k, j = 0, num;
        std::cin >> n >> k;
        std::vector<int> ans(n - k + 1);
        std::deque<std::pair<int, int> > deque;
        std::pair<int, int> pair;
        for (int i = 0; i < k; ++i) {
            std::cin >> pair.first;
            pair.second = i;
            while (!deque.empty() && deque.back().first >= pair.first)
                deque.pop_back();
            deque.push_back(pair);
        }
        for (int i = k; i < n; ++i) {
            ans[j] = deque.front().first;
            if (deque.front().second == j++)
                deque.pop_front();
            std::cin >> pair.first;
            pair.second = i;
            while (!deque.empty() && deque.back().first >= pair.first)
                deque.pop_back();
            deque.push_back(pair);
        }
        ans[j] = deque.front().first;
        for (const auto &it: ans)
            std::cout << it << std::endl;
        return 0;
    }

    int taskD() {
        std::string s;
        std::getline(std::cin, s);
        auto new_end = std::remove(s.begin(), s.end(), ' ');
        s.erase(new_end, s.end());

        std::stack<std::string> stack;
        for (const char &item: s) {
            if (isdigit(item))
                stack.push(std::string(1, item));
            else {
                int num1, num2, head;
                switch (item) {
                    case '+':
                        num1 = (std::stoi(stack.top()));
                        stack.pop();
                        num2 = (std::stoi(stack.top()));
                        stack.pop();
                        stack.push(std::to_string(num1 + num2));
                        break;
                    case '-':
                        num1 = (std::stoi(stack.top()));
                        stack.pop();
                        num2 = (std::stoi(stack.top()));
                        stack.pop();
                        stack.push(std::to_string(num2 - num1));
                        break;
                    case '*':
                        num1 = (std::stoi(stack.top()));
                        stack.pop();
                        num2 = (std::stoi(stack.top()));
                        stack.pop();
                        stack.push(std::to_string(num2 * num1));
                        break;
                    default:
                        break;
                }
            }
        }
        std::cout << stack.top();

        return 0;
    }

    namespace taskE
    {
        void counting(const std::string&& s)
        {

            std::stack<std::string> stack;
            for (int i = 0; i < s.size(); ++i)
            {
                char item = s[i];
                std::string digit {""};
                if (isdigit(item)) {
                    while (i < s.size() && std::isdigit(s[i])) {
                        digit += s[i];
                        ++i;
                    }
                    --i;
                    stack.push(digit);
                }
                else if(isspace(item)) {continue;}
                else
                {
                    int num1, num2, head;
                    switch (item) {
                        case '+':
                            num1 = (std::stoi(stack.top())); stack.pop();
                            num2 = (std::stoi(stack.top())); stack.pop();
                            stack.push(std::to_string(num1 + num2));
                            break;
                        case '-':
                            num1 = (std::stoi(stack.top())); stack.pop();
                            num2 = (std::stoi(stack.top())); stack.pop();
                            stack.push(std::to_string(num2 - num1));
                            break;
                        case '*':
                            num1 = (std::stoi(stack.top())); stack.pop();
                            num2 = (std::stoi(stack.top())); stack.pop();
                            stack.push(std::to_string(num2 * num1));
                            break;
                        default:
                            break;
                    }
                }
            }
            std::cout << stack.top();
        }

        bool isValidExpression(const std::string& expr) {
            //if (isNumber(expr)) {return 0;}
            std::stack<char> parentheses;
            bool expectNumber = true;             // Ожидаем число или унарный минус
            bool lastWasOperator = false;         // Проверка на двойные операторы
            bool lastWasOpenParenthesis = false;  // Проверка на пустые скобки
            bool lastWasSpace = false;
            bool lastWasNum = false;

            for (size_t i = 0; i < expr.size(); ++i) {
                char c = expr[i];

                if (std::isspace(c)) {
                    lastWasSpace = true;
                    continue; // Пропускаем пробелы
                }

                if (c == '(') {
                    parentheses.push(c);
                    expectNumber = true;          // После открывающей скобки ожидаем число или унарный минус
                    lastWasOpenParenthesis = true; // Отметка для проверки пустых скобок
                    lastWasOperator = false;
                    lastWasSpace = false;
                    lastWasNum = false;
                } else if (c == ')') {
                    if (parentheses.empty() || lastWasOpenParenthesis) {
                        return false; // Несбалансированные скобки или пустые скобки
                    }
                    parentheses.pop();
                    expectNumber = false;         // После закрывающей скобки ожидаем оператор или конец выражения
                    lastWasSpace = false;
                    lastWasNum = false;
                    lastWasOpenParenthesis = false;
                } else if (c == '+' || c == '*' || c == '-') {
                    if (i == 0) {return 0;}
                    if (expectNumber) {
                        if (c == '-' && !lastWasOperator) {
                            expectNumber = true; // Унарный минус, ожидаем число после него
                        } else {
                            return false; // Недопустимый оператор, если ожидается число
                        }
                    } else {
                        expectNumber = true; // После бинарного оператора ожидаем число
                    }
                    lastWasOperator = true;
                    lastWasOpenParenthesis = false; // Сбрасываем флаг, если был оператор
                    lastWasNum = false;
                    lastWasOpenParenthesis = false;
                } else if (std::isdigit(c)) {
                    // Читаем целое число
                    while (i < expr.size() && std::isdigit(expr[i])) {
                        ++i;
                    }
                    --i; // Корректируем индекс
                    if (lastWasSpace && lastWasNum) {return 0;}
                    expectNumber = false;
                    lastWasOperator = false;
                    lastWasOpenParenthesis = false;
                    lastWasSpace = false;
                    lastWasNum = true;
                } else {
                    return false; // Недопустимый символ
                }
            }

            // Проверка на оставшиеся открытые скобки и недопустимый оператор в конце
            return parentheses.empty() && !expectNumber && !lastWasOperator;
        }

        std::string trans_to_reverse_polish(const std::string& str)
        {
            std::string ans;
            std::stack <char> stack;

            for (int i = 0; i < str.size(); ++i)
            {
                char ch = str[i];
                if (ch == '+' || ch == '-' || ch == '*' || ch == ')')
                {
                    if (ch == '+' || ch == '-' || ch == ')')
                    {
                        while (!stack.empty() && stack.top() != '(')
                        {
                            ans += stack.top();
                            ans += ' ';
                            stack.pop();
                        }
                        if (ch != ')')
                            stack.push(ch);
                        else
                            stack.pop();
                    }
                    else if (ch == '*')
                    {
                        while (!stack.empty() && stack.top() == '*')
                        {
                            ans += stack.top();
                            ans += ' ';
                            stack.pop();
                        }
                        stack.push(ch);
                    }
                }
                else if (ch == '(') {stack.push(ch);}
                if (std::isdigit(ch))
                {
                    while (i < str.size() && std::isdigit(str[i])) {
                        ans += str[i];
                        ++i;
                    }
                    ans += ' ';
                    --i;

                }
            }
            while (!stack.empty()) {
                ans += stack.top();
                ans += ' ';
                stack.pop();
            }

            return ans;
        }

        int taskE() {
            std::string str; std::getline(std::cin, str);

            if (isValidExpression(str))
                counting(trans_to_reverse_polish(str));
            else
                std:: cout << "WRONG";

            return 0;
        }
    }

    int taskF()
    {
        unsigned int n, cnt_open = 0, remain_len, cnt_free = 0, cnt_brackets = 0;
        std::string alph, ans;
        std::stack <char> brackets;
        std::cin >> n;  // Считываем число
        std::cin.ignore();  // Пропускаем символ новой строки после числа
        std::getline(std::cin, alph);  // Считываем строку со скобками
        std::getline(std::cin, ans);   // Считываем следующую строку со скобкам
        for (int i = 0; i < ans.size(); ++i){
            char bracket = ans[i];
            if (bracket == '(' || bracket == '[') {
                cnt_open++;
                brackets.push(bracket);
            }
            else if (bracket == ')' || bracket == ']')
            {
                brackets.pop();
                cnt_open--;
            }
            ++cnt_brackets;
        }
        remain_len = n - cnt_brackets;
        cnt_free = (remain_len - cnt_open) / 2;
        while (ans.size() != n)
        {
            if (!cnt_open)
            {
                for (int i = 0; i < 4; ++i) {
                    char bracket = alph[i];
                    if (bracket == '(' || bracket == '[') {
                        brackets.push(bracket);
                        ans += bracket;
                        break;
                    }
                }
                ++cnt_open;
                --remain_len;
                cnt_free = (remain_len - cnt_open) / 2;
            }
            else if (cnt_open && cnt_free)
            {
                bool flag = true;
                for (int i = 0; i < 4; ++i) {
                    if (!flag) {break;}
                    char bracket = alph[i];
                    if (bracket == ')' || bracket == ']'){
                        switch (bracket) {
                            case ')':
                                if (brackets.top() == '(')
                                {
                                    brackets.pop();
                                    ans += bracket;
                                    --cnt_open;
                                    --remain_len;
                                    cnt_free = (remain_len - cnt_open) / 2;
                                    flag = false;
                                }
                                break;
                            case ']':
                                if (brackets.top() == '[')
                                {
                                    brackets.pop();
                                    ans += bracket;
                                    --cnt_open;
                                    --remain_len;
                                    cnt_free = (remain_len - cnt_open) / 2;
                                    flag = false;
                                }
                        }
                    }
                    else if (bracket == '(' || bracket == '[')
                    {
                        ans += bracket;
                        ++cnt_open;
                        --remain_len;
                        brackets.push(bracket);
                        cnt_free = (remain_len - cnt_open) / 2;
                        flag = false;
                    }
                }
            }
            else
            {
                while (!brackets.empty())
                {
                    if (brackets.top() == '('){
                        ans += ')';
                        brackets.pop();
                        --cnt_open;
                        --remain_len;
                        cnt_free = (remain_len - cnt_open) / 2;
                    }
                    else{
                        ans += ']';
                        brackets.pop();
                        --cnt_open;
                        --remain_len;
                        cnt_free = (remain_len - cnt_open) / 2;
                    }
                    break;
                }
            }
        }
        std::cout << ans;
        return 0;
    }

    int taskG()
    {
        long long n,b, num, ans = 0, people = 0; std::cin >> n >> b;
        for (int i = 0; i < n; ++i) {
            std::cin >> num;
            ans += num + people;
            people = (people + num - b);
            if (people < 0) {people = 0;}
        }
        std::cout << ans + people;
        return 0;
    }

    int taskH()
    {
        int n, cnt_oper = 0; std::cin >> n;
        std::vector <long long> stack;
        std::vector <long long> pr_sum;
        std::vector <long long> ans;
        std::string operation;
        pr_sum.emplace_back(0);
        std::cin.ignore();
        for (int i = 1; i < n+1; ++i) {
            std::getline(std::cin, operation);
            if (operation[0] == '+') {
                operation.erase(0,1);
                stack.emplace_back(std::stoi(operation));
                pr_sum.emplace_back(pr_sum[pr_sum.size() - 1] + stack.back());
            }
            else if (operation == "-")
            {
                ans.emplace_back(stack.back());
                stack.pop_back();
                pr_sum.pop_back();
            }
            else
            {
                operation.erase(0,1);
                ans.emplace_back(pr_sum[pr_sum.size()-1] - pr_sum[pr_sum.size() - 1 - std::stoi(operation)]);
            }

        }
        for (const auto & it : ans)
        {
            std::cout << it << std::endl;
        }
        return 0;
    }

}