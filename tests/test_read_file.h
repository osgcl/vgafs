
#include "libs/cltest/cltest/assert.h"
#include "libs/cltest/cltest/macros.h"

#include "vgafs/file.h"
#include <cstring>

const char* line_expected = "# this line is used by the testing tools to validate read";

CLTEST(test_read_gitignore) {
    osgcl::vgafs::FStream* stream = osgcl::vgafs::open(".gitignore", "r");

    assert_true(stream->is_open());

    std::size_t size = strlen(line_expected);

    char buffer[size + 1];
    std::size_t res = stream->read( buffer, size );
    buffer[size] = 0;

    assert_equals(res, size);

    for (int i = 0; i < size; i ++)
        assert_equals(buffer[i], line_expected[i]);
    
    delete stream;
}
