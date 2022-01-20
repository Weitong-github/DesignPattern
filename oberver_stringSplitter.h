#include <string>
#include <iostream>

class IProgress {
public:
    virtual void DoProgress (float value) = 0;
    virtual ~IProgress(){}
};

class StringSplit {
 private:
    std::string& str;
    int num;
    IProgress* m_iprogress;
 public:
    StringSplit(std::string& s, int n, IProgress* m_ip):str(s),num(n),m_iprogress(m_ip){}
    void Splitter() {
        int a = str.size();
        if(num < 0) {
            std::cout<<"INPUT WRONG! num should be bigger than zero."<<std::endl;
            return;
        }
        if(a <= num) {
            std::cout<<str<<std::endl;
            return;
        }
        for(int i = 0; i<str.size(); i+=num) {
            int boarder = i+num > str.size() ? str.size()%num:num;
            std::cout<<str.substr(i, boarder)<<std::endl;
            float v = str.size();
            int temp = i+num > str.size() ? str.size():i+num;
            v = temp/v;           
            m_iprogress->DoProgress(v);  // notice
        }
    }
};