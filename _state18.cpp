// enum NetworkState
// {
//     Network_Open,
//     Network_Close,
//     Network_Connect,
// };

// class NetworkProcessor{
    
//     NetworkState state;

// public:
    
//     void Operation1(){
//         if (state == Network_Open){

//             //**********
//             state = Network_Close;
//         }
//         else if (state == Network_Close){

//             //..........
//             state = Network_Connect;
//         }
//         else if (state == Network_Connect){

//             //$$$$$$$$$$
//             state = Network_Open;
//         }
//     }

//     public void Operation2(){

//         if (state == Network_Open){
            
//             //**********
//             state = Network_Connect;
//         }
//         else if (state == Network_Close){

//             //.....
//             state = Network_Open;
//         }
//         else if (state == Network_Connect){

//             //$$$$$$$$$$
//             state = Network_Close;
//         }
    
//     }

//     public void Operation3(){

//     }
// };

class NetworkState {
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState() {}
};

class OpenState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {
        if(m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }

    virtual void Operation1() {
        // ...
        pNext = CloseState::getInstance();
    }
    virtual void Operation2() {
        // ...
        pNext = ConnectionState::getInstance();
    }
    virtual void Operation3() {
        // ...
        pNext = OpenState::getInstance();
    }
};

class CloseState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {
        if(m_instance == nullptr) {
            m_instance = new CloseState();
        }
        return m_instance;
    }
    virtual void Operation1() {
        // ...
        pNext = CloseState::getInstance();
    }
    virtual void Operation2() {
        // ...
        pNext = ConnectionState::getInstance();
    }
    virtual void Operation3() {
        // ...
        pNext = OpenState::getInstance();
    }
};
class ConnectionState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {
        if(m_instance == nullptr) {
            m_instance = new ConnectionState();
        }
        return m_instance;
    }
    virtual void Operation1() {
        // ...
        pNext = CloseState::getInstance();
    }
    virtual void Operation2() {
        // ...
        pNext = ConnectionState::getInstance();
    }
    virtual void Operation3() {
        // ...
        pNext = OpenState::getInstance();
    }
};

class NetworkProcessor {
    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState) {
        this->pState = pState;
    }
    void Operation1() {
        pState->Operation1();
        pState = pState->pNext;
    }
    void Operation2() {
        pState->Operation2();
        pState = pState->pNext;
    }
    void Operation3() {
        pState->Operation3();
        pState = pState->pNext;
    }
};

