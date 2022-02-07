#include<string>
using namespace std;

//lj git test

class Messager {
protected:
    MessagerImp* messagerImp;
public:
    virtual void Login(string& username, string& password) = 0;
    virtual void SendMessage(string& message) = 0;
    virtual void SendPicture(int image) = 0;

    virtual ~Messager(){}
};

class MessagerImp {
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteTest() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp(){}
};

class PCMessagerImp:public MessagerImp {
public:
    virtual void PlaySound() {
        //
    }
    virtual void DrawShape() {
        //
    }
    virtual void WriteTest() {
        //
    }
    virtual void Connect() {
        //
    }
};

class MobileMessagerImp:public MessagerImp {
public:
    virtual void PlaySound() {
        //
    }
    virtual void DrawShape() {
        //
    }
    virtual void WriteTest() {
        //
    }
    virtual void Connect() {
        //
    }
};

class MessagerLite : public Messager {

    // MessagerImp* messagerImp;
public:
    virtual void Login(string username, string password) {
        messagerImp->Connect();
        //
    }
    virtual void SendMessage(string message) {
        messagerImp->WriteTest();
        //
    }
    virtual void SendPicture(int Image) {
        messagerImp->DrawShape();
        //
    }
};

class MessagerPerfect : public Messager {
    // MessagerImp* messagerImp;  // new MobileMessager
public:
    virtual void Login(string username, string password) {
        messagerImp->PlaySound();
        messagerImp->Connect();
        //
    }
    virtual void SendMessage(string message) {
        messagerImp->PlaySound();
        messagerImp->WriteTest();
        //
    }
    virtual void SendPicture(int Image) {
        messagerImp->PlaySound();
        messagerImp->DrawShape();
        //
    }
};


// class MobileMessagerLite : public MobileMessager {
// public:
//     virtual void Login(string username, string password) {
//         MobileMessager::Connect();
//         //
//     }
//     virtual void SendMessage(string message) {
//         MobileMessager::WriteTest();
//         //
//     }
//     virtual void SendPicture(int Image) {
//         MobileMessager::DrawShape();
//         //
//     }
// };

// class MobileMessagerPerfect : public MobileMessager {
// public:
//     virtual void Login(string username, string password) {
//         MobileMessager::PlaySound();
//         MobileMessager::Connect();
//         //
//     }
//     virtual void SendMessage(string message) {
//         MobileMessager::PlaySound();
//         MobileMessager::WriteTest();
//         //
//     }
//     virtual void SendPicture(int Image) {
//         MobileMessager::PlaySound();
//         MobileMessager::DrawShape();
//         //
//     }
// };

void Process() {

}
