class Stream {
public:
    virtual void Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream(){}
};

class FileStream: public Stream {
public:
    virtual void Read(int number) {
        // 读文件流
    }
    virtual void Seek(int position) {
        // 定位文件流
    }
    virtual void Write(char data) {
        // 写文件流
    }
};

class NetStream: public Stream {
public:
    virtual void Read(int number) {
        // 读网络流
    }
    virtual void Seek(int position) {
        // 定位网络流
    }
    virtual void Write(char data) {
        // 写网络流
    }
};

class MemoryStream: public Stream {
public:
    virtual void Read(int number) {
        // 读内存流
    }
    virtual void Seek(int position) {
        // 定位内存流
    }
    virtual void Write(char data) {
        // 写内存流
    }
};

// 为了把子项里重复的stream去掉，
class DecorateStream : public Stream {
protected:
    Stream* stream;
public:
    DecorateStream(Stream* stm): stream(stm){}
};

class CryptStream : public DecorateStream {  // 继承Stream是因为要重写虚函数
// Stream* stream; // new FileStream/NetStream/MemoryStream
public:
    CryptStream(Stream* stm):DecorateStream(stm){}
    virtual void Read(int number) {
        // 加密操作
        stream->Read(number);

    }
    virtual void Seek(int position) {
        // 加密操作
        stream->Seek(position);
    }
    virtual void Write(char data) {
        // 加密操作
        stream->Write(data);
    }
};

// class CryptStream : public Stream{
//     Stream* stream;  // new NetStream
// public:
//     virtual void Read(int number) {
//         // 加密操作
//         stream->Read(number);

//     }
//     virtual void Seek(int position) {
//         // 加密操作
//         stream->Seek(position);
//     }
//     virtual void Write(char data) {
//         // 加密操作
//         stream->Write(data);
//     }
// };

// class CryptMemoryStream:public MemoryStream {
// public:
//     virtual void Read(int number) {
//         // 加密操作
//         MemoryStream::Read(number);

//     }
//     virtual void Seek(int position) {
//         // 加密操作
//         MemoryStream::Seek(position);
//     }
//     virtual void Write(char data) {
//         // 加密操作
//         MemoryStream::Write(data);
//     }
// };

class BufferStream:public DecorateStream {
// Stream* stream;
public:
    BufferStream(Stream* stm) : DecorateStream(stm){}
    virtual void Read(int number) {
        // 缓存操作
        stream->Read(number);
    }
    virtual void Seek(int position) {
        // 缓存操作
        stream->Seek(position);
    }
    virtual void Write(char data) {
        // 缓存操作
        stream->Seek(data);
    }
};

// class BufferNetStream:public FileStream {
//     // ...
// };

// class BufferMemoryStream:public FileStream {
//     // ...
// };


// CryptBufferFileStream没必要存在了，两两组合就可以有了

// class CryptBufferFileStream:public FileStream { 
// Stream* stream;
// public:
//     virtual void Read(int number) {
//         // 加密操作
//         // 缓存操作
//         stream->Read(number);
//     }
//     virtual void Seek(int position) {
//         // 加密操作
//         // 缓存操作
//         stream->Seek(position);
//     }
//     virtual void Write(char data) {
//         // 加密操作
//         // 缓存操作
//         stream->Seek(data);
//     }
// };

void Process() {
    FileStream* s1 = new FileStream();
    CryptStream* s2 = new CryptStream(s1); // CryptFileStream
    BufferStream* s3 = new BufferStream(s1); // BufferFileStream
    BufferStream* s4 = new BufferStream(s2); // BufferCryptFileStream 
    // CryptBufferFileStream* s3 = new CryptBufferFileStream();
}