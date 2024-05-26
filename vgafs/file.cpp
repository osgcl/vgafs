
#include "vgafs/file.h"
#include <iostream>

using namespace osgcl::vgafs;

BasicFStream::BasicFStream (const char* path, const char* mode) {
    std::string __mode = mode;

    can_read  = __mode[0] == 'r';
    can_write = __mode.back() == 'w';

    status = true;
    if (can_read) {
        std::cout << "READER " << ((bool) reader) << "\n";
        reader = std::ifstream(path);
        std::cout << "READER " << ((bool) reader) << "\n";
        status &= (bool) reader;
    }
    if (can_write) {
        std::cout << "WRITER\n";
        writer.open(path);
        status &= (bool) writer;
    }
    std::cout << "STREAM " << status << "\n";
}
BasicFStream::~BasicFStream () {
    if (reader) reader.close();
    if (writer) writer.close();
    status = false;
}
bool BasicFStream::is_open () {
    std::cout << "GET STATUS\n";
    return status;
}

std::size_t BasicFStream::tellg () {
    return reader.tellg();
}
void BasicFStream::seekg (std::size_t size) {
    reader.seekg(size);
}
std::size_t BasicFStream::read (char* buffer, std::size_t sze) {
    reader.read(buffer, sze);

    return reader.gcount();
}

std::size_t BasicFStream::tellp () {
    return writer.tellp();
}
void BasicFStream::seekp (std::size_t size) {
    writer.seekp(size);
}
std::size_t BasicFStream::write (char* buffer, std::size_t sze) {
    std::size_t start = tellp();
    writer.write(buffer, sze);

    return tellp() - start;
}

FStream* osgcl::vgafs::open (const char* path, const char* mode) {
    return new BasicFStream (path, mode);
}
