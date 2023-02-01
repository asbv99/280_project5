#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include "csvstream.h"

using namespace std;

// EFFECTS: Returns a set containing the unique "words" in the original
//          string, delimited by whitespace.
set<string> unique_words(const string &str) {
    istringstream source(str);
    set<string> words;
    string word;
    
    // Read word by word from the stringstream and insert into the set
    while (source >> word) {
        words.insert(word);
    }
    return words;
}

class Classifier {
    
    public:
        //sort tag(about) and string(post)
        Classifier(csvstream &csv) {
           
            //READ IN THE POSTS & TAGS
            map<string, string> main_dummy;
            while(csv >> main_dummy){
                main_sorting_content[main_dummy["content"]] = main_dummy["tag"];
            }
            numPosts = main_sorting_content.size();
            cout << numPosts << endl;
        }
//            for(auto i : main_sorting_content) {
//                cout << i.second <<  " " << i.first << endl;
//            }
//            vocab_count();
//            num_posts_of_label();
//        }
//
//
//    // EFFECTS:
//    void vocab_count(){
//        for(auto i : main_sorting_content){
//            set<string> help = unique_words(i.first);
//            for (auto j : help) {
//                unico[j] += 1;
//            }
//        }
//        numVocab = unico.size();
//    }
//
//    // EFFECTS:
//    void num_posts_of_label(){
//        for(auto i : main_sorting_content){
//            labels[i.second] +=1;
//        }
//    }

    // EFFECTS:
//    void for_each_label(){
//        for(auto i : main_sorting_content){
//            for(auto i : labels) {
//
//            labels[i.second] +=1;
//        }
//    }
    private:
        map<string, string> main_sorting_content;
        map<string, int> unico;
        map<string, int> labels;
        map<string, int> posts_with_both;
        int numPosts;
       // int numVocab;












};

















int main(int argc, char* argv[]) {
    cout.precision(3);
    if(argc != 3 && argc != 4) {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }
    
    string file1 = argv[1];
    string file2 = argv[2];
    ifstream filetrain(file1);
    ifstream filetest(file2);
    if(!filetrain.is_open()) {
        cout << "Error opening file: " << file1 << endl;
        return 1;
    }
    if(!filetest.is_open()) {
        cout << "Error opening file: " << file2 << endl;
        return 1;
    }
    
    csvstream traincsv(filetrain, ',');
    csvstream testcsv(filetest, ',');
    
    Classifier numeroUno(traincsv);
    
    
}


