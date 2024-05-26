
#include "libs/cltest/cltest/assert.h"
#include "libs/cltest/cltest/macros.h"

#include "vgafs/file.h"
#include <cstring>

void assert_file_read (const char* path, const char* expected) {
    std::size_t size = strlen(expected);

    osgcl::vgafs::FStream* stream = osgcl::vgafs::open(path, "r");
    assert_true(stream->is_open());

    char buffer[size + 1]; buffer[size] = 0;
    std::size_t res = stream->read(buffer, size);
    assert_equals(res, size);

    for (int i = 0; i < size; i ++) assert_equals(expected[i], buffer[i]);

    delete stream;
}
