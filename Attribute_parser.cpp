#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); 
    map<string, string> attributes;
    vector<string> tag_stack;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

      
        if (line.substr(0, 2) == "</") {
           
            if (!tag_stack.empty()) tag_stack.pop_back();
        } else {
           
            line.erase(0, 1);
            if (line.back() == '>') line.pop_back(); 

            stringstream ss(line);
            string tag_name, attr_name, equals, attr_value;
            
            ss >> tag_name;

          
            string current_path = "";
            for (const string& t : tag_stack) {
                current_path += (current_path.empty() ? "" : ".") + t;
            }
            string full_tag_path = (current_path.empty() ? "" : current_path + ".") + tag_name;
            
            tag_stack.push_back(tag_name);

           
            while (ss >> attr_name >> equals >> attr_value) {
              
                if (attr_value.front() == '"') attr_value.erase(0, 1);
                if (attr_value.back() == '"') attr_value.pop_back();
                
                attributes[full_tag_path + "~" + attr_name] = attr_value;
            }
        }
    }

    
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if (attributes.find(query) != attributes.end()) {
            cout << attributes[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
