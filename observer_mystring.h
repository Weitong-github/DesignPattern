#include"oberver_stringSplitter.h"

class MyString : public IProgress{
 private:
    std::string s;
    int num;
 public:
    void split(std::string& s, int n) {
        StringSplit ss(s, n, this);
        ss.Splitter();
    }

    virtual void DoProgress(float val) {
        std::cout<<"The progress is prochaing at "<<val <<std::endl;
    }
};