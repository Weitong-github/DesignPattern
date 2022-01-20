class SplitterFactory {
public:
    virtual ISplitter* Create() = 0; 
    virtual ~SplitterFactory(){}
};

class ISplitter {
public:
    virtual void split() = 0;
    virtual ~ISplitter(){}
};

class BinarySplitter:public ISplitter {
public:
    void split(){

    }
};
class TxtSplitter : public ISplitter {
public:
    void split(){

    }
};
class PictureSplitter : public ISplitter {
public:
    void split(){

    }
};
class VideoSplitter : public ISplitter {
public:
    void split(){

    }
};

class BinarySplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* Create() {
        return new BinarySplitter();
    }
};
class TxtSplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* Create() {
        return new TxtSplitter();
    }
};
class PictureSplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* Create() {
        return new PictureSplitter();
    }
};
class VideoSplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* Create() {
        return new VideoSplitter();
    }
};
