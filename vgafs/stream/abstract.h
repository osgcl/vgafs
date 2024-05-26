
#pragma once

#include <cstddef>

namespace osgcl::vgafs::stream {

    template<typename T>
    class BasicIStream {
    public:
        virtual ~BasicIStream () {};

        virtual std::size_t read(T* buffer, std::size_t size) = 0;
    
        virtual void seekg (std::size_t pos) = 0;
        virtual std::size_t tellg () = 0;
    };

    template<typename T>
    class BasicOStream {
    public:
        virtual ~BasicOStream () {};

        virtual std::size_t write (T* buffer, std::size_t size) = 0;
        
        virtual void seekp (std::size_t pos) = 0;
        virtual std::size_t tellp () = 0;
    };

    template<typename T>
    class BasicIOStream : public BasicIStream<T>, public BasicOStream<T> {
    public:
        virtual ~BasicIOStream () override {};
    };

    using IStream  = BasicIStream<char>;
    using OStream  = BasicOStream<char>;
    using IOStream = BasicIOStream<char>;

}
