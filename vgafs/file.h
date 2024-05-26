#pragma once
#include "vgafs/stream/abstract.h"
#include "fstream"

namespace osgcl::vgafs {

    class FStream : public stream::IOStream {
    public:
        virtual ~FStream () override {};

        virtual bool is_open () = 0;
    };
    
    class BasicFStream : public FStream {
    private:
        std::ifstream reader;
        std::ofstream writer;

        bool status;
        bool can_read;
        bool can_write;
    public:
        BasicFStream (const char* path, const char* mode);
        ~BasicFStream () override;

        bool is_open () override;

        std::size_t read(char* buffer, std::size_t size) override;
    
        void seekg (std::size_t pos) override;
        std::size_t tellg () override;

        std::size_t write(char* buffer, std::size_t size) override;
    
        void seekp (std::size_t pos) override;
        std::size_t tellp () override;
    };

    FStream* open (const char* path, const char* mode);

}
