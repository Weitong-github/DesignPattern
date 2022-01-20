
class House {

};

class HouseBuilder {
public:
    House* GetResult() {
        return pHouse;
    }
    House* pHouse;
  

    virtual ~HouseBuilder(){}
protected:
    virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual bool BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
private:
    // 为什么这里采取友元，因为HouseDirector要用HouseBuilder中的函数，但外边使用的时候，
    // 不需要直接使用BuildPart3的函数，所以最好设置为protected，所以需要设置为友元。
    friend class HouseDirector;
};



class StoneHouse : public House {

};
class StoneHouseBuilder : public HouseBuilder {
protected:
    virtual void BuildPart1(){}
    virtual void BuildPart2(){}
    virtual bool BuildPart3(){}
    virtual void BuildPart4(){}
    virtual void BuildPart5(){}
};

class HouseDirector {
public:
    HouseBuilder* pHouseBuilder;

    HouseDirector(HouseBuilder* pHouseBuilder):pHouseBuilder(pHouseBuilder){}

    // 为什么返回值是House，因为初始化一个房子，需要返回一个房子
    // 
    House* Init(){
        
        pHouseBuilder->BuildPart1();
        
        for (int i = 0; i < 4; i++){
            pHouseBuilder->BuildPart2();
        }
        
        bool flag= pHouseBuilder->BuildPart3();
        
        if(flag){
            pHouseBuilder->BuildPart4();
        }
        
        pHouseBuilder->BuildPart5();
        
        return pHouseBuilder->GetResult();
    }
};

// class HouseDirector {
// public:
//     House* pHouseBuilder;
//     House* Construct(){
        
//         pHouseBuilder->BuildPart1();
        
//         for (int i = 0; i < 4; i++){
//             pHouseBuilder->BuildPart2();
//         }
        
//         bool flag= pHouseBuilder->BuildPart3();
        
//         if(flag){
//             pHouseBuilder->BuildPart4();
//         }
        
//         pHouseBuilder->BuildPart5();
        
//         return pHouseBuilder->GetResult();
//     }  
// };

int main() {
    // House* pHouse = new StoneHouse();
    // pHouse->Init();

    HouseBuilder* h = new StoneHouseBuilder();
    HouseDirector* hb = new HouseDirector(h);
    House* hh = hb->Init();

    return 0;
}
